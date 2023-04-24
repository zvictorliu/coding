#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> LearnOrder;
        vector<int> inDegree(numCourses, 0);
        unordered_map<int,vector<int>> umap; //���¹��� ����-������ϵ
        for (int i = 0; i < prerequisites.size(); i++){
            umap[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]] ++;
        }

        //todo �����Ϊ0�����
        queue<int> CourseQ;
        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] == 0) {
                CourseQ.push(i);
            }
        }
        int cnt = 0;
        // todo ���ӣ��޸�inDegree���ٷ���Ϊ0�ģ�ֱ��û����
        while (!CourseQ.empty())
        {
            // �Լ���Ҫ�޸�
            int id = CourseQ.front();
            LearnOrder.push_back(id);
            CourseQ.pop();
            inDegree[id] --;
            // �Ըýڵ�Ϊ���޵ģ���ȶ���1
            for (int i = 0; i < umap[id].size(); i++){
                inDegree[umap[id][i]]--;
                // ����������ж�
                if (inDegree[umap[id][i]] == 0) CourseQ.push(umap[id][i]);
            }

            // ��¼�޹��Ŀγ���
            cnt ++;
        }
        if (cnt != numCourses) LearnOrder.clear();
        return LearnOrder;
    }
};
int main() {

    Solution res;
    
    return 0;
}
