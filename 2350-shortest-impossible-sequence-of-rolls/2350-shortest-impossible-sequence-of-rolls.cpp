class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
    
        int i=0;
        int n=rolls.size();
        int count=0;
        while(i<n)
        {
            map<int,int>m;
            
            for(;i<n;i++)
            {
                if(m[rolls[i]]==0)
                {
                    m[rolls[i]]++;
                }
                if(m.size()==k)
                    break;
            }
            if(m.size()==k)
                count++;
            i++;
        }
        return count+1;
        
    }
    
};