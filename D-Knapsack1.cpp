#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll int n, w;
    cin >> n >> w;
    vector<pair<ll int, ll int>> v(n);
    for (ll int i = 0; i < n; i++)
        cin >> v.at(i).first >> v.at(i).second;
    ll int dp[n + 1][w + 1];
    // initializing the column that if w == 0 then you can't get anything
    for (ll int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    // initializing the row that if we dont have anything we can't get any value
    for (ll int i = 0; i < w + 1; i++)
        dp[0][i] = 0;

    for (ll int r = 1; r <= n; r++)
    {
        for (ll int wt = 1; wt <= w; wt++)
        {
            // the weight of the r-1'th item is less than the max wt in that box
            // we have two choices to either select the object or not
            if (v.at(r - 1).first <= wt)
                dp[r][wt] = max(dp[r - 1][wt], dp[r - 1][wt - v.at(r - 1).first] + v.at(r - 1).second);
            // we don't have a choice to select he object `
            else
                dp[r][wt] = dp[r - 1][wt];
        }
    }
    cout << dp[n][w] << endl;

    return 0;
}