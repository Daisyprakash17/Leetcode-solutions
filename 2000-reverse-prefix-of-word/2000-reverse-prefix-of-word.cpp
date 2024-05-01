class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        
        int i=0;
        int flag=0;
        for(;i<word.size();i++){
            if(word[i]==ch){
                flag=1;
                break;
            }
        }
        if(flag==1){
            int j=0;
            while(j<=i){
                swap(word[i],word[j]);
                i--;
                j++;
            }
        }
        return word;
        
    }
};