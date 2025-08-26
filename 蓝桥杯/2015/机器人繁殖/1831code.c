#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int quick_pow(long long int base, long long  int n){
    long long int result = 1;

    while(n > 0){
        if(n & 1){
            // 如果n是奇数
            result *= base;
        }
        base *= base;
        n >>= 1; // 右移一位，相当于除以2
    }

    return result;
}

int main(){
    int n;
    double s;
    int a0;

    scanf("%d%lf", &n, &s);
    a0 = (s-n-1)/(pow(2, n+1) -1) +1;

    printf("%d\n", a0);
}