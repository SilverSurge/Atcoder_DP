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
vector<vector<int>> MatrixMultiplication(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    int m1 = a.size(), n1 = a[0].size(), m2 = b.size(), n2 = b[0].size();
    vector<vector<int>> tmp;
    if(n1 != m2) return tmp;
    vector<vector<int>> c(m1,vector<int>(n2));
    for (auto j = 0; j < n2; ++j)
    {
        for (auto k = 0; k < n1; ++k)
        {
            for (auto i = 0; i < m1; ++i)
            {
                // c[i][j] += a[i][k] * b[k][j];
                c[i][j] = (c[i][j]%mod +  (a[i][k]%mod * b[k][j]%mod)%mod)%mod;
            }
        }
    }
    return c;
}


vector<vector<int>> BinaryMatrixExponentiation( vector<vector<int>> m, int y) {

    /*
        in case of linear recurrences we can use matrix multiplication
        let f(n) = a*f(n-1) + b*(f(n-2)) + c*(f(n-3)) + d(f(n-4))
        then
        height = 4 = number of terms in recurrence
        f(n)                f(0)
        f(n-1)              f(1)
        f(n-2)  =  X^(n)    f(2)
        f(n-3)              f(3)
        where X = 0 1 0 0
                  0 0 1 0 
                  0 0 0 1
                  a b c d
    */
    vector<vector<int>> r(m.size(), vector<int>(m.size()));
    for ( int i = 0; i < m.size(); i++) r[i][i] = 1;
    while (y>0){
        if (y&1) {
            r = MatrixMultiplication(r,m);
        }
        y=y>>1;
        m = MatrixMultiplication(m,m);
    }
    return r;
}

void solve(){
    /* R-Walk */
    int n, k;
    cin>>n>>k;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    /*
    this is a concept from discrete mathematics graph
    that in matrix^k
    m(i,j) = number of ways to go from i to j on a path of length k
    */
    mat = BinaryMatrixExponentiation(mat, k);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans = ans + mat[i][j]%mod;
            ans %= mod;
        }
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