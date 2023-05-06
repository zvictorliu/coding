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
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 仍然比较像双指针，只不过现在是三个之和
        // 如何去重: 一个是避免重复target，然后是要双指针找完后要跳过相同的
        vector<vector<int>> result;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int pre = 100001;
        for (int i = 0; i < N; i++){
            int target = 0 - nums[i];
            if (target != pre && i+1 < N){
                int *p = &nums[i+1];
                int *q = &nums[N-1];
                while (p < q){
                    if (*p + *q == target) { // ! 顺序很重要
                        result.push_back({nums[i], *p, *q}); // !往后还可能有
                        // 前进到不和*p一样
                        int tmp = *p;
                        while (*p == tmp && p < q) p++;
                        tmp = *q;
                        while (*q == tmp && p < q) q--;
                    }
                    else if (*p + *q < target) p++;
                    else if (*p + *q > target) q--;  
                }
                pre = target;
            }
        }
        return result;
    }
};

int main() {

    Solution res;
    vector<int> nums = {0,0,0};
    res.threeSum(nums);
    
    return 0;
}
