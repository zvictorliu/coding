#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ���ģ��ù�ϣ���ܽ��
        // O(1) space ������ָ�룬һ�����Ӵ�һ������С���л��ܻ�������ʱ�任�ռ䣩
        // set<ListNode*> Lset;
        // ListNode *p = head;
        // while (p != nullptr){
        //     if (Lset.find(p) != Lset.end()) return true;
        //     Lset.emplace(p);
        //     p = p->next;
        // }
        // return false;
        if (head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr){
            if (fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
