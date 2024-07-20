class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // we will be neeing monotonically decreasing array
       stack<int>st;
        int n=heights.size();
        vector<int>ans(n,0);
        cout<<"working "<<endl;
        for(int i=n-1;i>=0;i--){
            
             
            while(st.size()>0 && st.top()<=heights[i]){
                st.pop();
                ans[i]++;
            }
            if(st.size()>0)
                ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};