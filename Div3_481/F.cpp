#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

int skill[200005];
int orderedSkill[200005];
int quarreling[200005];

int n, k;

/*
Using a version of binarysearch learnt in lectures. Apparently this version
is good at catching off-by one errors but I need to modify the numbers 
everytime I use it so I'm not sure if that actually introduces errors
*/


bool canDo(int i, int skill) {
    return skill > orderedSkill[i];
}

// Finds the largest number that is larger than skill
int binarysearch(function<bool(int, int)> f, int skill) {
    int lo = 1;
    int hi = n;
    int bestSoFar = 0;
    // Range [lo, hi];
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (f(mid, skill)) {
            bestSoFar = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return bestSoFar;
}

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);


    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> skill[i];
        orderedSkill[i] = skill[i];
    }

    for(int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;

        if(skill[x] > skill[y]) {
            ++quarreling[x];
        } else if(skill[y] > skill[x]) {
            ++quarreling[y];
        }
    }

    sort(orderedSkill + 1, orderedSkill + n + 1);

    for(int i = 1; i <= n; ++i) {
        cout << binarysearch(&canDo, skill[i]) - quarreling[i] << ' ';
    }
    cout << '\n';

}