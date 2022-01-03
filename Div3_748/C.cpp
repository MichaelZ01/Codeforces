#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

int mices[400005];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int cc = 0; cc < t; ++cc) {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < k; ++i) {
            cin >> mices[i];
        }

        sort(mices, mices + k);

        int cat = 0;
        int saved = 0;
        for(int i = k-1; i >= 0; --i) {
            if(mices[i] > cat) {
                ++saved;
                cat += (n - mices[i]);
            } else {
                break;
            }
        }

        cout << saved << '\n';
    }
}