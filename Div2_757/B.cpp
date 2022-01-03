#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Greedy?

Multimap

ll overflow
*/

multimap<ll,int> coords;

int ans[200005];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;

        coords.clear();
        for(int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            coords.emplace(a, i);
        }
        ll posDis = 1;
        ll negDis = 1;
        bool pos = true;

        /*
        for(auto c : coords) {
            cout << c.first << " " << c.second << '\n';
        }
        */

        ll totalDist = 0;
        for(auto it = coords.rbegin(); it != coords.rend(); ++it) {
            auto index = it->second;
            ll times = it->first;

            //cout << "t: " << times << '\n';
            if(pos) {
                totalDist = totalDist + posDis * times * 2;
                pos = false;
                ans[index] = posDis;
                ++posDis;
            } else {
                totalDist = totalDist + negDis * times * 2;
                pos = true;
                ans[index] = -negDis;
                ++negDis;
            }
            //cout << "a: " << ans[index] << " " << index << '\n';

        }
        cout << totalDist << '\n';

        cout << "0" << " ";
        for(int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}