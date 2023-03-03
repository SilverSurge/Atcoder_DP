#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define newline '\n'

int mod = 1e9 + 7;
int main()
{
    // fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid.at(i).at(j);
        }
    }
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid.at(i).at(j) == '#')
                dp.at(i).at(j) = 0;
            else if (i == 0 && j == 0)
                dp.at(i).at(j) = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up += dp.at(i - 1).at(j);
                if (j > 0)
                    left += dp.at(i).at(j - 1);
                dp.at(i).at(j) = (up + left) % mod;
            }
        }
    }
    cout << dp.at(m - 1).at(n - 1) << endl;
    return 0;
}
