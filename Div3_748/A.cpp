#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

int winner;
bool multiWinner;

int printCand(int a) {
    if(a != winner) {
        a = winner - a + 1;
    } else {
        if(multiWinner) {
            a = 1;
        } else {
            a = 0;
        }
    }

    return a;
}


int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int cc = 0; cc < t; ++cc) {
        int a, b, c;
        cin >> a >> b >> c;
        winner = max(max(a,b),c);
        multiWinner = false;
        int winners = 0;
        if(a == winner) ++winners;
        if(b == winner) ++winners;
        if(c == winner) ++winners;

        multiWinner = (winners > 1);
      
        cout << printCand(a) << " " << printCand(b) << " " << printCand(c) << "\n";
    }
}