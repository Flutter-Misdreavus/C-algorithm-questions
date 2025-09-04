#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
    stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    printf("%d\n", stack1.top());
    printf("size: %d\n", stack1.size());
    stack1.pop();
}
