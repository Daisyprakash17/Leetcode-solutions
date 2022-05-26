class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>q;
        double sum=0,temp=0;
        for(auto i:nums)
        {
            
         q.push(i);
            sum+=i;
        }
        
        int count=0;
        while(temp<sum/2)
        {
            
            double val=q.top();
            q.pop();
            
            val=val/2;
            temp+=val;
            count++;
            q.push(val);
         }
        return count;
    }
};