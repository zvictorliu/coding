#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <map>
#include <set>
using namespace std;

class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) { // 我擦，居然也过了？ 但是这个不是常数级别的空间
        // 没有1就是1，有1就是在之间找（如果不连续）或者只能在之外找
        // 看1-MAX的占用情况
        set<int> nset;
        for (int num : nums){
            nset.emplace(num);
        }

        int target = 1;
        for (set<int>::iterator it = nset.find(1); it != nset.end(); it ++){
            if ((*it) > target) {
                 return target;
            }
            else {
                target = (*it) +1;
            }
        }

        return target;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 原地哈希，能够实现哈希同时还是找回原来的值
        // 只能是在[1,N+1]之间，而不是MAX+1，因为最坏也就是1-N连续，此时是N+1
        // 将数组中的<=0转换为N+1，这样数值都是正数了
        // 数x对它标记，将下标x-1的值改为负数以作为标记，这样还可以用abs找回nums[x-1]，如果它原来不是负数的话
        // 标记后，值为负数的下标+1代表此数在1-N+1范围内，而最小的那个正数下标就是了

        // 正数化
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= 0) nums[i] = nums.size()+1;
        }

        // 原地哈希标记
        for (int i = 0; i < nums.size(); i++){
            if (abs(nums[i]) <= nums.size()) nums[abs(nums[i])-1] = - abs(nums[abs(nums[i])-1]);
        }

        for (int i = 0; i <nums.size(); i++){
            if (nums[i] > 0) return i+1; 
        }
        return nums.size()+1;
    }
};

int main() {

    // vector<int> nums = {7,7,9,11,12};

    // Solution res;
    // cout << res.firstMissingPositive(nums) << endl;
    
    return 0;
}
