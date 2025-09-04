#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums;

    for(int i = 0; i<100; i++){
        nums.push_back(pow(i - 19, 4) - 3 * i + 3);
    }

    for(auto i = nums.begin(); i != nums.end(); i++){
        printf("%d ", *i);
    }
    printf("\n\n");

    // lambda [](){}
    sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
    for(auto i = nums.begin(); i != nums.end(); i++){
        printf("%d ", *i);
    }
    printf("\n");
}