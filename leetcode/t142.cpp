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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        set<ListNode*> Lset;
        while (p != nullptr){
            if (Lset.find(p) != Lset.end()) return p;
            Lset.emplace(p);
            p = p->next;
        }
        return nullptr;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
