#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Greedy


*/

int chocolates[105];


int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int cc = 0; cc < t; ++cc) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;

        for(int i = 0; i < n; ++i) {
            cin >> chocolates[i];
        }

        sort(chocolates, chocolates + n);

        int totalChocolates = 0;
        int totalCost = 0;

        for(int i = 0; i < n; ++ i) {
            if(chocolates[i] < l) continue;

            if(chocolates[i] > r || totalCost + chocolates[i] > k) break;

            ++totalChocolates;
            totalCost += chocolates[i];
        }

        cout << totalChocolates << '\n';
    }
}