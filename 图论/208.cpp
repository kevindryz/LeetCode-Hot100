class Trie {
private:
    Trie* nxt[26];
    bool flag;
public:
    Trie() {
        memset(nxt,0,sizeof nxt);
        flag=0;
    }
    
    void insert(string word) {
        Trie* node=this;
        for (char c : word)
        {
            if (!node->nxt[c-'a']) node->nxt[c-'a']=new Trie();
            node=node->nxt[c-'a'];
        }
        node->flag=1;
    }
    
    bool search(string word) {
        Trie* node=this;
        for (char c : word)
        {
            node=node->nxt[c-'a'];
            if (!node) return 0;
        }
        return node->flag;

    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for (char c : prefix)
        {
            node=node->nxt[c-'a'];
            if (!node) return 0;
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */