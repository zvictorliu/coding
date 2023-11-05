#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
using namespace std;

/* 
    应该要用一个链表，表尾最近久未使用的
    查找可以用哈希表实现，可是如何兼顾两者优点呢？
    get也是访问，也被算在访问次数内
    看来需要将链表节点的指针存在哈希表当中
        
*/

class Node {

public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(){
        prev = nullptr;
        next = nullptr;
    }

    Node(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    
    int cap;
    Node* Head;
    Node* Tail;
public:
    unordered_map<int, Node*> umap;
    LRUCache(int capacity) {
        cap = capacity;
        Head = new Node ();
        Tail = new Node ();
        Head->next = Tail;
        Tail->prev = Head;
    }
    
    int get(int key) {
        unordered_map<int, Node *>::iterator it= umap.find(key);
        if (it == umap.end()){
            return -1;
        }

        //加到链表头，表示最近访问过 还要注意尾部
        it->second->next->prev = it->second->prev;
        it->second->prev->next = it->second->next;
        it->second->prev = Head;
        it->second->next = Head->next;
        Head->next->prev = it->second;
        Head->next = it->second;

        return it->second->value;
    }
    
    void put(int key, int value) {
        Node* target;
        // if (get(key) == -1){ //这里不能用get，否则就会更新了
        unordered_map<int, Node *>::iterator it = umap.find(key);
        if (it == umap.end()){
            target = new Node (key, value);
            // 不存在，要检查是否已满
            if (umap.size() == cap){
                // 删除表尾
                if (umap.size() > 0){ //有元素
                    Node* temp = Tail->prev;
                    //移出哈希表
                    umap.erase(temp->key);
                    // 移出链表 
                    Tail->prev = temp->prev;
                    temp->prev->next = Tail;
                    delete temp;
                }
            }   
        }
        else { //存在
            target = umap.find(key)->second;
            target->value = value; //更新值
            target->next->prev = target->prev;
            target->prev->next = target->next;
        }
    
        //加到链表头
        // 如果是存在的，那么还要处理尾巴的问题
        target->prev = Head;
        target->next = Head->next;
        Head->next->prev = target;
        Head->next = target;

        //加入哈希表
        umap[key] = target;
    }
};

int main() {

    LRUCache lRUCache(1);
    lRUCache.put(2, 1);
    cout << lRUCache.get(2) << endl;
    lRUCache.put(3, 2);
    cout << lRUCache.get(2) << endl;
    cout << lRUCache.get(3) << endl;
    
    return 0;
}
