#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Day 1: Sonar Sweep
*/

int depth[5000];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int i = 0;
    int d;
    while(cin >> d) {
        depth[i++] = d;
    }
    int count = 0;
    for(int i = 3; i < 2000; ++i) {
        int a = depth[i-3] + depth[i-2] + depth[i-1];
        int a2 = depth[i-2] + depth[i-1] + depth[i];

        if(a2 > a) {
            ++count;
        }
    }

    cout << count << '\n';
}