#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution1 { // ! 超时了
public:
    vector<int> findAnagrams(string s, string p) {
        // 主要是有相同的字符在，在检索时有点麻烦？
        unordered_map<char, int> umap;
        vector<int> chars(26, 0);
        for (char ch : p){
            chars[ch- 'a']++;
        }

        int m = s.length(), n = p.length();
        vector<int> startPos;

        for (int i = 0; i <= (m - n); i++){
            // 但是我不能每次重新赋值啊！
            int j;
            umap.clear();
            for (j = i; j < i + p.length(); j++){
                if (chars[s[j]-'a'] == 0){ // 遇到了不存在的
                    i = j;
                    break;
                }
                if ((++umap[s[j]]) > chars[s[j]-'a']) { // 遇到过多的
                    for (int k = j-1; k >=i; k--){
                        if (s[k] == s[j]) {
                            i = k;
                            break;
                        }
                    }
                    break;
                }
            }

            if (j - i == n) startPos.push_back(i);
        }

        return startPos;
    }
};

class Solution { // 原来vector是可以直接比较的？
public:
    vector<int> findAnagrams(string s, string p) {
        // 定长滑动窗口 
        int m = s.size(), n = p.size();
        vector<int> startPos;
        if (m < n) return startPos;
        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);

        for (int i = 0; i < n; i++){
            sCount[s[i]-'a']++;
            pCount[p[i]-'a']++;
        }

        if (sCount == pCount) { //这个是出乎意料的
            startPos.push_back(0);
        }

        for (int i = 0; i < m-n; i++){
            sCount[s[i]-'a']--;
            sCount[s[i+n]-'a']++;

            if (sCount == pCount) startPos.push_back(i+1);
        }

        return startPos;
    }
};

int main() {

    string s,p;
    cin >> s >> p;

    Solution res;
    res.findAnagrams(s, p);
    
    return 0;
}
