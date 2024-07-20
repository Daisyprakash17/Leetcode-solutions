class Solution {
public:
    string longestPrefix(string s) {
        
        int n=s.size();
        vector<int>prefixTable(n);
        
        int j=0;
        int i=1;
        prefixTable[0]=0;
        while(i<n){
            if(s[j]==s[i]){
                prefixTable[i]=j+1;
                j++;
                i++;
            }else if(j>0)
                j=prefixTable[j-1];
            else{
                prefixTable[i]=0;
                i++;
            }
        }
        int length=prefixTable[n-1];
        cout<<length<<endl;
        return s.substr(0,length);
        
    }
};