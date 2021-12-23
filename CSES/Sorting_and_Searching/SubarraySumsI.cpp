#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    long long sum = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = -1, count = 0;
    while (r < n)
    {
        if (sum == x)
        {
            count++;
            sum += a[++r];
        }
        else if (sum < x)
            sum += a[++r];
        else if (sum > x)
        {
            sum -= a[l];
            l++;
        }
    }
    cout << count;
}