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
        // Ҫ���Ǳ����ڲ���������������ԭ�ض�������в���
        // ��ջ�Ļ��ͺܺý���ˣ����������ԭ���޸ģ�ð�ݣ����ƻᳬʱ
        // ˫ָ��������
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
