class Solution {
public:
    long long   dp[100001][61];
    long long  check(long long  first,long long  second){
        int a=0;
        int b=0;
        for(int i=0;i<61;i++){
            if((first&(1ll<<i))==(1ll<<i))
                a++;
            if((second&(1ll<<i))==(1ll<<i))
                b++;
        }
        if(a<=b)
            return first;
        else
            return second;
    }
    long long  findans(int r,int i,vector<int>ava){
        
        if(r==0)
            return 0;
        if(r>0 && i>=ava.size())
            return LONG_MAX;
        if(dp[r][i]!=-1)
            return dp[r][i];
        
        long long  taken,not_taken;
        
        // if i want to consider this person
        
        long long  temp=r;
        for(int j=0;j<61;j++){
            if((ava[i]&(1ll<<j))==(1ll<<j)){
                if((temp&(1ll<<j))==(1ll<<j))
                    temp=temp^(1ll<<j);
            }
        }
        taken=findans(temp,i+1,ava);
        not_taken=findans(r,i+1,ava);
        
        if(taken!=LONG_MAX)
        taken+=(1ll<<i); // consider this person so updating the taken number
        
        return dp[r][i]=check(taken,not_taken);
        
    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
       
       memset(dp,-1,sizeof(dp));
        map<string ,int>m;
        int r=0;
        for(int i=0;i<req.size();i++){
            m[req[i]]=i+1;
            r+=(1<<i);
        }
        vector<int>v;
        for(auto i:people){
            int temp=0;
            
            for(auto j:i){
                if(m[j]>0)
                {
                    temp+=(1ll<<(m[j]-1));
                }
            }
            v.push_back(temp);
        }
        // so now we have give the unique number of each of the people
    
        for(auto i:v)
            cout<<i<<endl;
        
        long long  ans=findans(r,0,v);
        vector<int >final_ans;
        for(int i=0;i<61;i++){
            if((ans&(1ll<<i))==(1ll<<i))
                final_ans.push_back(i);
        }
        return final_ans;
    }
};