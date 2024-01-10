//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int mx = INT_MIN;
	    unordered_map<int,int> mp;
	    
	    for(int i=1; i<n; i++)
	    {
	        arr[i] += arr[i-1];
	        if(arr[i]%k == 0)
	            mx = max(mx, i+1);
	    }
	    
	    
	    for(int i=0; i<n; i++)
	    {
	        arr[i] %= k;
	        if(arr[i] < 0)
	            arr[i] += k;
	    }
	    
	    for(int i=0; i<n; i++)
	    {
	        if(mp[arr[i]] > 0)
	            mx = max(mx, i+1- mp[arr[i]]);
	        else
	            mp[arr[i]] = i+1;
	    }
	    
	    if(mx == INT_MIN)
	        return 0;
	    
	    return mx;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends