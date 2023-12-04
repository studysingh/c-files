#include<bits/stdc++.h>
using namespace std;
// INITIALISING TRIE NODE
class TrieNode{
public:
    char ch;
    TrieNode* child[26];
    bool isTerminal;
    TrieNode(char ch){
        this->ch = ch;
        for(int i=0;i<26;i++){
            this->child[i] = NULL;
        }
        this->isTerminal = false;
    }
};
class Trie{
public:
    //insertion
    void insertUtil(string word , TrieNode* &root){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'A';
        if(root->child[idx] != NULL){   //present
            insertUtil(word.substr(1) , root->child[idx]);
        } else{     //absent
            TrieNode* new_node = new TrieNode(word[0]);
            root->child[idx] = new_node;
            insertUtil(word.substr(1) , root->child[idx]);
        }

    }
    void insertWord(string word , TrieNode* &root){
        // when root is null we insert the null character
        if(root == NULL){
            TrieNode* new_node = new TrieNode('\0');
            root = new_node;
        }
        insertUtil(word , root);
    }

    // searching
    bool searchUtil(string word , TrieNode* root){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int idx = word[0]-'A';
        // present
        if(root->child[idx] != NULL){
            return searchUtil(word.substr(1) , root->child[idx]);
        } else{
            //absent
            return false;
        }
    }
    bool searchWord(string word , TrieNode* root){
        return searchUtil(word , root);
    }
};

int main(){
    TrieNode* root = NULL;
    Trie t;
    t.insertWord("SAN" , root);
    t.insertWord("SAT" , root);
    // fun(root , "SAN" , "SAT");
    t.insertWord("SATUR" , root);
    t.insertWord("NAD" , root);
    // cout<<t.searchWord("SAN" , root)<<endl;
    // cout<<t.searchWord("SAT" , root)<<endl;
    // cout<<t.searchWord("SATUR" , root)<<endl;
    // cout<<t.searchWord("SA" , root)<<endl;
    // cout<<t.searchWord("NAD" , root)<<endl;
    return 0;
}