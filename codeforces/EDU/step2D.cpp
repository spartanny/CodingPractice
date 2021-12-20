#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m, n;
vector<ll> blown;
vector<struct w> worker;
struct w
{
    ll t, z, y;
};

ll helper(struct w m, ll time)
{
    ll ans = 0;
    ans += m.z * (time / (m.z * m.t + m.y));
    ll rem = time % (m.t * m.z + m.y);
    if (rem >= (m.t * m.z)) ans += rem;
    else ans += rem/m.t;
    return ans;
}

bool good(ll x)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        blown[i] = helper(worker[i], x);
        sum += blown[i];
    }
    return sum >= m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    blown.resize(n);
    for (int i = 0; i < n; i++)
    {
        ll t, z, y;
        cin >> t >> z >> y;
        worker.push_back({t, z, y});
    }
    ll l = 0, r = 1e17;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (good(m))
            r = m;
        else
            l = m;
    }
    cout << r << endl;
    for (auto i : blown)
        cout << i << " ";
}