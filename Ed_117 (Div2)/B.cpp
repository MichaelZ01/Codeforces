#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;
    for(int c = 0; c < t; ++c) {
        int n, a, b;
        cin >> n >> a >> b;

        // Not enough numbers to fill the half
        if(a > n / 2 + 1 or b < n / 2) {
            cout << "-1\n";
            continue;
        // b takes one of the large numbers
        } else if (b > n / 2 + 1 and a > n / 2) {
            cout << "-1\n";
            continue;
        // a takes one of the small numbers            
        } else if (a < n/ 2 and b < n / 2 + 1) {
            cout << "-1\n";
            continue;
        }

        cout << a << " ";
        for(int i = n; i > 0; --i) {
            if(i != a and i != b) {
                cout << i << " ";
            }
        }
        cout << b << '\n';
    }

}