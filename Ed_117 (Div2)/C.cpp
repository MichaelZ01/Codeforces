#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
Use binary search and arithmetic summation to find the largest sum
less than the ban amount. The code is a bit messy since I thought
it would be easier than trying to generalise the maths.
*/

ll sum(ll k) {
    return (1 + k ) * k  / 2; 
}

ll reversesum(ll i, ll k) {
    return (k-1 + i) * (k-i) / 2;
}

bool f(ll i, ll x) {
    return sum(i) < x;
}

// Find the largest X such that f(X) is true;
// Uses arithmetic summation to find the largest x that can be sent without
// being banned
ll binarysearch(ll x, int k) {
    ll lo = 0;
    ll hi = k;
    ll bestSoFar = -1;
    // Range [lo, hi];
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (f(mid, x)) {
            bestSoFar = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return bestSoFar;
}

bool f2(ll i, ll x, ll k) {

    return reversesum(i, k)  < x;

}

// Find the smallest X such that f(X) is true;
// Reverses the arithmetic progression in the second half of the triangle
ll binarysearch2(ll x, int k) {
    ll lo = 0;
    ll hi = k;
    ll bestSoFar = -1;
    // Range [lo, hi];
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (f2(mid, x, k)) {
            bestSoFar = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;            

        }
    }
    return bestSoFar;
}

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int t;
    cin >> t;

    for(int c = 0; c < t; ++c) {
        ll k, x;
        cin >> k >> x;

        // Full triangle
        if(sum(k) + sum(k-1)  <= x) {
            cout << 2*k - 1 << '\n';
            continue;
        }

        ll posted = 0;
        bool firstHalf = true;

        // Second half of triangle
        if(x > sum(k)) {
            posted = k;
            x -= sum(k);
            firstHalf = false;
        }

        if(firstHalf) {
            posted = binarysearch(x, k) + 1;
        } else {
            ll second = k - binarysearch2(x, k);
            posted += second + 1;
        }

        cout << posted << '\n';
    }
}