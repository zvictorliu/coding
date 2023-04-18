#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{ // failed

public:
    bool isTwentyFour(vector<int> &nums){
        // 去重
        set<int> st;
        for (int i = 0; i < 4; i++){
            st.insert(nums[i]);
        }
        bool flag;
        // flag = dfs(st, 0, 0, 2);
        // return flag;
        for (set<int>::iterator it = st.begin(); it != st.end(); it++){
            int root = *it;
            int val;
            // for (int i = 0; i <=3; i++){
            //     flag = dfs(st, root, root, i);
            //     if (flag) return true;
            // }
            flag = dfs(st, root, 1, 0);
            if (flag) return true;
        }
        return false;
    }

    bool dfs(set<int> &st, int root, int val, int op){
        switch (op)
        {
            case 0:
                val *= root;
                break;
            case 1:
                val /= root;
                break;
            case 2:
                val += root;
                break;
            case 3:
                val -= root;
                break;        
            default:
                break;
        }
        if (val == 24) return true;

        st.erase(root);

        bool flag;
        for (set<int>::iterator it = st.begin(); it != st.end(); it++){
            int root = *it;
            for (int i = 0; i <=3; i++){
                flag = dfs(st, root, val, i);
                if (flag) return true;
                st.insert(root);
            }
        }
        return false;

    }

};

int main() {
    vector<int> nums(4);
    for (int i = 0; i < 4; i++){
        cin >> nums[i];
    }

    Solution res;
    cout << res.isTwentyFour(nums) << endl;
    
    return 0;
}
