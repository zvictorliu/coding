#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution{

public:
    void GetBeautyValue(vector<string> &data, vector<int> &beautiVal, int N){
        //那必然是出现字母最多的设定的漂亮度最高，依次递减
        for (int i = 0; i < N; i++){
            string str = data[i];
            // 统计数量，排序
            int str_len = str.length();

            vector<int> char_cnt(26, 0);
            
            for (int j = 0; j < str_len; j++){
                ++ char_cnt[str[j] - 'a'];
            }

            sort(char_cnt.begin(), char_cnt.end(), greater<int>());

            int factor = 26;
            for (int k = 0; k < 26; k++){
                if (char_cnt[k]){
                    beautiVal[i] += (char_cnt[k] * factor);
                    -- factor;
                }
            }
        }
    }

};

int main() {
    int N;
    cin >> N;

    vector<string> in_str(N);
    vector<int> beautiVal(N, 0);

    for (int i = 0; i < N; i++){
        cin >> in_str[i];
    }

    Solution res;
    res.GetBeautyValue(in_str, beautiVal, N);
    for (int i = 0; i < N; i++){
        cout << beautiVal[i] << endl;
    }

    return 0;
}
