class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>temp(3,0);
        
        for(auto i:triplets){
            if(target[0]>=i[0] && target[1]>=i[1] && target[2]>=i[2]){
                temp[0]=max(temp[0],i[0]);            
                temp[1]=max(temp[1],i[1]);
                temp[2]=max(temp[2],i[2]);

            }
        }
        
        if(target[0]==temp[0] && target[1]==temp[1] && target[2]==temp[2])
            return true;
        else
            return false;
    }
};