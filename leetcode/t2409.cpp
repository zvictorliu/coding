#include <iostream>
#include <vector>
#include <regex>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // 正数第二大 - 倒数第二大，除非完全错开
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<string> daysStr = {arriveAlice, leaveAlice, arriveBob, leaveBob};
        vector<int> daysNum(4);
        for (int i = 0; i < 4; i++){
            daysStr[i][2] = ' ';
            istringstream str(daysStr[i]);
            int m,d;
            str >> m >> d;
            daysNum[i] = d;
            for (int j = 0; j < m - 1; j++){
                daysNum[i] += months[j];
            }
        }
        
        if (daysNum[1] < daysNum[2]) return 0;
        if (daysNum[3] < daysNum[0]) return 0;

        sort(daysNum.begin(), daysNum.end());
        return daysNum[2] - daysNum[1] + 1;
    }
};

int main(){
    string aA,lA,aB,lB;
    cin >> aA >> lA >> aB >> lB;
    Solution res;
    cout << res.countDaysTogether(aA, lA, aB, lB);
}