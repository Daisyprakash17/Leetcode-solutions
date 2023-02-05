    struct Node {
      Node * links[26];
        int flag=false;
        int count=0;
        bool checkval(char ch)
        {
            return (links[ch-'a']!=NULL);
        }
        void insertval(char ch,Node * node)
        {
            links[ch-'a']=node;
        }
        Node * getnode(char ch)
        {
            return links[ch-'a'];
        }
    };
class Solution {
public:
    Node * root;
    
    void insertstring(string  &s)
    {
        Node * node=root;
        
        for(auto i:s)
        {
            if(node->checkval(i)==false)
            {
                node->insertval(i,new Node());
            }
            node=node->getnode(i);
            node->count++;
        }
        
    }
    int getans(string &s)
    {
        Node * node=root;
        int ans=0;
        for(auto i:s)
        {
            if(node->checkval(i)==false)
                return 0;
            node=node->getnode(i);
            ans+=node->count;
        } 
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
     root=new Node ();
        
        for(auto i:words)
        {
            insertstring(i);
        }
        vector<int>ans;
        for(auto i:words)
        {
            int temp=getans(i);
            ans.push_back(temp);    
        }
        return ans;
        
    }
};