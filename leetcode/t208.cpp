#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <cstring>
using namespace std;

class Trie {
    bool isEnd;
    vector<Trie*> next;
public:
    Trie() : next(26, nullptr), isEnd(false) {} // ����д��Ҳ���
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word){
            if (node->next[ch-'a'] == nullptr){
                node->next[ch-'a'] = new Trie();
            }
            node = node->next[ch-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char ch : word){
            node = node->next[ch-'a']; // ���˳��
            if (node == nullptr) return false;
        }
        // ˳��������word
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix){
            node = node->next[ch-'a']; // ���˳��
            if (node == nullptr) return false;
        }
        // ˳��������word
        return true;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
