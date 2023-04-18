#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{

public:
    bool isTwentyFour(vector<int> &nums){
        // 去重
        set<int> st;
        for (int i = 0; i < 4; i++){
            st.insert(nums[i]);
        }
        bool flag;
        for (set<int>::iterator it = st.begin(); it != st.end(); it++){
            int root = *it;
            int val;
            st.erase(root);
            flag = dfs(st, root, 1, 0);
            if (flag) return true;
            st.insert(root);
            it = st.begin();
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

        // st.erase(root);

        bool flag;
        for (set<int>::iterator it = st.begin(); it != st.end(); it++){
            int child = *it; // 后续清空了迭代器，则会变得无效
            st.erase(child);
            for (int i = 0; i <=3; i++){
                flag = dfs(st, child, val, i);
                if (flag) return true;   
            }
            st.insert(child);
            it = st.begin(); // 这依然不是办法，还是麻烦在集合的遍历有问题，这一点远不如数组
            // 这里若不写，会引起段错误，成begin，则又回到第二位，而永远到不了
            // 所以另一种方法是不用集合，还是用数组，只不过多一个参考标记
            // st.insert(root);
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
