//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const long long mod = 1e9 + 7;
class Solution{
	public:
	long long f(int i,int n,vector<long long>&dp){
	    if(i>=n){
	        return 1;
	    }
	    if(dp[i]!=-1)return dp[i];
	    return dp[i]=(f(i+1,n,dp)+f(i+2,n,dp))%mod;
	}
	int TotalWays(int N)
	{
	    
	    vector<long long>dp(N,-1);
	    long long x=f(0,N,dp);
	    return x*x%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends