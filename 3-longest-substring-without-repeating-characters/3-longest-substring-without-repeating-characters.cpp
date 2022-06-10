class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=-1;
        int count=0;
        
        map<char,int>m; // this is going the store the index of its last occurence
        
        for(int i=0;i<s.size();i++)
        {
            
            if(m[s[i]]!=0)
            {
                 int in=m[s[i]];
                 for(auto j:m)
                {
                    if(j.second<=in && j.second>0)
                    {
                        
                     m[j.first]=0;
                        count--;
                    }
                }
                
            }  
            m[s[i]]=i+1;
                count++;
                ans=max(ans,count);
            
        }
        return max(ans,count);
         
    }
};