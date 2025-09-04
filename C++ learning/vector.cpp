#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    vector<int> vector1; //创建一个存储整数的空vector
    vector<int> vector2(5); //创建一个包含5个整数的vector,每个为默认值0
    vector<int> vector3(5, 10); //创建一个包含5个数值为10的vector

    vector<int> vector4 = {1, 2, 3, 4}; //长度为4，包含1，2，3，4
    for(int i = 0; i<4; i++){
        printf("%d ",vector4[i]);
    }

    vector4.push_back(7); //在末尾添加元素
    vector4.pop_back(); //删除末尾元素
    printf("\n%d\n", vector4[4]);

    printf("vector4.size(): %d\n", vector4.size()); //获取元素数量

    vector4.erase(vector4.begin() + 2); //删除第三个元素,erase(迭代器，用起来像指针)
    vector4.insert(vector4.begin() + 1, 56); //在任意位置插入
    for(auto i = vector4.begin(); i != vector4.end(); i++){
        printf("%d ", *i);
    }

    vector4.clear(); //清空
}