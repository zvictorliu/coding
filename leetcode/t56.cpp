#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <limits>
using namespace std;

class Solution1 { // ���������Ĳ���
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
            // �ҵ���һ��1��Ȼ�������һ��-1
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
        // ��С����ͬ������ʼ���������յ�
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i+1;
            while (j < intervals.size() && intervals[j][0] <= end){ // ���ǰһ������С
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
