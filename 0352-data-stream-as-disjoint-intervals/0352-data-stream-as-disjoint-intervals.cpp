class SummaryRanges {
public:
    set<pair<int,int>>s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        
        if(s.size()==0)
        {
            s.insert({value,value});
            return ;
        }  
        pair<int,int>l={-1,-1};
        pair<int,int>r={-1,-1};
        auto it=s.lower_bound({value,0});
        if(it!=s.end() )
        {
            if( (*it).first<=value && (*it).second>=value)
            return ;
            else
                r=(*it); 
             
            if(it!=s.begin())
            { 
                   it--; 
                l=(*it); 
                it++;
            }
             
        }
        else
        {
            // if pointing to end
            it--;
            l=(*it);
            it++;
        } 
       
        pair<int,int>left=l;
        pair<int,int>right=r;
        if(l.first!=-1 && l.first<=value && l.second>=value-1)
        {
            // left merging
             l.second=max(l.second,value);  
            if(r.first!=-1 && r.first-1<=l.second)
            {
                // then again merging with right  
                
                l.second=r.second; 
                s.erase(s.find(right));
            }
            s.erase(s.find(left));
            s.insert(l);
        }
        else if(r.first!=-1 && value>=r.first-1 && value<=r.second)
        {
            // only right merging 
            r.first=value;
            s.erase(s.find(right));
            s.insert(r);
        }
        else
        {
             // no merging in left and right both  
            s.insert({value,value});
        }
         
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(auto i:s)
            ans.push_back({i.first,i.second});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */