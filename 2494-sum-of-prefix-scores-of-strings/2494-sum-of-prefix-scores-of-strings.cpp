class Solution {
public:
    vector<int> res;
    struct trieNode{
        int count;
        trieNode* children[26];
    };
    trieNode* getNode()
    {
        trieNode* newNode = new trieNode();
        newNode->count =0;
        for(int i=0;i<26;i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    void insert(trieNode* root, string word)
    {
        trieNode* crawler = root;
        for(char ch : word)
        {
            if(crawler->children[ch-'a'] == NULL)
            {
                crawler->children[ch-'a'] = getNode();   
            }
            crawler->children[ch-'a']->count += 1;
            crawler = crawler->children[ch-'a'];
        }
    }
    int getScore(string word,trieNode* root)
    {
        trieNode* crawler = root;
        int score= 0;
        for(auto ch : word)
        {
            score += crawler->children[ch-'a']->count;
            crawler = crawler->children[ch-'a'];
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();   
        trieNode* root = getNode();
        for(string w : words)
        {
            insert(root,w);
        }
        for(int i=0;i<n;i++)
        {
            res.push_back(getScore(words[i],root));
        }
        return res;
    }
};