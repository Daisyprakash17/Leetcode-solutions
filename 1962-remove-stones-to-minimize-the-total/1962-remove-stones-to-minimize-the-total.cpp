class Solution {
public:
    int minStoneSum(vector<int>& v, int k) {
        
        priority_queue<int>q;
        for(auto i:v)
            q.push(i);
        
        while(k--)
        {
            int val=q.top();
            q.pop();
            q.push(val-val/2);
        }
        int sum=0;
        while(q.size()>0)
        {
            int val=q.top();
            q.pop();
            sum+=val;
        }
        return sum;
    }
};