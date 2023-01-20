//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
            vector<int>temp;
            int i=0,j=0;
            while(i!=array1.size() || j!=array2.size())
            {
                if(i==array1.size())
                {
                    temp.push_back(array2[j]);
                    j++;
                }
                else if(j==array2.size())
                {
                    temp.push_back(array1[i]);
                    i++;
                }
                else {
                    if(array1[i]<=array2[j])
                    {
                         temp.push_back(array1[i]);
                      i++;
                    }
                    else
                    {
                        temp.push_back(array2[j]);
                        j++;
                    }
                }
            } 
            int n=array1.size()+array2.size();
            double res;
            if(n%2==1)
            res=temp[n/2];
            else
            {
                res=(temp[n/2]+temp[(n/2)-1])/2.0; 
            }
            return res;
            
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends