#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 每个元素做一个掩码，然后以掩码为键放入map，最后输出
        // 比较特殊的是空，空的话，空result是不是就完了，还是要一个？先不管吧

        // 还要求了字母只能使用一次，那这个掩码就不好了，可能还得传统哈希表，但也很复杂了
        // 好吧，万物皆可为键，数组也可以
        vector<vector<string>> result;
        unordered_map<int, vector<string>> umap;

        int N = strs.size();
        vector<int> masks(N, 0);
        for (int i = 0; i < N; i++){
            int m = strs[i].length();
            for (int j = 0; j < m; j++){
                masks[i] |= (1 << (strs[i][j] - 'a')); //仅包含小写字母
            }
        }

        for (int i = 0; i < N; i++){
            umap[masks[i]].push_back(strs[i]); //说实话这种添加方式确实有些奇怪
        }

        for (auto iter = umap.begin(); iter != umap.end(); ++iter){
            result.push_back(iter->second);
        }

        return result;
    }
};

int main() {

    Solution res;
    
    return 0;
}
