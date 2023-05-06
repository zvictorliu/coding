#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution1 { //! 超时了
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> TreeHeights(n, 0);
        vector<int> minTree;
        // todo 构建邻接矩阵
        // 已假设没有环
        vector<vector<int>> adjMatrix(n, vector<int> (n, 0));
        for (auto edge : edges){
            adjMatrix[edge[0]][edge[1]] = 1;
        }

        // 逐个当作root
        for (int i = 0; i < n; i++){
            // 将子节点作为整体，算作一层
            vector<int> childs;
            queue<vector<int>> level;
            for (auto ch: adjMatrix[i]){
                if (ch) childs.push_back(ch);
            }
            level.push(childs);
            while(!level.empty()){
                vector<int> parent = level.front();
                level.pop();
                TreeHeights[i]++;
                childs.clear();

                for (auto p : parent){
                    for (auto ch: adjMatrix[p]){
                        if (ch) childs.push_back(ch);
                    }
                }
                level.push(childs);
            }
            
            if (minTree.empty()) {
                minTree.push_back(i);
            }
            else {
                if (TreeHeights[i] < TreeHeights[minTree.back()]) {
                    minTree.clear();
                    minTree.push_back(i);
                }
                else if (TreeHeights[i] == TreeHeights[minTree.back()]){
                    minTree.push_back(i);
                }
            }
        }

        return minTree;
    }
};

class Solution { // 拓扑排序
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 要想到拓扑排序，首先得意识到，这个最短树它其实是可以一层一层给剖出来的
        // 没有认识到这个规律就想不到拓扑排序
        vector<int> res;
        //! 总有比较奇葩的特殊情况
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        // todo 邻接表（比邻接矩阵好一些）
        vector<vector<int>> adjMap(n);
        vector<int> degree(n,0); // 记录度的表，拓扑排序需要这个
        for (auto edge: edges){
            adjMap[edge[0]].push_back(edge[1]);
            adjMap[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;
        // todo 加入叶子节点（度为1的）
        for (int i = 0; i < n; i++){
            if (degree[i]==1) leaves.push(i);
        }

        // todo BFS遍历，一直到最后一层就是最短树的节点了，这是建立在认识到的规律得出的结论上的
        while (!leaves.empty())
        {
            // todo 叶子节点取出来，要放进res里面，后面会被更新，最后在其中的就是目标
            res.clear(); //* 需要更新
            // todo 取出这一层叶子节点的方法
            //? 我之前想的是队列放入的是一个个向量，但其实可以通过个数来做到
            int sz = leaves.size();
            for (int i = 0; i < sz; i++){ // 出队多少次
                int leaf = leaves.front();
                leaves.pop();
                res.push_back(leaf); // 放入res
                // todo 出队后，更新度和相邻节点的度
                degree[leaf]--; //? 这还是必要的
                for (auto neibor: adjMap[leaf]){
                    degree[neibor]--;
                    if (degree[neibor] == 1) leaves.push(neibor); //? 在这里就顺便一起判断了
                }
            }
        }
        return res;
        
    }
};

int main() {

    // Solution res;
    
    return 0;
}
