#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int min_exclude(vector<int> &data, int N){
        vector<int> dp(N, 0);
        for (int i = 1; i <= N; i++){
            if (i == 1) dp[i] = 1;
            
        }

        return 0;
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