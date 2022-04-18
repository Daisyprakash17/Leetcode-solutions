class Solution {
public: 
    map<string ,int>m;
     int findans(string a,string  b )
    {  
         // size of different then return 0
         if(a.size()!=b.size())
             return 0;
         // if both of then are same then return 1
         if(a.compare(b)==0)
             return 1;  
         // bellowe we are checking for similar count of the character
         // if do not have similar count then return 0
         map<char,int>mm;
         for(auto i:a)
             mm[i]++;
         for(auto i:b)
             mm[i]--;
         for(auto i:mm)
             if(i.second>0)
                 return 0;
         
         
          // checking if value is already calculated or not
            string key=a;
         key+=" ";
         key.append(b);
         if(m.find(key)!=m.end())
             return m[key];
         int n=a.size();
         int flag=0;
         for(int k=0;k<n-1;k++)
         {  
             int ans=0;
                        // if not swapped 
                int first=findans(a.substr(0,k+1),b.substr(0,k+1)) &&findans(a.substr(k+1,n ),b.substr(k+1,n )); 
                // if swapped 
            int second=(findans(a.substr(0,k+1),b.substr(n-1-k,(k+1)))) && findans(a.substr(k+1,n ),b.substr(0,n-(k+1))); 
            ans=first|second;
            if(ans==1)
                flag=1;
          
         }
         // returning the value of
         return m[key]=flag;
        
         
    }
    bool isScramble(string s1, string s2) { 
        return findans(s1,s2 );
    }
};