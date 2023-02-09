struct Node{
    Node * link[26];
    int flag=false;
    bool findval(char ch)
    {
        return link[ch-'a']!=NULL;
    }
    void insertval(char ch,Node * node)
    {
        link[ch-'a']=node;
    }
    Node * nextval(char ch)
    {
        return link[ch-'a'];
    }
};

class Solution {
public:
    int val[26][26];
    Node * root;
    void insertstring(string& s )
    {
        Node * node=root;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(node->findval(s[i])==false)
            {
                node->insertval(s[i],new Node());
            }
            node=node->nextval(s[i]);
        }
        node->flag=true;   
    }
    
    void checkstring(string &s)
    {
        Node * node=root;
        int flag=true;
        for(int i=s.size()-1;i>0;i--)
        { 
            node=node->nextval(s[i]);
        }
        char ch=s[0];
        char cc='a';
        for(int i=0;i<26;i++)
        {
            if(node->findval(cc)==false)
            {
                val[ch-'a'][cc-'a']++;
            }
            else
            {
                Node * t=node->nextval(cc);
                if(t->flag==false)
                {
                    val[ch-'a'][cc-'a']++;
                }
            }
            cc++;
        }
        
    }
    
     
        long long distinctNames(vector<string>& t) {
        vector<string >v[26];
       root= new Node();
        for(auto i:t)
            insertstring(i);
        for(auto i:t)
            checkstring(i);
            
            
            long long res=0;
        
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                res+=2*(val[i][j]*val[j][i]);
                
            }
        }
        return res;
        
        
        
    }
};