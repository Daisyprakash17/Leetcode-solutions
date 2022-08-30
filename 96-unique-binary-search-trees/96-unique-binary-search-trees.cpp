class Solution {
public:
    int numTrees(int n) {
        vector<int>v(20,0);
        v[0]=1;
        v[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int left=j;
                int right=i-1-j;
                v[i]+=v[left]*v[right];
            }
        }
            
        return v[n];
    }
};