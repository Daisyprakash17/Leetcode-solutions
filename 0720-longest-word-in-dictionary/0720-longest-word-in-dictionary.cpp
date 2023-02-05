    struct Node {
        Node * links[26];
        bool flag=false;
        
        bool checknode(char ch)
        {
            // if not null then is will return true
            return (links[ch-'a']!=NULL);
        }
        void insertnode(char ch,Node * node)
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
     string ans;
    Node * root;
    void insertstring(Node * root,string &s)
    {
        Node * node=root;
        int flag=true;
        for(int i=0;i<s.size();i++)
        {
            if(node->checknode(s[i])==false)
            { 
                node->insertnode(s[i],new Node());
            }
            node=node->getnode(s[i]);
            if(i<s.size()-1 && node->flag==false)
            {
                flag=false;
            }
        }
        node->flag=true;
        if(flag)
        {
            if((ans.size()==s.size() && s<ans) || (ans.size()<s.size())) 
                ans=s; 
        }
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        root=new Node();
        for(auto i:words)
        {
                insertstring(root,i);    
        }
        return ans;
        
    }
};