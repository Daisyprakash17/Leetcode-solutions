class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1)
            return (target[0]==1);
        
        priority_queue<int>q;
        
        long long sum=0;
        for(auto i:target)
        {
            
         q.push(i);
            sum+=i;
        }
        int flag=0;
        
        
        
        
        while(q.top()!=1)
        {
            
            long long val=q.top();
            cout<<val<<endl; 
            long long bsum=sum-val;
            if(val<=bsum || bsum<1)
                return false;
            q.pop();
            
             long long oval=val%bsum; 
            sum=bsum+oval; 
            
            
            if(oval)
                q.push(oval);
            else
                q.push(sum);
        }
       
            return true; 
        }
};