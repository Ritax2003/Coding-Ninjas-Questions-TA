
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
bool search(TrieNode *root,string word) {
        // Write your code here
		if(word.size()==0) return true;
          
        if(root->children[word[0]-'a']==NULL)
            return false;

       

        return search(root->children[word[0]-'a'],word.substr(1)); 
    }
    bool search(string word)
    {  return search(root,word);}
    
    
    void autocomplete(TrieNode *root ,string s)
    {
        if(root->isTerminal==true)
            cout<<s<<endl;
        
        for(int i=0 ;i<26 ;i++)
        { if(root->children[i]!=NULL)
          { char c= i + 'a';
            autocomplete(root->children[i],s+c);
            }
        } 
        return;
    }
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
         for(int i=0 ;i<input.size();i++)
            insertWord(input[i]);
        //search in a trie
        if(search(pattern)==false) return ;
        
        
        string s= pattern;
        
        while(pattern.size()!=0)
        {
            root=root->children[pattern[0]-'a'];
            pattern=pattern.substr(1);
        }
        
        autocomplete( root , s);
    }
    
};
int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}