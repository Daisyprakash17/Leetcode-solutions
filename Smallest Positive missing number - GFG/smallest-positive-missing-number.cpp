// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int nums[], int n) 
    { 
        // Your code here
          sort(nums,nums+n);
        int flag=0;
        int ans=-1;
        if(n==0)
        {
                if(nums[0]==1)
                    return 2;
            else
                return 1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0)
                continue;
            else
            {
                if(nums[i]==1)
                {
                    flag=1;
                }
                if(i+1>=n)
                    continue;
                int diff=(nums[i+1]-nums[i]);
                if(diff<=1)
                    continue;
                else
                    {
                    ans= nums[i]+1;
                     break;
                    }
            }
    }
        if(flag==0)
            return 1;
        else if(ans!=-1)
            return ans;
        else
        return nums[n-1]+1;
    } 
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends