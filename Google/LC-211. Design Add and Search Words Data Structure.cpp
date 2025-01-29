class WordDictionary {
public:

    struct trienode{
        trienode* children[26];
        bool isEndOfWord;
    };

    trienode* getnode(){
        trienode * newnode = new trienode();
        newnode->isEndOfWord = false;

        for(int i=0; i<26; i++){
            newnode->children[i] = NULL;
        }
        return newnode;
    }

    //initializind
    trienode *root;

    WordDictionary() {
        root = getnode();
    }
    
    void addWord(string word) {
        trienode *crawler = root;

        for(int i=0; i<word.size(); i++){
            int index = word[i]-'a';
            if(!crawler->children[index]){
                crawler->children[index] = getnode();
            }
            crawler = crawler->children[index];
            
        }
        crawler->isEndOfWord = true;
    }

    bool searchUtil(trienode * root, string word){
        trienode *crawler = root;

        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(ch == '.'){
                for(int j =0; j<26; j++){
                    if(crawler->children[j]!=NULL){
                        if(searchUtil(crawler->children[j] , word.substr(i+1))){
                            return true;
                        }
                    }
                }
                return false;
            }
            else if(crawler->children[ch-'a'] == NULL){
                return false;
            }
            crawler = crawler->children[ch-'a'];
        }
        return (crawler!=NULL && crawler->isEndOfWord == true);
    }
    
    bool search(string word) { // b 'e' ts  -> when in place of dot we keep all 26 letter . here kept 'e' so we need to tell where crawler is for recursion.
        return searchUtil(root, word);
    }
};
