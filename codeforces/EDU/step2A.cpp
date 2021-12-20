#include <bits/stdc++.h>
using namespace std;

long long w, h, n;
bool func(long long x)
{
    return (x / w) * (x / h) >= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w >> h >> n;

    long long l = 0; // l is bad
    long long r = 1; //r is good , find the closest right

    while (!func(r))
        r *= 2;
    while (r > l + 1)
    {
        long long m = l + (r - l) / 2;
        if (func(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r << "\n";
}