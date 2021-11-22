#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Questions asks for a point half way between origin and (x,y) using
manhattan distance
*/
int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int c = 0; c < t; ++c) {
        int x, y;
        cin >> x >> y;

        
        if((x + y) % 2 != 0) {
            cout << "-1 -1\n";
            continue;
        }

        int dif = ((x + y) / 2);

        if(x > 1e6) {
            dif -= (x - 1e6);
            x = 1e6;
        }
        if(y > 1e6) {
            dif -= (y - 1e6);
            x = 1e6;
        }

        if(x > dif) {
            x -= dif;
        } else if (y > dif) {
            y -= dif;
        } else {
            dif -= x;
            x = 0;
            y -= dif;
        }

        cout << x << " " << y << '\n';
    }
}