#include <iostream>
#include <algorithm>

/*
Made a lot of mistakes with this question. With reading the questions or the 
edge cases. I was quite tired at this time but...
*/

using namespace std;

typedef long long ll;

int seq[200005];

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    sort(seq, seq+n);

    if(k == 0) {
        if(seq[0] > 1) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    } else if(k == n) {
        cout << seq[k-1] << '\n';
    } else if(seq[k-1] == seq[k]) {
        cout << "-1\n";
    } else {
        cout << seq[k-1] << '\n';
    }
}