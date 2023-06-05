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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode *head = (list1->val <= list2->val) ? list1 : list2;
        ListNode *smaller = head;
        ListNode *larger = (list1->val <= list2->val) ? list2 : list1;

        while (larger != nullptr)
        {
            while (smaller->next != nullptr && smaller->next->val <= larger->val)
            {
                smaller = smaller->next;
            }
            
            if (smaller->next == nullptr) {
                smaller->next = larger;
                return head;
            }

            ListNode *tmp = larger;
            larger = smaller->next;
            smaller->next = tmp;
            smaller = smaller->next;
        }
        
        return head;

    }
};

int main() {

    // Solution res;
    
    return 0;
}
