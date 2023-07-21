class Solution {
public:
    int minimumScore(string s, string t) {
         vector<int>pre(s.size(),0);
        int count=0;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(j<t.size() && t[j]==s[i])
            {
                count++;
                j++;
            }
            pre[i]=count;
        }
        
        vector<int>suf(s.size(),0);
        count=0;
        j=t.size()-1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(j>0 && t[j]==s[i])   
            {
                count++;
                j--;
            }
            suf[i]=count;
        }
        suf.push_back(0);
        int ans=INT_MAX; 
        for(int i=0;i<s.size();i++)
        {
            int left=pre[i];
            int right=t.size()-suf[i+1]-1;
            ans=min(ans,right-left+1);
            if(i==0)
            {
                left=0;
                right=t.size()- suf[i]-1;
            }
            else
            {
                left=pre[i-1];
                right=t.size() -suf[i]-1;
            }
            ans=min(ans,right-left+1);
        }
        
        if(ans<0)
            ans=0;
         return ans;
    }
};