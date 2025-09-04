#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
    printf("queue\n");
    queue<int> que1;
    que1.push(1);
    que1.push(2);
    printf("front: %d\nback: %d\n", que1.front(), que1.back());


    //双端队列允许在两端进行插入和删除操作，是栈和队列的结合体。
    printf("\ndeque\n");
    deque<int> deque1(4, 3);
    deque1.push_back(1);
    deque1.push_front(4);
    printf("%d\n", deque1.at(3));
    //双端队列支持迭代器
    for(auto i = deque1.begin(); i != deque1.end(); i++){
        printf("%d ", *i);
    }
}