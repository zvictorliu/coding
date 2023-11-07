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
    和人来算不同，查找会很耗时间
    那就要增加两个左右区间作为参数再来
    更好的方法？
*/
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
//     }

//     TreeNode* buildTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
//         if (pl > pr || il > ir){
//             return nullptr;
//         }
//         TreeNode* root;
//         // 在inorder里查找preorder[pl]
//         for (int i = il; i <= ir; i++){
//             if (inorder[i] == preorder[pl]){
//                 TreeNode* leftRoot = buildTree(preorder, pl+1, pl+i-il, inorder, il, i-1);
//                 TreeNode* rightRoot = buildTree(preorder, pr-(ir-i-1), pr, inorder, i+1, ir);
//                 root = new TreeNode (preorder[pl], leftRoot, rightRoot);
//                 break;
//             }
//         }
        
//         return root;
//     }
// };

/*
 迭代法
 md太难了
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
};

int main() {

    Solution res;
    
    return 0;
}
