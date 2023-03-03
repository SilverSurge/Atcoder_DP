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

void dfs(int root, const vector<vector<int>> &adj, vector<bool> &visited, vector<vector<int>> &dp)
{
    visited[root] = true;
    int ifblack = 1;
    int ifwhite = 1;
    // no overlapping problems
    for(const int &child: adj[root])
    {
        if(!visited[child]){
            dfs(child, adj, visited, dp);
            ifblack = (ifblack * dp[child][0]%mod)%mod;
            ifwhite = (ifwhite * (dp[child][0]%mod + dp[child][1]%mod)%mod)%mod;
        }
    }
    
    // cout<<root<<" "<<ifwhite<<" "<<ifblack<<endl;
    dp[root][0] = ifwhite;
    dp[root][1] = ifblack;
    
}
void solve()
{
    /* P-Independent Sets */
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x, y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    /*
        dp[node][0] -> the number of ways to paint the subtree with node as root with white color
        dp[node][1] -> with black color

        dp[node][1] = product(dp[child][1]);
        dp[node][0] = product((dp[child][0] + dp[child][1]));

        ans = dp[0][0] + dp[0][1];
    */
    vector<vector<int>> dp(n, vector<int>(2));
    vector<bool> visited(n,false);
    dfs(0, adj, visited, dp);
    debug(dp);
    cout<<(dp[0][0] + dp[0][1])%mod<<endl;
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



