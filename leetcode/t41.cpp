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
    int firstMissingPositive(vector<int>& nums) { // �Ҳ�����ȻҲ���ˣ� ����������ǳ�������Ŀռ�
        // û��1����1����1������֮���ң����������������ֻ����֮����
        // ��1-MAX��ռ�����
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
        // ԭ�ع�ϣ���ܹ�ʵ�ֹ�ϣͬʱ�����һ�ԭ����ֵ
        // ֻ������[1,N+1]֮�䣬������MAX+1����Ϊ�Ҳ����1-N��������ʱ��N+1
        // �������е�<=0ת��ΪN+1��������ֵ����������
        // ��x������ǣ����±�x-1��ֵ��Ϊ��������Ϊ��ǣ�������������abs�һ�nums[x-1]�������ԭ�����Ǹ����Ļ�
        // ��Ǻ�ֵΪ�������±�+1���������1-N+1��Χ�ڣ�����С���Ǹ������±������

        // ������
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= 0) nums[i] = nums.size()+1;
        }

        // ԭ�ع�ϣ���
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
