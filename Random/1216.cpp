#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*

*/

ll floor(ll n) {
    return max(n, 0LL);
}

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;
    ll x5, y5, x6, y6;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    ll totalArea = (y2 - y1) * (x2 - x1);

    ll blackArea1 = floor(min(y2,y4) - max(y1,y3)) * floor(min(x2,x4) - max(x1,x3));
    ll blackArea2 = floor(min(y2,y6) - max(y1,y5)) * floor(min(x2,x6) - max(x1,x5));

    ll blackOverlap = floor(min(min(y2,y4),y6) - max(max(y1, y3), y5)) * floor(min(min(x2,x4), x6) - max(max(x1,x3), x5));
    if(blackArea1 < 0) blackArea1 = 0;
    if(blackArea2 < 0) blackArea2 = 0;
    if(blackOverlap < 0) blackOverlap = 0;

    if(totalArea - blackArea1 - blackArea2 + blackOverlap > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}