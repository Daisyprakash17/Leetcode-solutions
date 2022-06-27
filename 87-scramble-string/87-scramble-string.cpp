class Solution {
public:
    map<string ,int>m;
    int findans(string a,string b )
    {
            if(a.size()!=b.size())
                return 0;
            if(a.compare(b)==0)
             return 1;  
        
        int flag=0;
         map<char,int>mm;
         for(auto i:a)
             mm[i]++;
         for(auto i:b)
             mm[i]--;
         for(auto i:mm)
             if(i.second!=0)
                 return 0;
        
      string key=a;
         key+=" ";
         key.append(b);
         if(m.find(key)!=m.end())
             return m[key];
        int n=a.size();
        for(int k=0;k<a.size()-1;k++)
        {
            int first=findans(a.substr(0,k+1),b.substr(0,k+1))  && findans(a.substr(k+1,a.size()),b.substr(k+1,a.size()));
            int second=findans(a.substr(0,k+1),b.substr(a.size()-k-1,k+1)) &&  findans(a.substr(k+1,a.size()),b.substr(0,a.size() -k-1));
            if(first|second==1)
                flag=1;
            
        }
        return m[key]=flag;

    }
    bool isScramble(string s1, string s2) {
        
        
        return findans(s1,s2);
    }
};