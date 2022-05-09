class Solution {
public:
    vector<string >ans;
        void findans(int i,int j,int n,int m,string temp)
        {
                // base conditions 
                if(n>0 && m==0)
                    return ;
                if(n==0 && m==0)
                {
                        ans.push_back(temp);
                    return ;
                }
                if(n==0 &&m>0)
                {
                    temp.push_back(')');
                    return findans(i,j+1,n,m-1,temp);
                }
           else if(i==j)
            {
                temp.push_back('(');
                findans(i+1,j,n-1,m,temp); 
            }
            else 
            {
                temp.push_back('(');
                findans(i+1,j,n-1,m,temp);
                temp.pop_back();
                temp.push_back(')');
                findans(i,j+1,n,m-1,temp);
                
            }
        }
    vector<string> generateParenthesis(int n) {
        string temp;
        findans(0,0,n,n,temp);
        return ans;
    }
};