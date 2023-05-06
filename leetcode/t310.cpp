#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution1 { //! ��ʱ��
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

class Solution { // ��������
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Ҫ�뵽�����������ȵ���ʶ����������������ʵ�ǿ���һ��һ����ʳ�����
        // û����ʶ��������ɾ��벻����������
        vector<int> res;
        //! ���бȽ�������������
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        // todo �ڽӱ����ڽӾ����һЩ��
        vector<vector<int>> adjMap(n);
        vector<int> degree(n,0); // ��¼�ȵı�����������Ҫ���
        for (auto edge: edges){
            adjMap[edge[0]].push_back(edge[1]);
            adjMap[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;
        // todo ����Ҷ�ӽڵ㣨��Ϊ1�ģ�
        for (int i = 0; i < n; i++){
            if (degree[i]==1) leaves.push(i);
        }

        // todo BFS������һֱ�����һ�����������Ľڵ��ˣ����ǽ�������ʶ���Ĺ��ɵó��Ľ����ϵ�
        while (!leaves.empty())
        {
            // todo Ҷ�ӽڵ�ȡ������Ҫ�Ž�res���棬����ᱻ���£���������еľ���Ŀ��
            res.clear(); //* ��Ҫ����
            // todo ȡ����һ��Ҷ�ӽڵ�ķ���
            //? ��֮ǰ����Ƕ��з������һ��������������ʵ����ͨ������������
            int sz = leaves.size();
            for (int i = 0; i < sz; i++){ // ���Ӷ��ٴ�
                int leaf = leaves.front();
                leaves.pop();
                res.push_back(leaf); // ����res
                // todo ���Ӻ󣬸��¶Ⱥ����ڽڵ�Ķ�
                degree[leaf]--; //? �⻹�Ǳ�Ҫ��
                for (auto neibor: adjMap[leaf]){
                    degree[neibor]--;
                    if (degree[neibor] == 1) leaves.push(neibor); //? �������˳��һ���ж���
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
