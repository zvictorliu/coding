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
        // �����ֻ��˵��������һ���ǿ
        // answer���Ϊ��ߺ��ұߵĳ˻�����ˣ���ÿһ�඼�������ģ����Կ���ͨ�����α������
        // �������бȽ��������
        vector<int> answer(nums.size());
        answer[0] = 1; 
        for (int i = 1; i < nums.size(); i++){ // ���˻�
            answer[i] = answer[i-1]*nums[i-1];
        }

        int right = 1;
        for (int j = nums.size()-2; j >= 0; j--){ // �����Ҳ�˻�
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
