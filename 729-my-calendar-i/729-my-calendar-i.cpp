class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        end--;
        for(auto i:v)
        {
            if((i.first<=start && i.second>=start) || (i.first<=end && i.second>=end) || 
               ( start<=i.first && end>=i.first) || (start<=i.second && end>=i.second))
                return false;
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */