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
        // ��������޸�val�Ļ����Ǿ���������
        // �����޸ģ��ǾͷŽ���ϣ��

        // ˫ָ�뷨����ѧ֤��̫���뵽��
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
