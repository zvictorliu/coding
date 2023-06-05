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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0, a = 0, b = 0;
        ListNode *p = new ListNode (0);
        ListNode *head = p;
        while (l1 != nullptr || l2 != nullptr){
            a = (l1 == nullptr) ? 0 : l1->val;
            b = (l2 == nullptr) ? 0 : l2->val;

            int sum = (a + b + c) % 10;
            c = (a + b + c) / 10;
            p->next = new ListNode(sum);
            p = p->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (c > 0) p->next = new ListNode(c);

        return head->next;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
