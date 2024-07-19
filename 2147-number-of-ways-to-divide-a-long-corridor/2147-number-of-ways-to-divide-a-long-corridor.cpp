class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int>seatPos;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S')
                seatPos.push_back(i);
        }
        
        if(seatPos.size()%2==1 || seatPos.size()==0)
            return 0;
        
        long long  noOfPar=1;
        long long  mod=1e9+7;
        for(int i=0;i<seatPos.size();i+=2){
            
            if(i+2<seatPos.size()){
                long long diff=seatPos[i+2]-seatPos[i+1];
            noOfPar=(noOfPar*diff)%mod;
            }
        }
        return noOfPar;
    }
};