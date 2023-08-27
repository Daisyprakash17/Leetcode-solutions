#define ll long long 
class Solution {
public:
    bool getans(vector<ll>v,ll n,ll r,ll k,ll mid)
    {
        ll count=0;
        for(int i=0;i<n;i++)
        {
            count+=v[i];
            if(count>=mid)
                continue;
            ll diff=mid-count;
            if(k<diff)
                return false;
            k-=diff;
            count+=diff;
            if((i+2*r+1)<=(n-1))
                v[(i+2*r+1)]+=-1*diff;
        }
        return true;
    }
    ll findans(vector<ll>v,ll n,ll r,ll k)
    {
        ll low=0;
        ll high=1e18;
        ll ans=0;
        
        while(low<=high)
        {
            ll mid=low+(high-low)/2; 
            if(getans(v,n,r,k,mid)==true)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
    long long maxPower(vector<int>& temp, int r, int k) {
        vector<ll>v(temp.size()+5,0);
        
        for(ll i=0;i<temp.size();i++)
        {
            
            ll left=i-r;
            if(left<0)
                left=0;
            ll right=i+r;
            v[left]+=temp[i];
            if((right+1)<=(temp.size()-1))
            v[right+1]+=-1*temp[i];
        }
        return findans(v,temp.size(),r,k);
    }
};