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
    void rotate(vector<int>& nums, int k) {
        k %= nums.size(); // 减少重复
        if (k == 0) return; // 避免出现特殊情况 l > r
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }

    void reverse(vector<int>& nums, int l, int r){
        for (int i = l; i <= l + (r-l)/2; i++){
            swap(nums[i], nums[r-(i-l)]);
        }
    }
};

int main() {

    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution res;
    res.rotate(nums, k);
    
    return 0;
}
