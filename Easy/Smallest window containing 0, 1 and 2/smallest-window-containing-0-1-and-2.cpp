//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int n=S.size();
        int a=-1;
        int b=-1;
        int c=-1;
        int ans=INT_MAX;
        
        for (int i=0;i<n;i++)
        {
            if(S[i]=='0')
            {
                a=i;
            }
            else if(S[i]=='1')
            {
                b=i;
            }
            else if(S[i]=='2')
            {
                c=i;
            }
            
            if(a!=-1 && b!=-1 && c!=-1)
            {
                ans=min(ans, (max(c,max(a,b)) - min(a,min(b,c)) +1));
            }
        }
        if(a==-1 || b==-1 || c==-1)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends