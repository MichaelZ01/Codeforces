#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Patterns:
00
25
50
75
*/


int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int cc = 0; cc < t; ++cc) {

        ll n;
        cin >> n;

        // 00 25 50 75
        set<int> seen;

        int steps = 0;
        while(n >  0) {
            int d = n % 10;
            n /= 10;
            ++steps;

            if(d == 0 && seen.count(0) != 0) {
                // 00
                break;
            } 
            if(d == 2 && seen.count(5) != 0) {
                // 25
                break;
            }
            if(d == 5 && seen.count(0) != 0) {
                //50
                break;
            }
            if(d == 7 && seen.count(5) != 0) {
                //75
                break;
            }
            seen.insert(d);
        }
        steps -= 2;

        cout << steps << '\n';
    }
}