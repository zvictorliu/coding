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

class Solution {
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        heightOfBinaryTree(root);
        return diameter;     
    }

    int heightOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int heightL = heightOfBinaryTree(root->left);
        int heightR = heightOfBinaryTree(root->right);
        if (heightL + heightR > diameter)
            diameter = heightL + heightR;
        return max(heightL, heightR) + 1;
    }
};

int main() {

    Solution res;
    
    return 0;
}
