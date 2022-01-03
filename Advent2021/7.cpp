#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*

*/

int pos[1005];

ll getCost(int x, int y) {
    int n = abs(x - y);

    return n * (1 + n) / 2;
}

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    string input;
    cin >> input;

    int start = 0;
    int end = input.find(",");
    int index = 0;
    string val;
    //cout << input << " " << "end: " << end << '\n';
    while(end != -1) {
        val = input.substr(start, end - start);
        pos[index] = stoi(val);

        start = end + 1;
        end = input.find(",", start);
        ++index;
    }
    val = input.substr(start, end - start);
    pos[index] = stoi(val); 
    ++index;
    /*

    for(int i = 0; i < index; ++i) {
        cout << pos[i] << '\n';
    }
    
    */

    sort(pos, pos + index);

    ll minCost = 1e9;
    ll curCost;

    for(int i = pos[0]; i <= pos[index-1]; ++i) {
        curCost = 0;
        for(int j = 0; j < index; ++j) {
            //curCost += abs(pos[j] - i);
            curCost += getCost(pos[j], i);
        }
        minCost = min(minCost, curCost);
    }


    cout << index << '\n';
    cout << minCost << '\n';


}