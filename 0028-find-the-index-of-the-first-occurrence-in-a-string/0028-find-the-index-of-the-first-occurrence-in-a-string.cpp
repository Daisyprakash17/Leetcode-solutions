class Solution {
public:
    int strStr(string s, string p) {
        
        
        vector<int>prefixTable(p.size());
        
        int j=0;
        int i=1;
        prefixTable[0]=0;
        
        while(i<p.size()){
            if(p[i]==p[j]){
                prefixTable[i]=j+1;
                j++;
                i++;
            }else if(j>0){
                j=prefixTable[j-1];
            }else{
                prefixTable[i]=0;
                i++;
            }
        }
        
        i=0;
        j=0;
        while(j<p.size() && i<s.size()){
            
            if(s[i]==p[j]){
                j++;
                i++;
            }else if(j>0){
                j=prefixTable[j-1];
            }else{
                i++;
            }
        }
        if(j==p.size()){
            return i-j;
        }
        else
            return -1;
    }
};