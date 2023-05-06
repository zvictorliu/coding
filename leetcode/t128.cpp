#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class UnionFind{
private:
    unordered_map<int,int> fa;
    unordered_map<int,int> sz; // Ӧ����size��һ�� ���ҿ���Ϊ���������Ի����ù�ϣ
    int maxSz;
public:
    UnionFind(vector<int>& nums){ // ���캯����дvoid
        // todo ��ʼ����ÿ���ڵ�ĸ��׶����Լ�(�����п������ظ���)
        int N = nums.size();
        for (int i = 0; i < N; i++){
            fa[nums[i]] = nums[i];
            sz[nums[i]] = 1;
        }
        maxSz = 1;
    }

    int search(int x){
        // ·��ѹ���ƺ��п��ܻ��ƻ�sz��׼ȷ�ԣ�
        // �ͻ��Ǵ�ͳ�İ�
        int root = x;
        if (root != fa[x]){
            root = search(fa[x]);
        }
        return root;
    }

    void merge(int x, int y){
        int px = search(x);
        int py = search(y);
        if (px != py){
            // ���� x y��Сmerge �����ſɱ�֤sz׼ȷ
            if (x > y){
                fa[x] = py;
                sz[py] += sz[x];
                maxSz = max(maxSz, sz[py]);
            }
            // if (sz[x] > sz[y]){
            //     fa[y] = px;
            //     sz[x] += sz[y];
            //     maxSz = max(maxSz, sz[x]);
            // }
        }

    }

    bool isInUnion(int x){
        if (fa.find(x) == fa.end()) return false;
        return true;
    }

    int maxsz(){
        return maxSz;
    }

};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ��ʾ���鼯��������һ��
        // ��x��x-1���й鲢�����x-1���ڵĻ������Ҫ�ù�ϣ��
        if (nums.size() == 0) return 0;
        UnionFind uf(nums);

        for (int num : nums){
            if (uf.isInUnion(num-1)) uf.merge(num, num-1);
        }
        return uf.maxsz(); 
    }
};



int main() {

    Solution res;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << res.longestConsecutive(nums) << endl;
    
    return 0;
}
