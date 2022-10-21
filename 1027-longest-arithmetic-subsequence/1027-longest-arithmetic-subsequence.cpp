class Solution {
public:
     int pos[1001][501];
    int neg[1001][501];
    map<int,vector<int>>in;
    int findans(vector<int>&v,int i,int diff)
    {
        if(i>=v.size())
            return 0;
         if(diff>=0 && pos[i][diff]!=-1)
         {
             return pos[i][diff];
         }
        else if(diff<0 && neg[i][abs(diff)]!=-1)
            return neg[i][abs(diff)];
        
        int val=1;
        int temp=v[i]+diff;
        if(in.find(temp)!=in.end()) 
        {
             auto it=lower_bound(in[temp].begin(),in[temp].end(),i+1);
        if(it!=in[temp].end())
             val=max(val,1+findans(v,(*it),diff));} 
      if(diff>=0)
          return pos[i][diff]=val;
        else
            return neg[i][abs(diff)]=val;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        memset(pos,-1,sizeof(pos));
        memset(neg,-1,sizeof(neg));
        int val=0;
        for(int i=0;i<n;i++)
        {
            in[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                val=max(val,1+findans(nums,j,nums[j]-nums[i]));
            }
        }
        return val;
    }
};