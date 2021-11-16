#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }


set<int> fav;

int minDist(int x, int y) {
    int d1 = abs(x-y);
    int d2 = abs((x+26)-y);
    int d3 = abs((y+26)-x);

    return min(d1, min(d2,d3));
}


int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int c = 1; c <= t; ++c) {
        string s;
        cin >> s;

        string f;
        cin >> f;

        fav.clear();

        for(auto ch: f) {
            int pos = ch - 'a';
            //cout << pos << '\n';
            fav.insert(pos);
        }

        ll ans = 0;
        for(auto ch: s) {
            int pos = ch - 'a';
            //cout << pos << '\n';

            int localMin = 1e9;

            for(auto f2: fav) {
                localMin = min(localMin, minDist(pos, f2));
            }
            ans += localMin;

            /*
            auto nxt = fav.upper_bound(pos);
            //cout <<"next: " << *nxt << '\n';

            if(nxt == fav.begin()) {
                ans += min(minDist(pos, *fav.rbegin()), minDist(pos, *nxt));
            } else if(nxt == fav.end()) {
                ans += min(minDist(pos, *fav.rbegin()), minDist(pos, *fav.begin()));
            } else {

                ans += min(minDist(pos, *nxt), minDist(pos,*(--nxt)));
            }
            //cout << ans - prev << '\n';
            */
        }
        cout << "Case #" << c << ": " << ans << '\n';
    }







}