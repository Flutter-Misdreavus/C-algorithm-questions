#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[110][110];
int book[110][110];

struct QUE
{
    int x;
    int y;
    int nao;
    int step;
};
typedef struct QUE QUE;
QUE que[1000];

int dfs(int x, int y, int n){
    int next[4][2] = {{1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int head = 0, tail = 1;
    memset(que, 0, sizeof(que));

    que[0].x = x;
    que[0].y = y;
    que[0].nao = 2;
    que[0].step = 0;
    book[x][y] = 1;

    int a, b;
    while(head <= tail){
        //printf("%d %d\n", que[head].x, que[head].y);
        if(que[head].nao == 3){
            return que[head].step;
        }

        for(int dex = 0; dex < 4; dex++){
            a = que[head].x + next[dex][0];
            b = que[head].y + next[dex][1];
            if(0 <= a && a < n && 0 <= b && b < n && map[a][b] != que[head].nao && book[a][b] == 0){
                que[tail].x = a;
                que[tail].y = b;
                que[tail].nao = map[a][b];
                que[tail].step = que[head].step + 1;
                book[a][b] = 1;
                tail++;
            }
        }

        head++;
    }

    return 0;
}

int main(){
    int n;
    char ch;
    int x, y;
    memset(map, 0, sizeof(map));

    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%c", &ch);

            if(ch == '+'){
                map[i][j] = 1;
            }else if(ch == '-'){
                map[i][j] = 0;
            }else if(ch == 'A'){
                map[i][j] = 2;
                x = i;
                y = j;
            }else{
                map[i][j] = 3;
            }
            //printf("%d", map[i][j]);
            getchar();
        }
        
    }

    int step = dfs(x, y, n);
    printf("%d\n", step);
}