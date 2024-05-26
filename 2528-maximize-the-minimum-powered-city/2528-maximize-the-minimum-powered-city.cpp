#define ll long long 
class Solution {
public:
    bool getans(vector<ll>v,ll r,ll k,ll mid){
        ll count=0;
        
        for(int i=0;i<v.size();i++){
            
            count+=v[i];
            if(count>=mid)
                continue;
            ll diff=mid-count;
            if(diff>k)
                return false;
            count+=diff;
            k-=diff;
            ll ind=i+2*r+1;
            if(ind<v.size())
                v[ind]-=diff;
            }
        return true;
    }
    ll findans(vector<ll>&v,int r,int k){
        ll low=0;
        ll high=1e18;
        ll ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            
            if(getans(v,r,k,mid)==true)
            {
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    long long maxPower(vector<int>& temp, int r, int k) {
        
        vector<ll>v(temp.size(),0);
        for(int i=0;i<temp.size();i++){
            
            int left=max(0,i-r);
            int right=i+r+1;
            v[left]+=temp[i];
            if(right<temp.size())
                v[right]+=(-1*temp[i]);
        }
        return findans(v,r,k);
    }
};