class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>ans(n,0);
        
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            
            while(st.size()>0  && t[i]>t[st.top()])
            {
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        } 
        return ans;
    }
};