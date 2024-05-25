class Solution {
public:
    unordered_map<int,int>par;
    unordered_map<int,int>rank;
    int findpar(int n){
        if(par[n]==n)
            return n;
        return par[n]=findpar(par[n]); // part compression
    }
    void unionjoin(int a,int b){
        int pa=findpar(a);
        int pb=findpar(b);
        // union by rank
        if(rank[pa]==rank[pb]){
            par[pb]=pa;
            rank[pa]++;
        }
        else if(rank[pa]>rank[pb]){
            par[pb]=pa;
        }
        else{
            par[pa]=pb;
        }
    }
    void process(int n){
        vector<int>bits;
        for(int i=0;i<26;i++)
            if((n&(1<<i))!=(1<<i)){
                bits.push_back(i);
                int temp=n;
            temp+=1<<i;
            if(par.count(temp)!=0){
                unionjoin(temp,n); // here implementing the logic of adding
            }
            }
        
        // // adding one of the char
        // for(auto i:bits){
        //     int temp=n;
        //     temp+=1<<i;
        //     if(par[temp]!=0){
        //         unionjoin(temp,n);
        //     }
        // }
        
        // deleting one of the char
//         for(int i=0;i<26;i++){
//             if((n&(1<<i))==(1<<i)){
//                 int temp=n^(1<<i);
//                 if(par[temp]!=0){
//                     unionjoin(temp,n);
//                 }
//             }
//         }
        
        // now i wil have to replace any of the value
        
        for(int i=0;i<26;i++){
            if((n&(1<<i))==(1<<i))
            {
                
                int temp=n^(1<<i);
                if(par.count(temp)!=0){
                    unionjoin(temp,n); // here implementing the logic of deleting
                }
                for(auto j:bits)
                {
                    int supertemp=(temp^(1<<j));
                        if(par.count(supertemp)!=0){
                            unionjoin(supertemp,n);
                        }
                }
            }
        }
    }
    vector<int> groupStrings(vector<string>& words) {
       unordered_map<int,int>counts;
        vector<int>temps;
        for(auto i:words){
            int temp=0;
            for(auto j:i)
            {
                temp+=1<<(j-'a');
            }
            par[temp]=temp;
            rank[temp]=0;
            
            counts[temp]++;
            temps.push_back(temp);
        }
        for(auto i:temps)
            process(i);
        unordered_map<int,int>m;
        int ma=0;
        for(auto i:par)
        {
            if(i.second==0)
                continue;
            int temppar=findpar(i.first);
            m[temppar]+=counts[i.first];
            ma=max(ma,m[temppar]);
        }
        vector<int> myans;
        myans.push_back(m.size());
        myans.push_back(ma);
        return myans;
        
    }
};