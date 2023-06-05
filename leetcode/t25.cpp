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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // �ݹ��
        // ����k�������� return head
        int sz = 0;
        ListNode *p = head;
        while (p != nullptr) {
            p = p->next;
            sz ++;
        }
        if (sz < k) return head;
        // reverse ǰk�� Ҫ�õ�β����ͷ��
        ListNode *pre, *next;
        pre = nullptr;
        p = head;
        next = p->next;
        sz = 0;
        while (++sz != k){
            p->next = pre;
            
            pre = p;
            p = next;
            next = next->next;
        }
        p->next = pre;
        head->next = reverseKGroup(next, k);
        return p;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
