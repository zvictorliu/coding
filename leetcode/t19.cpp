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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 要不是我看过那个呢
        ListNode *p = head, *q = head;
        for (int i = 0; i < n; i++){
            q = q->next;
        }
        // 此时 q - p = n
        if (q == nullptr) { // 正数第一个同时也是倒数第n个
            return head->next;
        }
        while (q->next != nullptr){
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }
};

int main() {

    // Solution res;
    
    return 0;
}