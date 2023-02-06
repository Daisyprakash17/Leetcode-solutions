// copied 

class Solution {
public:
    void rec(string 
&s,int idx,unordered_set<string> &dictionary,vector<int> &dp)
    {
        // The last index is kept true
        if(idx==s.size())
        {
            dp[idx]=1;
            return ;
        }
        rec(s,idx+1,dictionary,dp);
        string curr;
        for(int i=idx;i<s.size();i++)
        {
            curr+=s[i];
            if(dictionary.find(curr) != dictionary.end() && dp[i+1])
            {
                dp[idx]=1;
                break;
            }
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dictionary(words.begin(),words.end());
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            dictionary.erase(words[i]); // Removing current string so it won't contribute to answer
            int n=words[i].size();
            // creating dp every time, wont add to space comlexity
            vector<int> dp(n+1,0);
            rec(words[i],0,dictionary,dp);
            if(dp[0])
            {
                ans.push_back(words[i]);
            }
            dictionary.insert(words[i]);
        }
        return ans;
    }
};