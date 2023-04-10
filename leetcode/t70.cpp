class Solution {
public:
    int climbStairs(int n) {
        // int res[46];
        // res[0] = 1;
        // res[1] = 1;
        // res[2] = 2;
        // for (int i = 2; i < 46 ; i++){
        //     res[i] = res[i-1] + res[i-2];
        // }

        // return res[n];

        // save space
        int p = 0, q = 0, res = 1;

        for (int i = 1; i <= n; i++){
            p = q; q = res;
            res = p + q;

        }
        return res;
    }
};