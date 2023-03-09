class Solution {
public:
    
    string findans(vector<int>&a,vector<int>&b,int n,int m)
    {
        string temp; 
        if(n>m)
        {
            swap(n,m);
            a.swap(b);
        } 
        if((n<=1) && m==3) 
            temp=to_string(b[0]*100+b[1]*10+b[2]); 
        else if(n==1 && m==2)
        {
             
            if(a[0]>b[1])
                temp=to_string(a[0]*10+b[1]);
            else
                temp=to_string(b[1]*10+a[0]); 
        }
        else
        {
            int i=0;int j=0;
            while(i<n && j<m)
            {
                temp+=to_string(a[i++]);
                temp+=to_string(b[j++]);
            }
        }
        return temp;
    }
    
    string largestMultipleOfThree(vector<int>& digits) {
        string ans="";
        vector<int>one,two;
        sort(digits.begin(),digits.end());
        for(auto i:digits)
        {
            int mod=i%3;
            if(mod==0)
                ans=ans+to_string(i);
            else if(mod==1)
                one.push_back(i);
            else
                two.push_back(i);
        }    
        int n=one.size()%3;
        if(one.size()%3==0 && one.size()!=0)
             n=3; 
        int m=two.size()%3;
        if(two.size()%3==0 && two.size()!=0)
            m=3;  
        
        int i=n,j=m;
          while(n<one.size() || m<two.size())
        {
            if(n<one.size())
                ans+=to_string(one[n++]);
            if(m<two.size())
                ans+=to_string(two[m++]);
        }
        ans+=findans(one,two,i,j);
      
        sort(ans.rbegin(),ans.rend());
        if(ans[0]=='0')
            ans="0";
        return ans;
    }
};