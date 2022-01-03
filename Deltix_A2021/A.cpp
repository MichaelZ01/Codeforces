#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Ah, I now realise that only numbers that are power to 2 can be divided
to 1. Numbers such as 6, stop at 3...
*/

ll a[20];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tt = 0; tt < t; ++ tt) {
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll biggest = -1;

        for(int i = 0; i < n; ++i) {
            ll big = a[i];
            ll res = 0;

            for(int j = 0; j < n; ++j) {
                if(i == j) continue;

                if(a[j] % 2 != 0) {
                    res += a[j];
                    continue;
                }

                if(a[j] >= 2) {
                    big *= a[j];
                    ++res;
                }
            }

            biggest = max(biggest, big + res);
        }

        cout << biggest << '\n';
    }


}