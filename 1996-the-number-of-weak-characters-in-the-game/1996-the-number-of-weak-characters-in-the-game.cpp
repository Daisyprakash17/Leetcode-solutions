class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
         sort(v.begin(),v.end());
        vector<pair<int,int>>temp;
        multiset<pair<int,int>>s;
        for(auto i:v){
            s.insert({i[1],i[0]});
            temp.push_back({i[0],i[1]});
        }
        
        int count=0;
        
        for(int i=0;i<v.size();i++)
        {
             
            auto it=s.find({temp[i].second,temp[i].first});
            if(it!=s.end())
            { 
                s.erase(it);  
            for(int j=i+1;j<v.size();j++)
            {
                if(temp[j].first==temp[i].first)
                { 
                    auto it=s.find({temp[j].second,temp[j].first});
                    if(it!=s.end())
                    s.erase(it);    
                }
                else
                    break;
            }
            }
            it=s.lower_bound(make_pair(temp[i].second+1,0));
            if(it!=s.end())  
                count++; 
        }
        return count;
    }
};