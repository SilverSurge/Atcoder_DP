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
    int three_cnt = 0, two_cnt = 0, one_cnt = 0;
    for(int i=0;i<n;i++)
    {
        int val;cin>>val;
        if(val == 3)
            three_cnt++;
        else if(val == 2)
            two_cnt++;
        else if(val == 1)
            one_cnt++;
    }

    /*
    dp[i][j][k] = expected number of operations
        for i threes, j twos, k ones and n-(i+j+k) zeros

    dp[i][j][k] = 1 + (p3*dp[i-1][j+1][k] + p2*dp[i][j-1][k+1] + p1*dp[i][j][k-1] + p0 * dp[i][j][k])
    this has a self relation so 
    we transpose and then get the relation
    dp[i][j][k] =  (1 + (p3*dp[i-1][j+1][k] + p2*dp[i][j-1][k+1] + p1*dp[i][j][k-1])) / (1-p0)
    p3 = three/n
    p2 = two/n
    p1 = one/n
    p0 = zero/n

    dp[0][0][0]
    */
    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1,vector<double>(n+1)));
    dp[0][0][0] = 0;
    for(int three = 0;three <= n; three++)
    {
        for(int two = 0; two <= n; two++)
        {
            for(int one = 0; one <= n; one++)
            {
                int zero = n - three - two - one;
                if(zero >= n)
                    continue;
                if(one + two + three > n)
                    continue;

                double p3 = (1.0)*three/n;
                double p2 = (1.0)*two/n;
                double p1 = (1.0)*one/n;
                double p0 = (1.0)*(zero)/n;
                double val = 0;
                val += 1;
                if(three-1 >= 0) val += p3 * dp[three-1][two+1][one];
                if(two-1 >= 0) val += p2 * dp[three][two-1][one+1];
                if(one-1 >= 0) val += p1 * dp[three][two][one-1];
                dp[three][two][one] = val/(1-p0);
            }
        }
    }
    cout<<setprecision(9)<<endl;
    cout<<fixed;
    cout<<dp[three_cnt][two_cnt][one_cnt]<<endl;
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



