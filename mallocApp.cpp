#include<stdio.h>   // 标准输入输出头文件
#include<stdlib.h>  // 动态内存管理头文件
#define InitSize 10 // 默认初始数组大小

// 定义顺序表结构体
typedef struct {
    int * data;      // 指向动态分配数组的指针
    int MaxSize;    // 当前数组的最大容量
    int length;     // 当前数组的实际长度
} SeqList;

/**
 * @brief 初始化顺序表
 * @param L 顺序表引用
 * 功能：为顺序表分配初始内存空间并初始化成员变量
 */
void InitList(SeqList &L) {
    L.data = (int *)malloc(InitSize* sizeof(int)); // 分配初始内存
    L.length = 0;           // 初始化长度为0
    L.MaxSize = InitSize;   // 设置最大容量为初始大小
}

/**
 * @brief 扩展顺序表容量
 * @param L 顺序表引用
 * @param len 需要增加的容量长度
 * 功能：重新分配更大的内存空间，复制原有数据，并释放旧内存
 */
void IncreaseSize(SeqList &L,int len) {
    int *p = L.data;    // 保存旧数组指针
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int)); // 分配新内存

    // 复制旧数据到新数组
    for(int i = 0;i<L.length;i++) {
        L.data[i]=p[i];
    }

    L.MaxSize = L.MaxSize+len; // 更新最大容量
    free(p);                   // 释放旧内存
}

/**
 * @brief 主函数
 * 功能：演示顺序表的初始化和扩容操作
 */
// int main() {
//     SeqList L;          // 声明顺序表变量
//     InitList(L);        // 初始化顺序表
//     IncreaseSize(L,5);  // 扩容5个单位
//     return 0;
// }