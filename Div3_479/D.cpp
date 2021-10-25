#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
Numbers must be unique as you / 3 will never be equal to * 2

All numbers will have 1 edge, except the last number which will have 0.
*/

typedef long long ll;

set<ll> nums;
set<ll> midNums;
ll ans[105];
map<ll,ll> nextNum;

ll last;

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        ll elem;
        cin >> elem;
        nums.insert(elem);
    }

    for(auto num : nums) {
        if(nums.count(num / 3) != 0 and num % 3 == 0) {
            nextNum[num] = num/3;
            midNums.insert(num/3);
        } else if(nums.count(num * 2) != 0) {
            nextNum[num] = num * 2;
            midNums.insert(num * 2);
        } 

        if(nums.count(num * 3) == 0 and (nums.count(num / 2) == 0 or num % 2 != 0)) {
            last = num;
        }
    }

    for(int i = 0; i < n; ++ i ){
        cout << last << " ";
        last = nextNum[last];
    }

    cout << '\n';
}