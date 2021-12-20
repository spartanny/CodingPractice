#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> tree(n + 1);
    vector<int> p(n + 1);
    vector<int> distance(n + 1, -1);

    for (int i = 1; i <= n; i++)    cin >> tree[i];
    for (int i = 1; i <= n; i++)    cin >> p[i];

    if (tree[p[1]] != p[1])
    {
        cout << -1;
        return;
    }
    distance[p[1]] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (distance[tree[p[i]]] == -1)
        {
            cout << -1;
            return;
        }
        distance[p[i]] = distance[p[i - 1]] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << distance[i] - distance[tree[i]]<<" ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}