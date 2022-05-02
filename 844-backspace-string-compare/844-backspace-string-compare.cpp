class Solution {
public:
    bool backspaceCompare(string a, string b) {
        int count=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i]=='#')
                count++;
            else if(count>0)
            {
                count--;
                a[i]='#';
            }
                
        }
        count=0;
        for(int i=b.size()-1;i>=0;i--)
        {
            if(b[i]=='#')
                count++;
            else if(count>0)
            {
                count--;
                b[i]='#';
            }
                
        }
        int i=0;int j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]=='#')
                i++;
            else if(b[j]=='#')
                j++;
            else 
            {
                if(a[i]!=b[j])
                    return false;
                i++;
                j++;
            }
        }
        if(i==a.size() && j<b.size())
        {
            while(j<b.size())
            {
                if(b[j]!='#')
                    return false;
                j++;
                
            } 
        }
        else if(i<a.size()&& j==b.size())
        {
            while(i<a.size())
            {
                if(a[i]!='#')
                    return false;
                i++;
            }
        }
        
            return true; 
    }
};