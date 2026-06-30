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
    string search(string &word,string subans){
        TrieNode* curr=root;
        for(char ch:word){
            int index=ch-'a';
            if(curr->child[index]!=NULL){
                curr=curr->child[index];
                if(curr->isEnd==false){
                    return "";
                }
            }
        }
        if(subans.size()<word.size()){
            return word;
        }else if(subans.size()==word.size()){
            if(subans<word){
                return subans;
            }else{
                return word;
            }
        }else{
            return subans;
        }
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* ROOT=new Trie();
        for(string word:words){
            ROOT->insert(word);
        }
        string subans="";
        for(string word:words){
            if(ROOT->search(word,subans)!=""){
                subans=ROOT->search(word,subans);

            }
        }
        return subans;
    }
};