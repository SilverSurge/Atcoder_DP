#include<bits/stdc++.h>
using namespace std;
typedef int int32_t;
#define int long long int
#define endl '\n'

int fun(int idx, const vector<int> &v, vector<int> &dp)
{
	if(idx == 0)
		return 0;
	if(dp[idx] != -1)
	    return dp[idx];
	int ans = INT_MAX;
	if(idx-1>=0)
		ans = min(ans,fun(idx-1,v, dp) + abs(v[idx]-v[idx-1]));
	if(idx-2>=0)
		ans = min(ans, fun(idx-2,v, dp) + abs(v[idx]-v[idx-2]));
	return dp[idx] = ans;
}

int32_t main()
{
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // ..........................//
    
    int tests = 1;
    // cin>>tests;
    for(int test = 1;test<=tests;test++)
    {
    	int n;
    	cin>>n;
    	vector<int> v(n);
    	// vector<int> dp(n,-1);
    	for(int i=0;i<n;i++)
    	{
    		cin>>v[i];
    	}
    	// cout<<fun(n-1,v, dp)<<endl;
    	vector<int> dp(n);
    	dp[0] = 0;
    	dp[1] = abs(v[1]-v[0]);
    	for(int i=2;i<n;i++)
    	{
    		// if(i>=2)
    		dp[i] = min(dp[i-1] + abs(v[i]-v[i-1]), dp[i-2] + abs(v[i]-v[i-2]));
    	}
    	cout<<dp[n-1]<<endl;

    }
    return 0;
}