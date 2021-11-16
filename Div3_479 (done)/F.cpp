#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
Use a map dp to avoid having to search all previous, since we are only looking
for consecutive not all ascending.

I thought there would be a edge case that would fail for this implementation, 
but there is a work around. Once again the consecutive requirement simplifies the
implementation because we know what the next number we are looking for is. It 
is simply the decremented number.
*/

int seq[200005];

map<int,int> dp;

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    int ans = 0;
    int lst = 0;

    for(int i = 0; i < n; ++i) {
        dp[seq[i]] = dp[seq[i] - 1] + 1;
        if(dp[seq[i]] > ans) {
            ans = dp[seq[i]];
            lst = seq[i];
        }
    }

    vector<int> res;

    for(int i = n-1; i >= 0; --i) {
        if(seq[i] == lst) {
            res.push_back(i);
            --lst;
        }
    }

    reverse(res.begin(), res.end());

    cout << ans << '\n';
    for(auto it: res) {
        cout << it + 1 << " ";
    }
    cout << '\n';
}