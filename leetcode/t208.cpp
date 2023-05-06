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
    Trie() : next(26, nullptr), isEnd(false) {} // 这种写法也是妙啊
    
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
            node = node->next[ch-'a']; // 这个顺序
            if (node == nullptr) return false;
        }
        // 顺利查找完word
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix){
            node = node->next[ch-'a']; // 这个顺序
            if (node == nullptr) return false;
        }
        // 顺利查找完word
        return true;
    }
};

int main() {

    // Solution res;
    
    return 0;
}
