#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <limits>
using namespace std;

class Solution1 { // 差分数组真的不行
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> divArr;
        for (vector<int> interval : intervals){
            divArr[interval[0]]++;
            divArr[interval[1]]--;
        }

        vector<vector<int>> res;
       
       int state = 0;
       int start,end;
       for (auto item : divArr){
            // 找到第一个1，然后找最后一个-1
           if (item.second > 0 && state == 0)  {
                state = 1;
                start = item.first;
           }
           else if (item.second < 0) {
            end = item.first;
            state = 2;
           }
           else if (item.second > 0 && state == 2){
            state = 1;
            res.push_back({start, end});
            start = item.first;
           }

       }

       if (state == 2) {
        res.push_back({start, end});
       }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 从小到大，同样的起始，找最大的终点
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i+1;
            while (j < intervals.size() && intervals[j][0] <= end){ // 左比前一个的右小
                end = max(end, intervals[j][1]);
                j++;
            }

            res.push_back({start, end});
            i = j;
            
        }

        return res;
    }
};

int main() {

    vector<vector<int>> intervals = {{1,4},{5,6}};

    Solution res;
    res.merge(intervals);
    
    return 0;
}
