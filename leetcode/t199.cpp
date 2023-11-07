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
层序遍历，每一层的最后一个
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<int> right;
        if (root == nullptr)
            return right;
        Q.push(root);
        while (!Q.empty()){
            int sz = Q.size(); //妙笔
            while (sz > 0){ //一层
                root = Q.front();
                Q.pop();
                if (sz == 1)
                    right.emplace_back(root->val);

                if (root->left != nullptr)
                    Q.push(root->left);
                if (root->right != nullptr)
                    Q.push(root->right);
                sz --;
            } 
        }

        return right;
    }
};

int main() {

    Solution res;
    
    return 0;
}
