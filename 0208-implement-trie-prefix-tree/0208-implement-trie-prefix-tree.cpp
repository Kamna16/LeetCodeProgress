class Trie {
public:
    struct trieNode{
        bool isEnd;
        trieNode* children[26];
    };
    trieNode* root;

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for(int i=0;i<26;i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* Node = root;
        for(char ch : word){
            int index = ch-'a';
            if(Node->children[index]==NULL)
            {
                Node->children[index] = getNode();
            }
            Node= Node->children[index];
        }
        Node->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* Node = root;
        for(char ch : word){
            int index = ch-'a';
            if(Node->children[index]==NULL) return false;
            Node= Node->children[index];
        }
        return Node->isEnd;
    }
    
    bool startsWith(string word) {
        trieNode* Node = root;
        for(char ch : word){
            int index = ch-'a';
            if(Node->children[index]==NULL) return false;
            Node= Node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */