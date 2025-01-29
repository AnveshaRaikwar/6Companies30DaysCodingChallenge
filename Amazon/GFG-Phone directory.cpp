class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char d){
            this->data = d;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
        }
        
    void insertUtil(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            
            int index = word[0] - 'a';
            TrieNode* child;
            
            if(root->children[index]){
                child = root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            insertUtil(child, word.substr(1));
        }
        void insertWord(string word){
            insertUtil(root, word);
    }
        
    void printsuggestion(TrieNode* curr, vector<string> & temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for( char ch = 'a'; ch <= 'z';ch++){
            TrieNode* next = curr->children[ch-'a'];
            
            if( next!=NULL){
                prefix.push_back(ch);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion( string s){
        TrieNode* prev = root;
        
        vector<vector<string>> output;
        string prefix = "";
        
        for(int i =0; i<s.size(); i++){
            char lastch = s[i];
            prefix.push_back(lastch);
            
            TrieNode* curr = prev->children[lastch - 'a'];
            
            if(curr == NULL){
                for (int j = i; j < s.size(); j++) {
                    output.push_back({"0"}); // "0" indicates no suggestions
                }
                break;
            }
            vector<string> temp;
            printsuggestion(curr, temp, prefix);
            
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};

class Solution{
public:

    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* root = new Trie();
        
        for(int i=0; i<n; i++){
            string str = contact[i];
            root->insertWord(str);
        }
        return root->getSuggestion(s);
    }
};