class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int>s;
        s.push(v[0]);
        for(int i=1;i<v.size();i++)
        {
            
             while(s.size()>0 && v[i]!=0)
             {
                if(s.top()>0 & v[i]<0)
                {
                    // this means that both the sings are similare
                int val=s.top();
                 s.pop();
                 if(val>abs(v[i]))
                 {
                     v[i]=0;
                    s.push(val);
                 }
                    else if(val==abs(v[i]))
                    {
                        v[i]=0;
                    }
                 
                }
                 else
                 {
                     s.push(v[i]);
                    break;
                }
                
                
                     
                 
             }
            if(s.size()==0 && v[i]!=0)
            {
                s.push(v[i]);
            }
             
        }
        vector<int>ans;
        while(s.size()>0)
        {
            
                    int val=s.top();
                    s.pop();
            ans.push_back(val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};