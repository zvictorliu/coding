#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> isIn (0, 26);
        unordered_set<char> uset;
        int maxLen = 0;
        int len = 0;
        int left = 0;
        for (int j = 0; j < s.length(); j++){
            if (uset.find(s[j]) != uset.end()){ // 存在
                maxLen = max(len, maxLen);
                // 清理之前的
                while (s[left] != s[j]){
                    uset.erase(s[left++]);
                    len--;
                }
                left++;   
            }
            else { // 不存在
                uset.emplace(s[j]);
                len ++;
            }
            
        }
        maxLen = max(len, maxLen);
        return maxLen;
    }
};

int main() {

    string s;
    cin >> s;

    Solution res;
    cout << res.lengthOfLongestSubstring(s) << endl;
    
    return 0;
}
