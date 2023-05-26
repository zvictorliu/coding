#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char,int> tmap;
        int start = 0, sz = INT_MAX;
        int needCnt = 0;
        for (char ch : t){
            tmap[ch]++;
            needCnt ++;
        }


        int j = 0;
        for (int i = 0; i < s.size(); i++){
            while (j < s.size()){
                if (tmap.find(s[j]) != tmap.end()) { // 确认是t中字符并且i-j中还缺这种字符
                    if (tmap[s[j]] > 0) needCnt--;
                    tmap[s[j]] --;
                }

                if (needCnt == 0){ // 已包含全部字符
                    // 移动i到第一个在其中的字符位置
                    int l;
                    for (l = i; l <= j ; l++){
                        if (tmap.find(s[l]) != tmap.end()) {
                            tmap[s[l]]++;
                            if (tmap[s[l]] > 0) {
                                needCnt ++;
                                break;
                              
                            }
                             
                        }
                    }

                    i = l;
                    if (sz > j - l + 1) {
                        start = l;
                        sz = j - l + 1;
                    } 

                    j++;
                    break; 
                }

                j++;
            }
        }

        if (sz == INT_MAX) return ""; // 不存在

        return s.substr(start, sz);
        
    }
};

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution res;
    cout << res.minWindow(s, t) << endl;
    
    return 0;
}
