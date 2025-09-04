#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long int nums[100010];
int extent[100010];

void onXOR(long int n, long int x){
    // 扫描一遍nums,将可以异或数字对纪录
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            if((nums[i] ^ nums[j]) == x){
                extent[i] = j; //将最小的纪录下来
                continue;
            }
        }
    }
    return;
}
void existXOR(int l, int r){
    for(int i = l; i<=r; i++){
        if(extent[i] <= r){
            printf("yes\n");
            return;
        } 
    }
    printf("no\n");
    return;
}

int main(){
    int n, m;
    long int x;
    int l, r;

    scanf("%d%d%ld", &n, &m, &x);
    for(int i = 1; i<=n; i++){
        scanf("%ld", &nums[i]);
    }

    for(int i = 1; i<=n; i++){
        extent[i] = 2147483647;
    }
    onXOR(n, x);

    for(int i = 0; i<m; i++){
        scanf("%d%d", &l, &r);
        existXOR(l, r);
    }
}