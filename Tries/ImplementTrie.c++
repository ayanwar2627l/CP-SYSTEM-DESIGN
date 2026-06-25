class TrieNode{
public:
    bool isEnd;
    TrieNode* child[26];

    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root=new TrieNode();
    }

    void insert(string &word) {
        TrieNode* curr=root;

        for(char ch:word){
            int index=ch-'a';

            if(curr->child[index]==NULL){
                curr->child[index]=new TrieNode();
            }

            curr=curr->child[index];
        }

        curr->isEnd=true;
    }

    bool search(string &word) {
        TrieNode* curr=root;

        for(char ch:word){
            int index=ch-'a';

            if(curr->child[index]==NULL){
                return false;
            }

            curr=curr->child[index];
        }

        return curr->isEnd;
    }

    bool isPrefix(string &word) {
        TrieNode* curr=root;

        for(char ch:word){
            int index=ch-'a';

            if(curr->child[index]==NULL){
                return false;
            }

            curr=curr->child[index];
        }

        return true;
    }
};