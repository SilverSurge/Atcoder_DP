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
    /* L - Deque */
    int n;cin>>n;
    vector<int> v(n);
    int summ = 0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        summ += v[i];
    }
    /*
        we have x-y but also
        x + y = c (summ(v))
        thus we need 2*x-c

        dp[l][r][p] = x when
        (l.....r) consdiered
        by person i
        p = 0 -=> first, maximise;
        p = 1 -=> second, minimise;

        base cases
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;

        transitions
        dp[l][r][0] = max(dp[l+1][r][1]+a[l], dp[l][r-1][1]+a[r]);
        dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]);
    */
    
    int dp[n][n][2] = {0};
    for(int i=0;i<n;i++)
    {
        dp[i][i][0] = v[i];
        dp[i][i][1] = 0;
    }
    for(int l = n-1;l>=0;l--)
    {
        for(int r = l+1;r<n;r++)
        {
            // if(l>=r)
                // continue;
            dp[l][r][0] = max(dp[l+1][r][1] + v[l], dp[l][r-1][1] + v[r]);
            dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]);

        }
    }
    cout<<2*dp[0][n-1][0] - summ<<endl;
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



