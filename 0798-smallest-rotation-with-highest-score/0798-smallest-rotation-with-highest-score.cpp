class Solution {
public:
    int bestRotation(vector<int>& v) {
        int n=v.size();
        vector<int>t(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            int in=v[i];
            if(i<in)
            {
                t[i+1]+=1;;
                t[i+1+(n-1-in)+1]+=-1;
             }
            else
            {
                t[0]+=1;
                t[i-in+1]+=-1;
                 t[i+1]+=1;
                t[n]-1;
             }
        }
        int ans=-1;
        int in=0;
        int count=0;
        for(int i=0;i<n+1;i++)
        { 
            count+=t[i];
            if(count>ans)
            {
                ans=count;
                in=i;
            }
        } 
        return in;
            

    }
};