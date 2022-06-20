class Solution {
public:
    long long countVowels(string s) {
        long long ans=0;
        
        int n=s.size();
        string temp="aeiou";
        for(int i=0;i<n;i++)
        {
            if(count(temp.begin(),temp.end(),s[i])==1)
            {    
                long long first=i+1;
                long long second=n-i;
                ans+=first*second; 
            }
        }
        
        return ans;
    }
};