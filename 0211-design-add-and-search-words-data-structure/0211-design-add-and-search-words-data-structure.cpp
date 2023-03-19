class WordDictionary {
public:
    
    WordDictionary *child[26] = {};
    bool isWord = false;
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        WordDictionary *root = this;
        for(char &x : word) {
            int ind = x-'a';
			// check if the child already exists, create if not
            if(!root->child[ind]) root->child[ind] =  new WordDictionary();
            root = root->child[ind];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, this);
    }
     
	
    bool search(string &word, int ind, WordDictionary *root) {
        if(ind==word.length()) return root->isWord;
        char x = word[ind];
        if(x!='.') {
            return root->child[x-'a'] && search(word, ind+1, root->child[x-'a']);
        }
        else {
            for(int i=0;i<26;i++) {
                if(root->child[i] && search(word, ind+1, root->child[i])) return true;
            }
            return false;
        }
        return root->isWord;
    }
};