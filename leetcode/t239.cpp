#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <deque>
using namespace std;

class Solution1 { // ��ʱ
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // ��������+��ͨ����
        queue<int> q1,q2;
        vector<int> maxVal;
        if (k == 1) return nums;
        q1.push(nums[0]);
        for (int i = 1; i < k; i++){
            if (nums[i] >= q1.back()) q1.push(nums[i]);
            else q2.push(nums[i]);
        }
        maxVal.push_back(q1.back());
        for (int i = k; i < nums.size(); i++){
            // ɾ����һ��
            if (q2.empty() || q1.front() == nums[i-k] || q2.front() != nums[i-k]){
                q1.pop();
            }
            else {
                q2.pop();
            }

            if (q1.empty()) {
                int sz = q2.size();
                q1.push(q2.front());
                q2.pop();
                while (--sz){
                    int f = q2.front();
                    q2.pop();
                    if (f >= q1.back()) q1.push(f);
                    else q2.push(f);
                }
            }

            // �����µ� q1������Ϊ��
            if (nums[i] >= q1.back()) {
                q1.push(nums[i]);
            }
            else {
                q2.push(nums[i]);
            }

            maxVal.push_back(q1.back());
        }

        return maxVal;
    }
};

class Solution { // ���ȶ��У�ֻ�迼�����ֵ�ڲ��ڴ����м��ɣ��������б��Ƴ���Ԫ��Ҳ����ν
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // �������У�Ҳ����ˣ�ֻ�������ֵ�ķ�����һ��
        if (k == 1) return nums;
        vector<int> maxVal;
        deque<int> dq; // �����ֳɵ����ݽṹ������
        for (int i = 0; i < k; i++){
            while (!dq.empty() && nums[dq.back()] <= nums[i]){ //����Ҫȡ���ڣ����������ֵ��ʼ�ĵݼ�����
                dq.pop_back();
            }
            dq.push_back(i);
        }

        maxVal.push_back(nums[dq.front()]);
        for (int j = k; j < nums.size(); j++){
            while (!dq.empty() && nums[dq.back()] <= nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);

            while (j - dq.front() >= k) {
                dq.pop_front();
            }

            maxVal.push_back(nums[dq.front()]);
        }

        return maxVal;
    }
};

int main() {

    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    Solution res;
    res.maxSlidingWindow(nums, k);
    
    return 0;
}
