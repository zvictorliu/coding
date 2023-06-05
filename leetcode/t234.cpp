#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 恐怕也就是出栈入栈了
        // 如果是O(n)time O(1)space应该怎样
        stack<int> valStk;
        ListNode *p = head;
        while (p != nullptr){
            valStk.emplace(p->val);
            p = p->next;
        }

        p = head;
        int sz = valStk.size();
        for (int i = 0; i < sz / 2; i++){
            if (valStk.top() != p->val) return false;
            valStk.pop();
            p = p->next;
        }

        return true;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
