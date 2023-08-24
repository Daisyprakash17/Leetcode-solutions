class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int len = 0 , count = 0 ,tot = 0;
        int n = words.size();
        for(int i = 0 ; i < n ; i++){
            len += words[i].size();count++;
            if( i < n-1 && len + words[i+1].size() + count> maxWidth){
                int noOfSpace = maxWidth - len  ;
                string temp = "";
                if(count == 1 ){
                    temp+=words[i];
                    tot++;
                    for(int k = 0 ; k < noOfSpace ; k++) temp+=" ";
                }
                else {
                    if(noOfSpace % (count-1) == 0){
                        noOfSpace = noOfSpace / (count-1);
                        for(int j = i - count +1 ; j <= i ; j++){
                            temp+=words[j];
                            tot++;
                            if(j != i ){
                                for(int k = 0 ; k < noOfSpace ; k++) temp+=" ";
                            }
                        }
                    }else{
                        int s  = noOfSpace / (count-1);
                        int l = noOfSpace % (count -1 );
                        for(int j = i - count+1 ; j <= i ; j++){
                            temp+=words[j];
                            tot++;
                            if(l  > 0 ){
                                if(j != i) for(int k = 0 ; k < s+1 ; k++) temp+=" ";
                                l--;
                            }else{
                              if(j != i)  for(int k = 0 ; k < s ; k++) temp+=" ";
                            }

                        } 
                    }

                }
                ans.push_back(temp);
                len = 0;
                count = 0 ;
            }

            if(i == n - 1 && tot != n){
                string temp = "";
                int noOfSpace = maxWidth - len;
                if(count == 1 ){
                    temp+=words[i];
                    for(int k = 0 ; k < noOfSpace ; k++) temp+=" ";
                }
                else{
                    for(int j = tot ; j < n ; j++){
                        temp+=words[j];
                        if(j != n - 1 ) temp+=" ";
                    }
                    cout<< noOfSpace - count - 1 ;
                    for(int k = 0 ; k < noOfSpace - count +1   ; k++ ) temp+=" ";
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};