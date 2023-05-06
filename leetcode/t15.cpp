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
        // ��Ȼ�Ƚ���˫ָ�룬ֻ��������������֮��
        // ���ȥ��: һ���Ǳ����ظ�target��Ȼ����Ҫ˫ָ�������Ҫ������ͬ��
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
                    if (*p + *q == target) { // ! ˳�����Ҫ
                        result.push_back({nums[i], *p, *q}); // !���󻹿�����
                        // ǰ��������*pһ��
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
