//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans = 0;
        for(int i = a; i <= b; i++)
        {
            int val = i;
            for(int j = 2; j * j <= i; j++)
            {
                while(val % j == 0)
                {
                    ans++;
                    val /= j;
                }
            }
            if(val > 1)ans++;
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends