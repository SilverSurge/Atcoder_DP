/*----------------all header files-------*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
 
using namespace std;
/*---------------Debugging Class Template------------------*/
/*copied from my friend's template*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*--------------------all defines----------------*/
#define int long long
#define endl '\n'
const int mod = 1e9+7;
const int inf = 1LL<<60;
 
/*--------------start from here------------------*/
void solve()
{
    /* N-Slimes */
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    /*
    dp[l][r] = the minimum cost for mixing (l....r)

    the recursion 
    dp[l][r] = min(dp[l][i]+dp[i+1][r]) + sum(l....r)
    base case
    dp[i][i] = v[i];
    */
    vector<int> prefix(n);
    prefix[0] = v[0];
    for(int i=1;i<n;i++)
        prefix[i] = prefix[i-1] + v[i];
        
    // debug(v);
    // debug(prefix);

    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0;i<n;i++)
        dp[i][i] = 0;
    for(int l=n-1;l>=0;l--)
    {
        for(int r=l+1;r<n;r++)
        {
            int val = inf;
            int psum;
            if(l == 0)
                psum = prefix[r];
            else
                psum = prefix[r] - prefix[l-1];
            // debug(l, r, psum);
            for(int i=l;i<=r-1;i++)
                val = min(val, dp[l][i]+dp[i+1][r] + psum);
            dp[l][r] = val;
        }
    }
    cout<<dp[0][n-1]<<endl;
    // debug(dp);
} 
int32_t main(){
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // ..........................//
 
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int tests = 1;
    // cin>>tests;
    for(int test = 1;test<=tests;test++)
    {
        // cout<<"Case "<<test<<": ";
        solve();
    }
}



