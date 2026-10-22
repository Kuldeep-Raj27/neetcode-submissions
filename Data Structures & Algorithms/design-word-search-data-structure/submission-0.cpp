class TrieNode{
    public:
       unordered_map<char,TrieNode*> children;
       bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c:word){
            if(cur->children.find(c)==cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
        
    }
    
    bool search(string word){
        return dfs(word,0,root);
    }

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* cur = root;
        for(int i=j;i<word.size();i++){
            char c = word[i];
            if(c=='.'){
                for(const auto& [key, child] : cur->children){
                    if(child!=nullptr && dfs(word,i+1,child)){
                        return true;
                    } 
                }
                return false;
            } 
            else {
            if((cur->children.find(c)==cur->children.end())){
                return false;
            }
            cur = cur->children[c];
        }        }
        return cur->endOfWord;
    }
};
