class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& t) {
        map<string,multiset<string>>arr;
        stack<string>st;
        
        for(auto i:t)
            arr[i[0]].insert(i[1]);
        
        st.push("JFK");
        vector<string>ans;
        while(st.size()>0)
        {
            string s=st.top();
            
            if(arr[s].size()==0)
            {
                ans.push_back(s);
                st.pop();
            }
            else
            {
                auto it=arr[s].begin();
                st.push((*it));
                arr[s].erase(it);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};