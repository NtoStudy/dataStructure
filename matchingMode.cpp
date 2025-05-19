#include<stdio.h>
#include<iostream>
using namespace std;
int M = 50;
int N = 4;
int lena,lenb;
int matchingMode(char a[],char b[]) {
    int i=1,j=1;
    while(i<lena && j<lenb) {
        if(a[i] == b[j]) {
            i++;
            j++;
        }else {
            i = i-j+2;
            j = 1;
        }
    }
    if(j>lenb) {
        return i-lenb;
    }else {
        return 0;
    }
}
