#include<bits/stdc++.h>

class Solution {
public:
      int isSubstring(string s2, string s1)
            { 
               if(s1.size()>s2.size())
                   return -1;
        
            for(int i=0;i<s2.size()-s1.size();i++)
            {
                
                int flag=1;
                for(int j=0;j<s1.size();j++)
                {
                    if(s1[j]!=s2[i+j])
                    {
                        flag=0; 
                    }
                }
                if(flag==1)
                    return 1;
            }

                return -1;
            }
    void add(string& ans,string t){
        
        int in=-1;
        if(isSubstring(ans,t)==1)
            return ;
        for(int i=0;i<t.size();i++)
        {
            if(i+1>ans.size())
                break;
            
            int j=i;
            int k=ans.size()-1;
            int flag=1;
            while(j>=0)
            {
                if(t[j]!=ans[k])
                {
                    flag=0;
                    break;
                    
                }
                j--;
                k--;
            }
            if(flag)
                in=i;
        }
        for(int j=in+1;j<t.size();j++)
            ans+=t[j];
    }
   
     pair<int,string> findans(vector<string>v)
     { 
          
        string ans=""; 
        ans+=v[0]; 
        add(ans,v[1]);
        add(ans,v[2]); 
        return {ans.size(),ans};
     }
    string minimumString(string a, string b, string c) {
        
        vector<string>v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        multiset<pair<int,string>>res;
        res.insert(findans(v));
        swap(v[1],v[2]);
        res.insert(findans(v));
        swap(v[0],v[2]);
        res.insert(findans(v));
        
        swap(v[1],v[2]);
        res.insert(findans(v));
        
        
        swap(v[0],v[2]);
        res.insert(findans(v));
        
        
        swap(v[1],v[2]);
        res.insert(findans(v));
       
        pair<int,string >ans=*(res.begin());
        return ans.second;
        
    }
};