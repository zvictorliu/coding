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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        int step = 1;
        while (step < lists.size()){
            for (int i = 0; i+step < lists.size();){
                lists[i] = mergeList(lists[i], lists[i+step]);
                i+=step;
                i+=step;
            }
            step *= 2;
        } 
        return lists[0];
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

        return varHead->next;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
