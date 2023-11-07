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
    法一：检查是否在区间内
    法二：检查遍历序列是否有序
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) { //非递归中序遍历
        stack<TreeNode*> stk;
        long long pre = INT64_MIN;

        while (root != nullptr || !stk.empty()){
            while (root != nullptr){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();

            if (root->val <= pre)
                return false;
            pre = root->val;
            root = root->right;
        }

        return true;
    }
};

int main() {

    Solution res;
    
    return 0;
}
