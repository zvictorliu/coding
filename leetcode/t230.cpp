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
感觉中序遍历即可啊，并没有很难(非递归)
可能难在进阶：频繁查找第k大、经常增删
*/

// class Solution {
    
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*> stk;
//         int cnt = 0;

//         while (!stk.empty() || root != nullptr){
//             while (root != nullptr){
//                 stk.push(root);
//                 root = root->left;
//             }

//             root = stk.top();
//             stk.pop();

//             if ((++cnt) == k)
//                 return root->val;
//             root = root->right;
//         }

//         return 0;
//     }
// };

/*
根据节点数量来看第k个位于哪个子树
就单纯找还不如解法一，但如果增删该查比较多就比较好
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

    }
};

int main() {

    Solution res;
    
    return 0;
}
