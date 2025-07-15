#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[52];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<52;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;            
        }
        //assumption word will be in caps
        // int index=word[0]-'a';

         int index;
        if(isupper(word[0])){
            index=word[0]-'A'+26;
        }
        else{
            index=word[0]-'a';
        }
        TrieNode* child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //recursion
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
       insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        // int index=word[0]-'a';
        int index;
        if(isupper(word[0])){
            index=word[0]-'A'+26;
        }
        else{
            index=word[0]-'a';
        }
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else{
            //absent
            return false;
        }

        //resursion
        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }
};
int main(){
    Trie* t=new Trie();
    t->insertWord("abcd");
    t->insertWord("AbCd");
    cout<<"present or not "<<t->searchWord("abcd")<<endl;
    cout<<"present or not "<<t->searchWord("Abcd")<<endl;
    return 0;
}