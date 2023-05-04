#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution { //! 超时了
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

int main() {

    Solution res;
    
    return 0;
}
