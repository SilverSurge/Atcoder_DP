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

 
// root = 1
int  combine(const int  &a,const int  &b)
{
    return max(a,b);
}
void build(const vector<int > &a, int  tl, int  tr, int  idx, vector<int > &stree)
{
    if(tl == tr)
        stree.at(idx) = a.at(tl);
    else
    {
        int  tm = tl + (tr-tl)/2;
        build(a,tl,tm,2*idx,stree);
        build(a,tm+1,tr,2*idx+1,stree);
        stree.at(idx) = combine(stree.at(2*idx),stree.at(2*idx+1));
    }
}
 
void update(int  tl, int  tr, int  idx, int  pos, int  val, vector<int > &stree)
{
    if(tl == tr)
        stree.at(idx) = val;
    else
    {
        int  tm = tl + (tr-tl)/2;
        if(pos<=tm)
            update(tl,tm,2*idx,pos,val,stree);
        else
            update(tm+1,tr,2*idx+1,pos,val,stree);
        stree.at(idx) = combine(stree.at(2*idx),stree.at(2*idx+1));
    }
}
int  query(int  tl, int  tr, int  idx, int  l, int  r, vector<int > &stree)
{
    if(l>r)
        return 0;
    else if(tl == l && tr == r)
        return stree.at(idx);
    
 
    int  tm = tl + (tr-tl)/2;
    return combine(query(tl,tm,2*idx,l , min(r,tm),stree) , query( tm+1,tr,2*idx+1,max(l,tm+1),r,stree));
}
void solve(){
    /* Q-Flowers */
    /*
    we will use segment tree for range max query 
    each leaf node in the segment tree corresponds to maximum beauty 
    which can be obtained if the subsequence ends at that number
    */
    int n;
    cin>>n;
    vector<int> h(n), a(n);
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        cin>>a[i];

    vector<int> stree(4*(n+1));
    int ans = -inf;
    for(int i=0;i<n;i++)
    {
        int l = 1, r = h[i]-1;
        int tmp = query(0,n, 1, l, r, stree);
        tmp += a[i];
        ans = max(ans, tmp);
        update(0,n,1, h[i], tmp, stree);
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