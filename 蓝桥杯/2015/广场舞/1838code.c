#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double point_x[100];
double point_y[100];

double PNPoly(double x, double y, double n){
    int is_inside = 0; //0代表在外面，1代表在里面
    double xi, yi;
    double xj, yj;

    for(int i = 0, j = n - 1; i < n; j = i, i++){
        //从第1个(i)和最后一个(j)开始,遍历所有顶点形成的边
        //(0, n-1) -> (1, 0) -> (2, 1) -> ...
        xi = point_x[i];
        yi = point_y[i];
        xj = point_x[j];
        yj = point_y[j];

        if (((yi > y) != (yj > y)) &&
            (x <= (xj - xi) * (y - yi) / (yj - yi) + xi)) // 不能直接同乘(yj - yi)，因为不知道其是否大于0
            is_inside = !is_inside;

    }

    return is_inside;
}

int is_fang(double x, double y, double n){
    if(PNPoly(x, y, n) && PNPoly(x + 1, y, n) && PNPoly(x, y + 1, n) && PNPoly(x + 1, y + 1, n)){
        return 1;
    }else{
        return 0;
    }
}

double min_in(double* nums, double n){
    double alo = nums[0];

    for(int i = 1; i<n ;i++){
        if(nums[i] < alo){
            alo = nums[i];
        }
    }

    return alo;
}

double max_in(double* nums, double n){
    double alo = nums[0];

    for(int i = 1; i<n ;i++){
        if(nums[i] > alo){
            alo = nums[i];
        }
    }

    return alo;
}

int main(){
    int n;
    double minx, miny;
    double maxx, maxy;

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%lf%lf", &point_x[i], &point_y[i]);
    }

    minx = min_in(point_x, n);
    miny = min_in(point_y, n);
    maxx = max_in(point_x, n);
    maxy = max_in(point_y, n);

    int count = 0;
    for(int i = minx; i<maxx; i++){
        for(int j = miny; j<maxy; j++){
            if(is_fang(i, j, n)){
                count++;
            }
        }
    }
    printf("%d\n", count);
}