#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
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


// class Solution { //不用递归方法实现中序遍历更有挑战性
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> stk;

//         // 不能按层序遍历那样
//         while (root != nullptr || !stk.empty()){
//             // 一直向左
//             while (root != nullptr){
//                 stk.push(root);
//                 root = root->left;
//             }

//             root = stk.top();
//             stk.pop();
//             res.emplace_back(root->val);
//             root = root->right;
//         }
        
//         return res;
//     }
// };

class Solution { // Morris
public:
    vector<int> inorderTraversal(TreeNode* root) {

    }
};

int main() {

    // Solution res;
    
    return 0;
}
