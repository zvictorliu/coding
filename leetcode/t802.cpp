#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // ����Ϊ0���ն˽ڵ�
        // graph[i]�ж����ն˽ڵ���ǰ�ȫ�ڵ�
        // �ն˽ڵ�һ���ǰ�ȫ�ڵ�
        // ���ȥ����һ���ն˽ڵ㣬�²������ն˽ڵ���ԭ����ͼ��һ���Ƕ������ն˽ڵ�ģ����Ҳһ���ǰ�ȫ�ڵ�
        // ���ȥ���ڶ����ն˽ڵ㣬�²������ն˽ڵ���ԭ����ͼ�ϣ�һ��������ڶ���ģ���ô�Ͳ��ǰ�ȫ�ڵ�
        // ����Ӧ�þ�ֻ��ǰ������ն˽ڵ㣿���Ƕ��ǣ��ðɣ���Ҳ��
        vector<int> res;
        int N = graph.size();
        vector<int> degree(N);
        queue<int> terminals;
        // todo ����Ҫһ�����graph
        vector<vector<int>> parents(N);
        for (int i = 0; i < N; i++){
            degree[i] = graph[i].size();
            if (degree[i] == 0) terminals.push(i);
            for (auto cd : graph[i]){
                parents[cd].push_back(i);
            }
        }
        

        int cnt = 0;
        while (cnt !=2 && !terminals.empty()){ //ֻ��ǰ����
            int sz = terminals.size();
            for (int i = 0; i < sz; i++){
                int tml = terminals.front();
                terminals.pop();
                res.push_back(tml);
                degree[tml] --;
                for (auto neibor : parents[tml]){
                    degree[neibor]--;
                    if (degree[neibor] == 0) terminals.push(neibor);
                }
            }
            cnt ++;
        }
        sort(res.begin(), res.end());
        return res;

    }
};

int main() {

    
    
    return 0;
}
