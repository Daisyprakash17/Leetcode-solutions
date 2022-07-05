class Solution {
public:
    int ans=-1;
    vector<string>w;
    map<char,int>l;
    vector<int>s;
    void findans(vector<int>&val,int k,int n)
    {
        if(k>=n)
        {  
            map<char,int>temp;
            temp=l;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(val[i]==1)
                {
                     
                    for(auto j:w[i])
                    {
                        temp[j]--;
                        if(temp[j]<0)
                            return ;
                        else
                            sum+=s[j-'a'];
                    }   
                }
            }
           ans=max(ans,sum); 
            return ;
        }
        val[k]=1;
        findans(val,k+1,n);
        val[k]=0; 
        findans(val,k+1,n);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        w=words;
        for(auto i:letters)
            l[i]++;
        s=score;
        int n=w.size();
        vector<int>val(n,0);
        findans(val,0,n);
        return ans;
    }
};