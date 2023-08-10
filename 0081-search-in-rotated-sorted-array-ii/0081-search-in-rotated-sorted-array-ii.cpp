class Solution {
public:
    
    
        bool getans(vector<int>v,int val)
         {
 
            int low=0;
            int high=v.size()-1;
            
            while(low<=high)
            {
                
                
                int mid=low+(high-low)/2;
                cout<<low<<" "<<mid<<" "<<high<<endl;
                if(v[mid]==val)
                    return true;
                
                if(v[mid]==v[low] && v[mid]==v[high])
                {
                    low++;
                    high--;
                    continue;
                }
                if(v[low]<=v[mid])
                {
                    // if left side is sorted 
                    if(val>=v[low] && val<=v[mid])
                    {
                        high=mid-1;
                    }
                    else
                        low=mid+1;
                }
                else
                {
                    
                    // else right is sorted 
                    if(val>=v[mid] && val<=v[high])
                    {
                            low=mid+1;
                        
                    }
                    else
                        high=mid-1;
                }
            }
            return false;
         }
    
    
    bool search(vector<int>& v, int target) {
        
        return getans(v,target);
        
             
     }
};