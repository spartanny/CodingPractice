#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_SIDE = 1000;
int pref[MAX_SIDE + 1][MAX_SIDE + 1];
int forest[MAX_SIDE + 1][MAX_SIDE + 1];

int main() {
    int n,Q;
    cin>>n>>Q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char a;cin>>a;
            forest[i][j] += a=='*';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pref[i][j] = forest[i][j]
                        +pref[i-1][j]
                        +pref[i][j-1]
                        -pref[i-1][j-1];
        }
    }
    for (int q = 0; q < Q; q++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pref[x2][y2]
				- pref[x1-1][y2]
				- pref[x2][y1-1]
				+ pref[x1-1][y1-1] << '\n';

	}
}
