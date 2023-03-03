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
const int inf = 1LL<<62;

/*--------------start from here------------------*/

void solve(){

    /* E-Knapsack 2 */
    int n, w;
    cin>>n>>w;
    vector<int> weight(n), value(n);
    for(int i=0;i<n;i++)
        cin>>weight[i]>>value[i];
    /*
        this time dp[i][v] = the minimum weight required to get value v using the items till index i 

        base case:
            dp[i][0] = 0
        dp[0][value[0]] = weight[0]
    */
    vector<vector<int>> dp(n, vector<int>(100005,inf));
    for(int i=0;i<n;i++)
        dp[i][0] = 0;
    dp[0][value[0]] = weight[0];
    for(int idx = 1; idx<n;idx++)
    {
        for(int v = 1; v <= 100000; v++)
        {
            int nottake = dp[idx-1][v];
            int take = inf;
            if(v-value[idx] >= 0 && dp[idx-1][v-value[idx]] != inf)
                take = dp[idx-1][v-value[idx]] + weight[idx];
            dp[idx][v] = min(take, nottake); 
        }
    }
    int ans = 0; 
    for(int i=0;i<=100000;i++)
    {
        if(dp[n-1][i] <= w)
            ans = i;
    }
    cout<<ans<<endl;
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