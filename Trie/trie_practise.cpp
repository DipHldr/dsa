#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[26]={nullptr};
    bool output=false;
};

class Trie{
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    }

    void findAllStringsWithPrefix(TrieNode* node,string& path,vector<string>&result){
        if(node->output)result.push_back(path);

        for(int i=0;i<26;i++){
            if(node->child[i]){
                path.push_back('a'+ i);
                findAllStringsWithPrefix(node->child[i],path,result);
                path.pop_back();
            }
           
        }
    }

    void insert(const string & s){
        TrieNode* node=root;
        for(char ch:s){
            int idx=ch-'a';
            if(!node->child[idx]){
                node->child[idx]=new TrieNode();
            }
            node=node->child[idx];
        }
        node->output=true;
    }

    bool search(const string & s){
        TrieNode* node=root;
        for(char ch:s){
            int idx=ch-'a';
            if(!node->child[idx])return false;

            node=node->child[idx];
        }

        return node->output;
    }

    bool startsWith(const string& s){
        TrieNode* node=root;
        for(char ch:s){
            int idx=ch-'a';
            if(!node->child[idx])return false;

            node=node->child[idx];
        }

        return true;
    }

    vector<string> getWordsWithPrefix(const string& prefix){
        TrieNode* node=root;
        for(char ch:prefix){
            int idx=ch-'a';
            if(!node->child[idx])return {};

            node=node->child[idx];
        }

        vector<string> result;
        string path=prefix;
        findAllStringsWithPrefix(node,path,result);
        return result;
    }
};

int main(){
    Trie trie;
    trie.insert("apple");
    trie.insert("appyfizz");
    trie.insert("applepie");
    trie.insert("batman");
    trie.insert("batista");
    trie.insert("bat");

    cout<<trie.search("apple")<<endl;
    cout<<trie.search("bata")<<endl;
    cout<<trie.startsWith("app")<<endl;
    cout<<trie.startsWith("ba")<<endl;

    vector<string>op=trie.getWordsWithPrefix("b");
    for(string& s:op)cout<<s<<endl;

    return 0;
}
