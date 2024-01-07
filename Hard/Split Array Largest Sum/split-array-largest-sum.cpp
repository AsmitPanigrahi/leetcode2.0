//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        return findPages(arr,N,K);
    }
    
    bool isPossible(int arr[], int n, int m, int curMin) {
    int studentsRequired = 1;
    int curSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > curMin) {
            return false;
        }

        if (curSum + arr[i] > curMin) {
            // Increment student count by '1'
            studentsRequired += 1;

            // Update curSum
            curSum = arr[i];

            // If students required becomes greater than given no. of students, return false
            if (studentsRequired > m) {
                return false;
            }
        }
        // Else update curSum
        else {
            curSum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    // If number student is more than number of books
    if (n < m) {
        return -1;
    }

    // Count total number of pages
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Initialize start as 0 pages and
    // End as total pages
    int start = 0, end = sum;
    int result = INT_MAX;

    // Traverse until start <= end , binary search
    while (start <= end) {
        // Check if it is possible to distribute books by using mid as current minimum
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid)) {
            // If yes then find the minimum distribution
            result = min(result, mid);
            end = mid - 1;
        }

        else {
            start = mid + 1;
        }
    }

    return result;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends