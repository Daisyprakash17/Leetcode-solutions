class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        
        vector<vector<int>>ans; 
        for(auto i :v)
            cout<<i[0]<<" "<<i[1]<<endl;
        
        for(int i=0;i<v.size();i++)
        {
            auto temp=v[i];
            if(temp[1]==0)
            {
                ans.push_back(temp);
                continue;
            }
            auto j=ans.begin();
            int count=0;
            while(j!=ans.end())
            {
                if( (*j)[0] >=temp[0])
                    count++;
                if(count>temp[1])
                {
                    count--;
                    break;
                }
                j++;
            }
            cout<<(j-ans.begin())<<endl;
            ans.insert(j,temp);
        }
        return ans;
    }
};