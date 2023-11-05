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
    和一般的BST不同的是这里是排好序的、已经知道长度的
    或许就不需要和普通的那样构建、旋转
    中点为root，分左右两部分
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = nums.size();
        // TreeNode* root = new TreeNode (nums[sz/2]);
        // root->left = sortedArrayToBST(nums, 0, sz/2 -1);
        // root->right = sortedArrayToBST(nums, sz/2 +1, sz -1);
        // return root;
        return sortedArrayToBST(nums, 0, sz-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r){
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode (nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid - 1);
        root->right = sortedArrayToBST(nums, mid+1, r);
        return root;
    }
};

int main() {

    Solution res;
    
    return 0;
}
