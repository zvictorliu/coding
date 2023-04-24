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
        unordered_map<int,vector<int>> umap; //重新构造 先修-后续关系
        for (int i = 0; i < prerequisites.size(); i++){
            umap[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]] ++;
        }

        //todo 将入度为0的入队
        queue<int> CourseQ;
        for (int i = 0; i < numCourses; i++){
            if (inDegree[i] == 0) {
                CourseQ.push(i);
            }
        }
        int cnt = 0;
        // todo 出队，修改inDegree，再放入为0的，直到没有了
        while (!CourseQ.empty())
        {
            // 自己的要修改
            int id = CourseQ.front();
            LearnOrder.push_back(id);
            CourseQ.pop();
            inDegree[id] --;
            // 以该节点为先修的，入度都减1
            for (int i = 0; i < umap[id].size(); i++){
                inDegree[umap[id][i]]--;
                // 在这里进行判断
                if (inDegree[umap[id][i]] == 0) CourseQ.push(umap[id][i]);
            }

            // 记录修过的课程数
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
