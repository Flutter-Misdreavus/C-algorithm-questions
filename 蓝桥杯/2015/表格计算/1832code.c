#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char table[100][100][20];
double num_table[100][100];

int what_fuc(int x, int y){
    //判断当前格式属于什么类型
    if (table[x][y][0] == 'E'){
        return -1; //已处理
    }
    else if(isdigit(table[x][y][0])){
        return 0; //数字
    }else if(table[x][y][0] == 'A'){
        return 1; //平均数
    }else if(table[x][y][1] == 'U'){
        return 2; //求和
    }else if(table[x][y][1] == 'T'){
        return 3; //标准差
    }
}
void in_num_tabel(int x, int y){
    //转换数字
    for(int i = 0; table[x][y][i] != '\0'; i++){
        num_table[x][y] *= 10;
        num_table[x][y] += table[x][y][i] - '0';
    }
    
}
void chaijie(int x, int y, int* x1, int* y1, int* x2, int* y2){
    //将算式中的坐标拆解出来
    *x1 = 0;
    *y1 = 0;
    *x2 = 0;
    *y2 = 0;

    int i = 4;
    while (table[x][y][i] != ',')
    {
        *x1 *= 10;
        *x1 += table[x][y][i] - '0';
        i++;
    }
    i++;
        while (table[x][y][i] != ':')
    {
        *y1 *= 10;
        *y1 += table[x][y][i] - '0';
        i++;
    }
    i++;
        while (table[x][y][i] != ',')
    {
        *x2 *= 10;
        *x2 += table[x][y][i] - '0';
        i++;
    }
    i++;
        while (table[x][y][i] != ')')
    {
        *y2 *= 10;
        *y2 += table[x][y][i] - '0';
        i++;
    }
    
}

double AVG(int x1, int y1, int x2, int y2);
double SUM(int x1, int y1, int x2, int y2);
double STD(int x1, int y1, int x2, int y2);

double execute(int x, int y);

int main(){
    int n, m;
    memset(num_table, 0, sizeof(num_table));

    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            scanf("%s", table[i][j]);
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            execute(i, j);
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            printf("%.2lf ", num_table[i][j]);
        }
        printf("\n");
    }

}

double AVG(int x1, int y1, int x2, int y2){
    double he = SUM(x1, y1, x2, y2);
    return he / ((x2 - x1 + 1) * (y2 - y1 + 1));
}

double SUM(int x1, int y1, int x2, int y2){
    double he = 0;
    for(int i = x1; i<=x2; i++){
        for(int j = y1; j<=y2; j++){
            he += execute(i, j);
        }
    }
    return he;
}

double STD(int x1, int y1, int x2, int y2){
    double avg = AVG(x1, y1, x2, y2);
    double result = 0;
        for(int i = x1; i<=x2; i++){
        for(int j = y1; j<=y2; j++){
            result += pow((execute(i, j) - avg), 2);
        }
    }
    result /= ((x2 - x1 + 1) * (y2 - y1 + 1));
    result = pow(result, 0.5);

    return result;
}

double execute(int x, int y){
    int x1, y1, x2, y2;
    switch (what_fuc(x, y))
    {
    case -1:
        return num_table[x][y];
        break;

    case 0:
        in_num_tabel(x, y);
        table[x][y][0] = 'E';
        return num_table[x][y];
        break;

    case 1:
        chaijie(x, y, &x1, &y1, &x2, &y2);
        num_table[x][y] = AVG(x1, y1, x2, y2);
        table[x][y][0] = 'E';
        return num_table[x][y];
        break;

    case 2:
        chaijie(x, y, &x1, &y1, &x2, &y2);
        num_table[x][y] = SUM(x1, y1, x2, y2);
        table[x][y][0] = 'E';
        return num_table[x][y];
        break;

    case 3:
        chaijie(x, y, &x1, &y1, &x2, &y2);
        num_table[x][y] = STD(x1, y1, x2, y2);
        table[x][y][0] = 'E';
        return num_table[x][y];
        break;
    
    default:
        break;
    }
}