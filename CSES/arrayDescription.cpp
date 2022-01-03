#include <iostream>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*

*/

int nums[100005];

ll dp[100005][105]; // How many numbers / value of previous number


int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if(nums[0] != 0) {
        dp[0][nums[0]] = 1;
    } else {
        for(int i = 1; i <= m; ++i) {
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(nums[i] != 0) {
            dp[i][nums[i]] = dp[i-1][nums[i]-1] + dp[i-1][nums[i]] + 
                dp[i-1][nums[i] + 1];
            dp[i][nums[i]] %= MOD;
        } else {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }        

        }
    }
    ll numArrays = 0;
    for(int i = 0 ; i <= m; ++i) {
        numArrays =  madd(numArrays, dp[n-1][i]);
    }

    cout << numArrays << '\n';

}