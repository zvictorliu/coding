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
    vector<int> productExceptSelf(vector<int>& nums) {
        // 这个题只能说技巧性有一点点强
        // answer理解为左边和右边的乘积再相乘，而每一侧都是连续的，所以可以通过两次遍历求出
        // 矩形排列比较容易理解
        vector<int> answer(nums.size());
        answer[0] = 1; 
        for (int i = 1; i < nums.size(); i++){ // 左侧乘积
            answer[i] = answer[i-1]*nums[i-1];
        }

        int right = 1;
        for (int j = nums.size()-2; j >= 0; j--){ // 乘上右侧乘积
            right *= nums[j+1];
            answer[j] *= right;
        }

        return answer;
    }
};

int main() {

    vector<int> nums = {1,2,3,4};

    Solution res;
    res.productExceptSelf(nums);
    
    return 0;
}
