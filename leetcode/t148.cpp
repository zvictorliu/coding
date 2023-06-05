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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode *tail){
        if (head == nullptr) return head;
        // �趨������ҿ�����
        if (head->next == tail){
            head->next = nullptr; // ֻ������һ��
            return head;
        }

        // �ҵ��м�ڵ�
        ListNode *slow = head, *fast = head;
        while (fast != tail){
            slow = slow->next;
            fast = fast->next;
            // ��Ϊ�п���tail�ǿ����Բ���fast->next->nextд��
            if (fast != tail) fast = fast->next;
        }
        ListNode *mid = slow;
        
        return mergeList(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* mergeList(ListNode *head1, ListNode *head2){
        ListNode *varHead = new ListNode (0);
        ListNode *p0 = varHead, *p1 = head1, *p2 = head2;
        while (p1 != nullptr && p2 != nullptr){
            if (p1->val <= p2->val){
                p0->next = p1;
                p1 = p1->next;
            }
            else {
                p0->next = p2;
                p2 = p2->next;
            }
            p0 = p0->next;
        }

        if (p1 == nullptr) p0->next = p2;
        else p0->next = p1;
        // if (p1 != nullptr) p0->next = p1;
        // else if (p2 != nullptr) p0->next = p2;

        return varHead->next;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
