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
    unordered_map<int,int> sz; // 应该用size好一点 而且可能为负数，所以还得用哈希
    int maxSz;
public:
    UnionFind(vector<int>& nums){ // 构造函数不写void
        // todo 初始化，每个节点的父亲都是自己(但是有可能有重复的)
        int N = nums.size();
        for (int i = 0; i < N; i++){
            fa[nums[i]] = nums[i];
            sz[nums[i]] = 1;
        }
        maxSz = 1;
    }

    int search(int x){
        // 路径压缩似乎有可能会破坏sz的准确性？
        // 就还是传统的吧
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
            // 根据 x y大小merge 这样才可保证sz准确
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
        // 提示并查集，连续是一家
        // 把x和x-1进行归并，如果x-1存在的话，大概要用哈希表？
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
