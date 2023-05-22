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
    int maxSubArray(vector<int>& nums) {
        // ǰ׺�ͣ��������Сֵ������ջ��
        int pre = nums[0], maxSum = nums[0]; 
        int minL = min(0, pre); // �п���������
        // ��ʾ����
        for (int i = 1; i < nums.size(); i++){
            pre += nums[i];
            maxSum = max(maxSum, pre - minL);
            minL = min(minL, pre);
        }

        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2,1};
    Solution res;
    cout << res.maxSubArray(nums) << endl;
    
    return 0;
}
