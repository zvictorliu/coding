#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int max_limit(vector<int> &R, int cnt){
        int N = R.size();
        int n = N;
        int final_limit = 0;

        while (1)
        {
            int limit = 0;
            limit = cnt / N;

            if (limit == 0){
                return (++final_limit);
            }

            cnt -= (limit * N);
            for (int i = 0; i < N; i++){
                if (R[i] > 0) R[i] -= limit;
                if (R[i] <= 0) {
                    N --;
                    cnt -= R[i];
                    R[i] = 0;
                }
            }

            if (N == 0) {
                if (cnt >= 0) return -1;
            }

            final_limit += limit;
            if (cnt == 0) return final_limit;            
        }
        return final_limit;
    }

};

int main(){

    vector<int> R;
    int cnt;

    int num;
    char ch;
    cin >> num;
    R.push_back(num);

    while ( (ch = getchar()) != '\n'){
        cin >> num;
        R.push_back(num);
    }

    cin >> cnt;


    Solution res;
    cout << res.max_limit(R, cnt) << endl;


    return 0;
}