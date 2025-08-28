#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char str1[2010];
char str2[2010];

void bianhuan(){
    int i = 1;
    int j = 0;
    int count = 1;
    char ch = str1[0];

    while(str1[i] != '\0'){
        if(ch != str1[i]){ //如果当前字符不等于上一个字符
            str2[j] = count + '0';
            j++;
            str2[j] = ch;
            j++;
            count = 1;
            ch = str1[i];
        }else{
            count++;
        }
        i++;
    }
    //处理最后的
    str2[j] = count + '0';
    j++;
    str2[j] = ch;
    j++;
    str2[j] = '\0';

    memcpy(str1, str2, sizeof(str2));

}

int main(){
    int n;
    
    scanf("%s", str1);
    scanf("%d", &n);


    for(int i = 0; i<n; i++){
        bianhuan();
    }

    printf("%s\n", str1);

}