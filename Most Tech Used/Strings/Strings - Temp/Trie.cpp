struct Trie {
    struct Node {
        Node* child[26];
        int pre = 0;
        int is_word = 0;
        bool win = 0 , lose = 0;
        Node(){
            memset(child, 0, sizeof(child));
        }
    };
 
    Node* root;
 
    Trie(){
        root = new Node;
    }
 
    int count(const string& word){
        Node* cur = root;
        for(auto &c : word){
            int x = c - 'a';
            if(! cur -> child[x])
                return 0;
            cur = cur -> child[x];
        }
        return cur -> pre;
    }
 
    void erase(const string& word, int i, Node* cur){
        if(i == word.size()){
            cur -> is_word--;
            return;
        }
        int x = word[i] - 'a';
        erase(word, i + 1, cur -> child[x]);
        if(--cur -> child[x] -> pre == 0){
            cur -> child[x] = nullptr;
            delete cur -> child[x];
        }
    }
 
    void erase(const string& word){
        if(count(word))
            erase(word, 0, root);
    }
 
    void insert(const string &word){
        Node* cur = root;
        for(auto& c : word){
            int x = c - 'a';
            if(! cur -> child[x])
                cur -> child[x] = new Node;
            cur = cur -> child[x];
            cur -> pre++;
        }
        cur -> is_word++;
    }
};