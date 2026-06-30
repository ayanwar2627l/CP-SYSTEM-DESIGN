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
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string &word){
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
    string dfs(TrieNode* curr){
        string res="";
        for(int i=0;i<26;i++){
            if(curr->child[i]!=NULL&&curr->child[i]->isEnd==true){
                string temps=(char)(i+'a')+dfs(curr->child[i]);
                if(res.size()<temps.size()){
                    res=temps;
                }
            }
        }
        return res;
        
    }
    string search(){
        return dfs(root);
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* ROOT=new Trie();
        for(string word:words){
            ROOT->insert(word);
        }
        // return ROOT->dfs(ROOT->root);
        return ROOT->search(); 
    }
};