class Solution {
public: 
    long long  n;
    map<long long ,long long >m;
    long long  maxi=-1;
    
        long long  findans(vector<long long >arr[],long long  node)
        {
            if(arr[node].size()==0)
            { 
                maxi=max(maxi,n-1);
                m[n-1]++;
                return 1;
            }
           else  if(arr[node].size()==1)
            {
                
                long long  left=findans(arr,arr[node][0]);
                long long  val=left;
               if(((n-1)-left))
                    val*=((n-1)-left);
                   m[val]++; 
                maxi=max(maxi,val);
                return 1+left;
            }
            
            else if(arr[node].size()==2)
            {
                long long  left=findans(arr,arr[node][0]);
                long long  right=findans(arr,arr[node][1]);
                  
                long long  val=left*right;
                if(((n-1)-(left+right)))
                val*=((n-1)-(left+right));
                    m[val]++; 
                maxi=max(maxi,val);
                return 1+left+right;
            }
            return -1;
            
        }
    int countHighestScoreNodes(vector<int>& v) {
          n=v.size();
        vector<long long >arr[n];
        
        
        for(int i=1;i<n;i++)
        {
            arr[v[i]].push_back(i);
        }
         
        findans(arr,0);
          return m[maxi]; 
    }
};