class Solution {
public:
    set<string>temp;
    int ma=-1; 
    int findmaxstring(string &s,int i,int k,map<char,int>&m,string& tt){
            
         
            if(k==0)
        { 
            int sum=0; 
            for(auto i:tt)
                sum+=m[i];
            
             if(sum>ma) 
             {
                 ma=sum;
                 temp.clear();
             }
                if(sum==ma)
                temp.insert(tt);
                return 1;
        }
         if(s.size()-i<k)
            return 0;
         
            tt+=s[i];
             
            findmaxstring(s,i+1,k-1,m,tt);
        tt.pop_back();
            findmaxstring(s,i+1,k,m,tt);
            
         
        return 0;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        map<char,int>m;
        set<char>ss;
        for(auto i:s){
            m[i]++;
            ss.insert(i);
        } 
        s=""; 
        for(auto i:ss)
        {
            s+=i;     
        } 
        string help;
        findmaxstring(s,0,k,m,help);        
        
        long long ans=0;
        int mod=1e9+7; 
        cout<<"the mas is "<<ma<<endl;
        for(auto i:temp)
        {
            long long count=1; 
            for(auto j:i)
                count=(count*m[j])%mod;
            ans=(ans+count)%mod;
        }
        return ans;
        
    }
};