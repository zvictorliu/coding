#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution1 { //û���ǵ�����
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        int p = 0, q = 1;
        int sum_pq = nums[0];
        int cnt = 0;
        
        // if (sum_pq == k) cnt++;
        while (p < q){
            while (sum_pq < k && q < N){
                sum_pq += nums[q++];
            }
            if (sum_pq == k) {
                cnt ++;
            }
            sum_pq -= nums[p++];
        }
        
        return cnt;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // ǰ׺�����򣬲��ң�ͬʱ�����Ǳȵ�ǰ�±�С��
        // �ù�ϣ�����Ҹ�����
        // ����ֻ������ǰ���ң����ԾͲ���Ҫǰ׺����
        unordered_map<int, int> umap;
        umap[0] = 1; // �ѵ���k������
        int frontSum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            frontSum += nums[i];
            if (umap.find(frontSum - k) != umap.end()) cnt += umap[frontSum - k];
            umap[frontSum]++;
        }
        return cnt;
    }
};

int main() {

    vector<int> nums = {1,-1,0};
    int k = 0;
    Solution res;
    cout << res.subarraySum(nums, k) << endl;
    
    return 0;
}
