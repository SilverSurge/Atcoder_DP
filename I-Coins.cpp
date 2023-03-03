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
    int n;
    cin>>n;
    
    vector<double> probHead(n+1);
    for(int i=1;i<=n;i++)
        cin>>probHead[i];
    vector<vector<double>> dp(n+1, vector<double>(n+1));
    // dp[i][j] = i heads out of first j
    dp[0][0] = 1;

    for(int i=1;i<=n;i++)
        dp[0][i] = dp[0][i-1] * (1-probHead[i]);

    for(int numcoins = 1; numcoins <= n ; numcoins++)
    {
        for(int numHead = 1; numHead<=numcoins;numHead++)
        {
            dp[numHead][numcoins] = 
                probHead[numcoins] * dp[numHead-1][numcoins-1]
                +
                (1-probHead[numcoins]) * dp[numHead][numcoins-1];
        }
    }
    double ans = 0;
    for(int i=n/2+1;i<=n;i++)
        ans += dp[i][n];
    cout<<setprecision(20)<<ans<<endl;

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



