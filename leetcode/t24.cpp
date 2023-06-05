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
    ListNode* swapPairs(ListNode* head) {
        // �������ʺϵݹ�ⷨ��ֻ�Ǹ��ܲ���
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;

        return next;
    }
};

int main() {

    // Solution res;
    
    return 0;
}