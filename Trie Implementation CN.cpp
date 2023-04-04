#include <iostream>

using namespace std;

class TrieNode{
public:
    char data;                          //to store data(char value: 'a' to 'z')
    TrieNode ** children;
    bool isTerminal;                    //it will be true if the word terminates at this character
    
    TrieNode(char data){                //constructor
        this->data = data;
        children = new TrieNode*[26];   //array of addresses of TrieNodes
        for(int i = 0; i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode * root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    
    private:
    void insertWord(TrieNode * root, string word){                  //for internal working
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        
        //small calculation
        int index = word[0] - 'a';                  //as for 'a' refers to index 0, b to 1 and so on
        
        TrieNode * child;
        if(root->children[index]!=NULL){            //if first char of string already present as child of root          
            child = root->children[index];
        } 
        else {                                      //first char of string not present as child of root
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        //recursive call
        insertWord(child, word.substr(1));        
    }
    
    public:                             //for user
    void insertWord(string word){
        insertWord(root, word);
    }
    private:
    bool search(TrieNode * root, string word){
        if(word.size()==0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        if(root->children[index]==NULL){
            return false;
        } else {
           
            return search(root->children[index], word.substr(1));
        }
    }
    public:
    bool search(string word) {
        // Write your code here
        return search(root, word);
    }
    
    private:
    void removeWord(TrieNode * root, string word){
        if(word.size()==0){
            root->isTerminal = false;
            return;
        }
        TrieNode * child;
        int index = word[0] - 'a';
        if(root->children[index]!=NULL){
            child = root->children[index];
        } else {
            return;
        }
        
        removeWord(child,word.substr(1));
        
        if(child->isTerminal==false){
            for(int i = 0; i<26; i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            
            delete child;
            root->children[index]=NULL;
        }
        
    }
    
    public:
    void removeWord(string word){
        removeWord(root, word);
    }
};
int main()
{
    
}
