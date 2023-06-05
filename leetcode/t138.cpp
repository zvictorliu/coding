#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 有一个后验的问题，使得复制random有困难
        unordered_map<Node*,Node*> umap;
        if (head == nullptr) return nullptr;
        Node *p = head->next;
        Node *h = new Node (head->val);
        Node *q = h;
        umap[head] = h;
        while (p != nullptr){
            q->next = new Node (p->val);
            umap[p] = q->next;
            q = q->next;
            p = p->next;
        }

        q = h; p = head;
        while (q != nullptr){
            q->random = umap[p->random];
            q = q->next;
            p = p->next;
        }

        return h;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
