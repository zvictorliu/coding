#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution1 { // ! ��ʱ��
public:
    vector<int> findAnagrams(string s, string p) {
        // ��Ҫ������ͬ���ַ��ڣ��ڼ���ʱ�е��鷳��
        unordered_map<char, int> umap;
        vector<int> chars(26, 0);
        for (char ch : p){
            chars[ch- 'a']++;
        }

        int m = s.length(), n = p.length();
        vector<int> startPos;

        for (int i = 0; i <= (m - n); i++){
            // �����Ҳ���ÿ�����¸�ֵ����
            int j;
            umap.clear();
            for (j = i; j < i + p.length(); j++){
                if (chars[s[j]-'a'] == 0){ // �����˲����ڵ�
                    i = j;
                    break;
                }
                if ((++umap[s[j]]) > chars[s[j]-'a']) { // ���������
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

class Solution { // ԭ��vector�ǿ���ֱ�ӱȽϵģ�
public:
    vector<int> findAnagrams(string s, string p) {
        // ������������ 
        int m = s.size(), n = p.size();
        vector<int> startPos;
        if (m < n) return startPos;
        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);

        for (int i = 0; i < n; i++){
            sCount[s[i]-'a']++;
            pCount[p[i]-'a']++;
        }

        if (sCount == pCount) { //����ǳ������ϵ�
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
