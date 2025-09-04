#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nums[200010];

int main(){
    long long int sum = 0;
    int n;
    long long int result = 0;

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &nums[i]);
        sum += nums[i];
    }

    for(int i = 0; i<n; i++){
        result += nums[i] * (sum - nums[i]);
    }
    result = result >> 1;

    printf("%lld\n", result);
}