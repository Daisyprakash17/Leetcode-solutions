    struct Node {
        Node * links[2];
        int flag=false;
        bool checkval(int i){
            // this will return true if it is not null
            return (links[i]!=NULL); 
        }
        
        void putval(int i,Node * node){
            links[i]=node;
        }
        
        Node * getnextnode(int i)
        {
            return links[i];
        }
    };
class Solution {
public:
    Node * root;
    void putnum(int n)
    {
        Node *node=root;
        for(int i=30;i>=0;i--)
        {
            int val=0;
            if(((1<<i)&n)==(1<<i))
                val=1;
            if(node->checkval(val)==false)
            {
                node->putval(val,new Node());
            }
            node=node->getnextnode(val);
        }
        node->flag=true;// this means bit ended but it not nessary
    }
    int getans(int n)
    {
        Node * node=root;
        int res=0;
        for(int i=30;i>=0;i--)
        {
            int val=0;
            if(((1<<i) &n)==(1<<i))
                val=1;
            if(node->checkval((val+1)%2)==true)
            {
                // if we were able to get the opposite bit 
                // then we can consider this but in the res
                res+=(1<<i);
                node=node->getnextnode((val+1)%2);
            }
            else
            {
                node=node->getnextnode(val);
            }
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        root=new Node();
        
        for(auto i:nums)
        {
            putnum(i);
        }
        
        int ans=0;
        for(auto i:nums)
        {
            ans=max(ans,getans(i));
        }
        return ans;
        
    }
};