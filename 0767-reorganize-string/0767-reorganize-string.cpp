class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>m;
        int maxi=0;
        for(auto i:s)
        {
            m[i]++;
            maxi=max(maxi,m[i]);
        }
        
        if(maxi>(s.size()+1)/2)
            return "";
        
        string ans;
        priority_queue<pair<int,char>>q;
        for(auto i:m)
            q.push({i.second,i.first});
        while(q.size()>1)
        {
            pair<int,char>first=q.top();
            q.pop();
            pair<int,char>second=q.top();
            q.pop();
            ans=ans+first.second+second.second;
            first.first--;
            if(first.first>0)
                q.push(first);
            second.first--;
            if(second.first>0)
                q.push(second);
            
            
        }
        if(q.size()==1)
            ans=ans+(q.top()).second;
        return ans;
    }
};