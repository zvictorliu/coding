#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int min_exclude(vector<int> &data, int N){
        vector<int> dpl(N+1, 0); 
        vector<int> dpr(N+1, 0);
        // 左边最大增序列长度
        for (int i = 1; i <= N; i++){
            // 左边所有小于当前i身高的最大增序列长度当中的最大值+1
            for (int j = 1; j < i; j++){
                if (data[i] > data[j]) dpl[i] = max(dpl[i], dpl[j]);
            }
            dpl[i] ++; // i=1则为1
        }

        // 右边最大减序列长度
        for (int i = N; i >= 1; i--){
            for (int j = N; j > i; j--){
                if (data[i] > data[j]) dpr[i] = max(dpr[i], dpr[j]);
            }
            dpr[i] ++;
        }

        // 找最大值
         int max_len = 0;
         for (int i = 1; i <= N; i++) max_len = max(max_len, dpl[i]+dpr[i]-1); //包括了自己，所以要减掉重复的一次


        return N - max_len;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> data(N+1, 0);
    for (int i = 1; i <= N; i++){
        cin >> data[i];
    }

    Solution res;
    cout << res.min_exclude(data, N) << endl;
    return 0;
}