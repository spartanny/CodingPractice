#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b)
{
    if (a.length() == 0 or b.length() == 0)
        return 0;
    int dp[a.length() + 1][b.length() + 1] = {0};
    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else
            {
                if (a[i - 1] != b[j - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }
    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[a.length()][b.length()];
}

int main()
{
    string a;
    string b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
}