class Solution {
private:
    bool getMatch(int i, int j, string &s, string &p, vector<vector<int>>& dp){
        if(j<=0 && i<=0) return true;
        if(j<=0) return false;
        if(i<=0){
            while(j > 0){ if(p[j-1]!='*') return false; j--;}
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='?')) return dp[i][j] = getMatch(i-1, j-1, s, p, dp);
        else if(p[j-1]=='*') return dp[i][j] = getMatch(i-1, j, s, p, dp) || getMatch(i, j-1, s, p, dp);
        else return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp (n+1, vector<int>(m+1, -1));
        return getMatch(n, m, s, p, dp);
    }
};