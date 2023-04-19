#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //����unordered_map�ṩ�Ĺ�ϣ������Ҫ������ô��
        //�Լ�д��ϣ��ͻ���Ϊ���鲻��������������
        // for (auto [num, occ]: freq) ����������python��д��Ҫѧ��
        unordered_map<int,int> freq_cnt; //�������Ϊ�յ�
        int N = nums.size();
        for (int i = 0; i < N; i++){
            ++freq_cnt[nums[i]]; //��������һ�¾��൱����ӽ�ȥ�ˣ����ҳ�ʼ��Ϊ0
        }
        for (auto [n, f]: freq_cnt){ //�о��棬��������
            if (f == 1) return n;
        }

        return 0;
    }
};

// ����һ��λ�����������ѭ��31�Σ�ÿһλ����0����1�����ڳ������Σ���ÿһλ֮�����������𰸵���һλ��0�����Ϊ3�ı�����
// ����𰸵���һλ��1�����%3Ϊ1
// ֻ��Ҫע�����һλ�޸ĵļ��ɣ��ɿ��ٷ����

int main(){
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution res;
    cout << res.singleNumber(nums) << endl;

    return 0;
}