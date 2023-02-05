class Solution {
public:
    void fillin(vector<int>&v,string &s)
    {
        if(s.size()==1)
            return ;
        v[0]=0;
        int i=0;
        int j=1;
        
        while(j<s.size())
        {
            if(s[i]==s[j]) {
                v[j]=i+1;
                i++; 
                j++;
            }
             else
             {
                 if(i==0)
                 {
                     j++;
                 }
                 else
                 {
                     i=v[i-1];
                 }
             }
            
             
        }
        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
    }
    int findindex(vector<int>&in,string &s,string &t)
    {
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size())
        {
         if(s[i]==t[j])
         {
             i++;
             j++;
         }
        else if(j==0)
                i++;
            else
                j=in[j-1];   
        }
        if(j!=t.size()) 
            return -1;
        else
             return i-t.size();
    }
    int strStr(string s, string t) {
        vector<int>in(t.size(),0);
        
           fillin(in,t);
         return findindex(in,s,t);
    }
};