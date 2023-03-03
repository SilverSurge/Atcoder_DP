#include<bits/stdc++.h>
using namespace std;
typedef int int32_t;
#define int long long int
#define endl '\n'
 
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
    	int n, k;
    	cin>>n>>k;
    	vector<int> v(n);
    	for(int i=0;i<n;i++)
    	{
    		cin>>v[i];
    	}
    	vector<int> dp(n);
    	dp[0] = 0;
    	for(int i=1;i<n;i++)
    	{
    		int tmp = INT_MAX;
    		for(int j=1;j<=k;j++)
    		{
    			if(i-j>=0)
    				tmp = min(tmp, dp[i-j] + abs(v[i]-v[i-j]));
    			else
    			    break;
    		}
    		dp[i] = tmp;
    	}
    	cout<<dp[n-1]<<endl;
 
    }
    return 0;
}