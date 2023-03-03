#include <iostream>
#define ll long long
using namespace std;
struct day
{
    ll int a;
    ll int b;
    ll int c;
};
int main()
{
    int n;
    cin>>n;
    day days[n];
    for(int i = 0;i<n;i++)
    {
        cin>>days[i].a>>days[i].b>>days[i].c;
    }
    int dp[n+1][3];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i = 1;i<=n;i++)
    {
        dp[i][0] = max(dp[i-1][1],dp[i-1][2])+days[i-1].a;
        dp[i][1] = max(dp[i-1][0],dp[i-1][2])+days[i-1].b;
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+days[i-1].c;
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
 
    return 0;
}