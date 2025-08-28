#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int map[300][300];
//0代表A，1代表B

int lei = 0;
int max = 0;

void show(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void dfs(int a_num, int b_num, int i, int j){
    //i代表第i行，j代表第j个
    //j <= i

    if((j + 1) * (j) == max){
        return;
    }

    if(a_num == 0 && b_num == 0){
        //show(i);
        lei++;
        return;
    }

    if(i == 0){
        if(a_num != 0){
            map[i][j] = 0;//A
            dfs(a_num - 1, b_num, i + 1, j);  
        }
        
        if(b_num != 0){
            map[i][j] = 1;//B
            dfs(a_num, b_num - 1, i + 1, j);  
        }
    }else if(j == 0){
        if(a_num != 0){
            map[i][j] = 0;//A
            dfs(a_num - 1, b_num, i, j + 1);  
        }
        
        if(b_num != 0){
            map[i][j] = 1;//B
            dfs(a_num, b_num - 1, i, j + 1);  
        }
    }else if(i == j){
        //最后一行
        if(a_num != 0){
            if(map[i - 1][j - 1] == 0 && map[i][j - 1] == 0){
                map[i][j] = 0;//A
                dfs(a_num - 1, b_num, i + 1, 0); 
            }
            
            if(map[i - 1][j - 1] == 1 && map[i][j - 1] == 1){
                map[i][j] = 0;//A
                dfs(a_num - 1, b_num, i + 1, 0);
            }
        }

        if(b_num != 0){
            if(map[i - 1][j - 1] == 0 && map[i][j - 1] == 1){
                map[i][j] = 1;//B
                dfs(a_num, b_num - 1, i + 1, 0);
            }

            if(map[i - 1][j - 1] == 1 && map[i][j - 1] == 0){
                map[i][j] = 1;//B
                dfs(a_num, b_num - 1, i + 1, 0);
            }
        }
    }else{
        if(a_num != 0){
            if(map[i - 1][j - 1] == 0 && map[i][j - 1] == 0){
                map[i][j] = 0;//A
                dfs(a_num - 1, b_num, i, j + 1);
            }

            if(map[i - 1][j - 1] == 1 && map[i][j - 1] == 1){
                map[i][j] = 0;//A
                dfs(a_num - 1, b_num, i, j + 1);
            }
        }

        if(b_num != 0){
            if(map[i - 1][j - 1] == 0 && map[i][j - 1] == 1){
                map[i][j] = 1;//B
                dfs(a_num, b_num - 1, i, j + 1);
            }

            if(map[i - 1][j - 1] == 1 && map[i][j - 1] == 0){
                map[i][j] = 1;//B
                dfs(a_num, b_num - 1, i, j + 1);
            }
        }
    }

    return;
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);

    memset(map, 0, sizeof(map));

    max = m + n;
    max *= 2;
    lei = 0;

    dfs(m, n, 0, 0);
    printf("%d\n", lei);
}