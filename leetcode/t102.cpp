#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (root == nullptr) return levels;
        // levels.push_back({root->val});
        queue<TreeNode*> Tq;
        Tq.push(root);
        int len = 1;
        while (!Tq.empty())
        {
            vector<int> level;
            int nextLen = 0;
            while (len --)
            {
                TreeNode *TN = Tq.front();
                Tq.pop();
                level.push_back(TN->val);
                if (TN->left != nullptr){
                    Tq.push(TN->left);
                    nextLen++;
                }
                if (TN->right != nullptr){
                    Tq.push(TN->right);
                    nextLen++;
                }
            }
            levels.push_back(level);
            len = nextLen;
        }
        return levels;
    }
};

int main() {

    Solution res;
    
    return 0;
}
