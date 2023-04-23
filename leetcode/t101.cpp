#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left == nullptr ^ root->right == nullptr) return false;
        queue<TreeNode*> Tq;
        if (root->left != nullptr) Tq.push(root->left);
        if (root->right != nullptr) Tq.push(root->right);

        while (!Tq.empty())
        {
            TreeNode *leftN = Tq.front();
            Tq.pop();
            TreeNode *rightN = Tq.front();
            Tq.pop();

            if (leftN->val != rightN->val) return false;

            if (leftN->left == nullptr ^ rightN->right == nullptr) return false;
            if (leftN->left != nullptr) Tq.push(leftN->left);
            if (rightN->right != nullptr) Tq.push(rightN->right);

            if (leftN->right == nullptr ^ rightN->left == nullptr) return false;
            if (leftN->right != nullptr) Tq.push(leftN->right);
            if (rightN->left != nullptr) Tq.push(rightN->left);
        }
        
        return true;
    }
};

int main() {

    Solution res;
    
    return 0;
}
