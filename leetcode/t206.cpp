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
    ListNode* reverseList(ListNode* head) {
        // 就，入栈出栈吗？

        if (head == nullptr) return head; // 特殊情况
        stack<ListNode*> Lstk;
        ListNode *p = head;
        while (p != nullptr){
            Lstk.push(p);
            p = p->next;
        }

        head = Lstk.top();
        Lstk.pop();
        p = head;
        while (!Lstk.empty()){
            p->next = Lstk.top();
            Lstk.pop();
            p = p->next;
        }
        p->next = nullptr; // ! 重要
        return head;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
