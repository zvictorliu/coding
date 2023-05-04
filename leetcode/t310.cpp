#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution { //! ��ʱ��
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> TreeHeights(n, 0);
        vector<int> minTree;
        // todo �����ڽӾ���
        // �Ѽ���û�л�
        vector<vector<int>> adjMatrix(n, vector<int> (n, 0));
        for (auto edge : edges){
            adjMatrix[edge[0]][edge[1]] = 1;
        }

        // �������root
        for (int i = 0; i < n; i++){
            // ���ӽڵ���Ϊ���壬����һ��
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
