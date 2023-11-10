#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    前序遍历可以计算出每个节点的累计值
    但是依然不能解决 （暴力点，每个节点都前序遍历
    前缀和解决重复计算
    又用到了哈希表
*/
class Solution {
    unordered_map<long,int> umap; // 前缀和-次数
    int target;
public:
    int pathSum(TreeNode* root, int targetSum) {
        umap[0] = 1;
        target = targetSum;
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, long curr){
        int cnt = 0;
        if (root == nullptr)
            return 0;
        curr += root->val;
        // 检测前面是否有合适的节点
        if (umap.count(curr - target)){ //说明存在
            cnt += umap[curr-target];
        }
        umap[curr] ++; //! 应该放在后面，不能把自己也算进去了
        cnt += dfs(root->left, curr);
        cnt += dfs(root->right, curr);
        //! 退回来应该不计入了,否则会引起重复
        umap[curr] --;

        return cnt;
    }
};

int main() {

    Solution res;
    
    return 0;
}
