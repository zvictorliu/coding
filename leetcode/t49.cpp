#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ÿ��Ԫ����һ�����룬Ȼ��������Ϊ������map��������
        // �Ƚ�������ǿգ��յĻ�����result�ǲ��Ǿ����ˣ�����Ҫһ�����Ȳ��ܰ�

        // ��Ҫ������ĸֻ��ʹ��һ�Σ����������Ͳ����ˣ����ܻ��ô�ͳ��ϣ����Ҳ�ܸ�����
        // �ðɣ�����Կ�Ϊ��������Ҳ����
        vector<vector<string>> result;
        unordered_map<int, vector<string>> umap;

        int N = strs.size();
        vector<int> masks(N, 0);
        for (int i = 0; i < N; i++){
            int m = strs[i].length();
            for (int j = 0; j < m; j++){
                masks[i] |= (1 << (strs[i][j] - 'a')); //������Сд��ĸ
            }
        }

        for (int i = 0; i < N; i++){
            umap[masks[i]].push_back(strs[i]); //˵ʵ��������ӷ�ʽȷʵ��Щ���
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
