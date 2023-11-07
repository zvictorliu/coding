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
最简单按先序序列是新建一个链表
别人的解法还是挺难想到的
*/

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         while (root != nullptr){
//             //左侧为空，往右遍历
//             // while (root->left == nullptr){ //不能这么写，万一右子树为空就完了
//             //     root = root->right;
//             // }
//             if (root->left == nullptr){
//                 root = root->right;
//             }
//             else {
//                 //左侧不为空
//                 TreeNode* tmp = ToRight(root->left);
//                 tmp->right = root->right;
//                 root->right = root->left;
//                 root->left = nullptr;
//                 // 往下一层
//                 root = root->right;
//             }
            
//         }

//     }

//     TreeNode* ToRight(TreeNode* root){ //确保不要传入空节点
//         while (root->right != nullptr){
//             root = root->right;
//         }
//         return root;
//     }

// };

/*
    右-左-根 递归写法
    遍历到一个就把现在右指针指向上一个
    还可考虑递归写法

    或者正常先序遍历递归写法，但是保存右子树
*/
class Solution {
    TreeNode* pre = nullptr;
public:
    void flatten(TreeNode* root) {
        if (root == nullptr){
            return;
        }
        flatten(root->right);
        flatten(root->left); 
        // "访问"
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};


int main() {

    Solution res;
    
    return 0;
}
