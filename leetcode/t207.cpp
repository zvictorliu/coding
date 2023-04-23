#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 第一个难点是如何构建数据结构
        // 有前驱的节点一定在prerequisites里面的第一维当中，那就是要找0~n但不在p数组中的
        // 一个n大的数组，记录入度；一个umap保存p，方便查找和修改，然后是bfs遍历
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
            CourseQ.pop();
            inDegree[id] --;
            // 以该节点为先修的，入度都减1
            for (int i = 0; i < umap[id].size(); i++){
                inDegree[umap[id][i]]--;
                // 在这里进行判断
                if (inDegree[umap[id][i]] == 0) CourseQ.push(umap[id][i]);
            }

            // 添加入度为0的 这样写不是很好
            // for (int i = 0; i < numCourses; i++){
            //     if (inDegree[i] == 0) {
            //         CourseQ.push(i);
            //     }
            // }

            // 记录修过的课程数
            cnt ++;
        }
        if (cnt == numCourses) return true;
        return false;
    }
};

int main() {

    Solution res;
    
    return 0;
}
