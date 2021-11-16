#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    while(k > 0) {
        if(n % 10 != 0) {
            n -= 1;
        } else {
            n /= 10;
        }
        --k;
    }

    cout << n << '\n';
} 