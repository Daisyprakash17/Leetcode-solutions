// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int, vector<int>, greater<int>>q;
	    for(int i=0;i<n;i++)
	    {
	        q.push(arr[i]);
	        if(q.size()>k)
	            {
	                int val=q.top();
	                q.pop();
 	            }
	    }
	    vector<int >v;
	    while(q.size()>0)
	    {
	        int val=q.top();
	        q.pop();
	        v.push_back(val);
	    
	        
	    }
	    reverse(v.begin(),v.end());
	    return v;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends