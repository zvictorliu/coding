#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 如果可以修改val的话，那就搜索两遍
        // 不能修改，那就放进哈希表

        // 双指针法的数学证明太难想到了
        set<ListNode*> Lset;
        ListNode *temp = headA;
        while (temp != NULL) {
            Lset.emplace(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp != NULL){
            if (Lset.find(temp) != Lset.end()) return temp;
            temp = temp->next;
        }

        return NULL;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
