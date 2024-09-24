struct Node{
    public: 
    Node* children[10];
};

class Solution {
public:
    
    Node* getTrieNode()
    {
        Node* node = new Node();
        for(int i=0;i<10;i++)
        {
            node->children[i] = NULL;
        }
        return node;
    }
    void insert(int num , Node* root)
    {
        Node* crawl = root;
        string str = to_string(num);
        for(char ch : str)
        {
            int index = ch-'0';
            if(!crawl->children[index]){
                crawl->children[index] = getTrieNode();
            }
            crawl = crawl->children[index];
        }
    }
    int search(int num , Node* root)
    {
        Node* crawl = root;
        string str = to_string(num);
        int len =0;
        for(char ch : str)
        {
            int index = ch-'0';
            if(crawl->children[index]){
                len++;
                crawl = crawl->children[index];
            }else break; 
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        Node* root = getTrieNode();
        for(int num : arr1)
        {
            insert(num,root);
        }
        int res =0;
        for(int num : arr2)
        {
            res = max(res, search(num,root));
        }
        return res;
    }
};