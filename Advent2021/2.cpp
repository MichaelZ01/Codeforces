#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Day 2: Dive!
*/

string instr[1005];
int mag[1005];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    for(int i = 0; i < 1000; ++i) {
        cin >> instr[i];
        cin >> mag[i];
    }

    ll depth = 0;
    ll pos = 0;
    ll aim = 0;

    // Just brute force it
    for(int i = 0; i < 1000; ++i) {

        if(instr[i] == "forward") {
            pos += mag[i];
            depth += aim * mag[i];
        } else if(instr[i] == "down") {
            aim += mag[i];
        } else {
            aim -= mag[i];
        }
    }

    cout << depth * pos << '\n';
}