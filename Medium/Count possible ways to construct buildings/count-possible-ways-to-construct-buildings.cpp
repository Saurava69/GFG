//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long mod = 1e9+7;
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    long long a=2,b=3,c=0;
	    if(N==1) return 4;
	    if(N==2) return 9;
	    for(int i=2;i<N;i++)
	    {
	        c=(a+b)%mod;
	        a=b;
	        b=c;
	        
	    }
	    return c=c*c%mod;
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