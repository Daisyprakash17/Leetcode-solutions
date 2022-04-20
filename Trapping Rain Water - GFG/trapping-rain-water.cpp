// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int v[], int n){
        // code here
           
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=v[0];
        suf[n-1]=v[n-1];
        for(int i=1;i<n;i++)
            pre[i]=max(v[i],pre[i-1]);
        
        for(int i=n-2;i>=0;i--)
        suf[i]=max(v[i],suf[i+1]);
        
        long long  ans=0;
        for(int i=0;i<n;i++)
        {
            int val=min(pre[i],suf[i])-v[i];
            if(val>0)
                ans+=val;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends