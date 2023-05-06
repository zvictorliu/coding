#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 要求是必须在不复制数组的情况下原地对数组进行操作
        // 用栈的话就很好解决了，可是如果是原地修改，冒泡？估计会超时
        // 双指针或许可以
        vector<int>::iterator p, q;
        p = nums.begin();
        while (1){
            while (p < nums.end() && *p != 0) p++;
            if (p == nums.end()) break;
            q = p;
            while (q < nums.end() && *q == 0) q++;
            if (q == nums.end()) break;
            swap(*p, *q);
        }
    }
};

int main() {

    Solution res;
    vector<int> nums = {0,1,0,3,12};
    res.moveZeroes(nums);
    
    return 0;
}
