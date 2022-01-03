#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

#define MOD 100000007

ll madd(ll a, ll b) { return ((a+b) % MOD + MOD) % MOD; }

/*
1: 17
2: 34
    5: a, c, d, e, g
3: 39
    5: a, c, d, f, g
4: 30
5: 37
    5: a, b, d, f, g
6: 41
    6: a, b, d, e, f, g (c)
7: 25
8: 49
9: 45
    6: a, b, c, d, f, g (e)
0: 42
    6: a, b, c, e, f, g (d)

a : 8
b : 6
c : 8
d : 7
e : 4
f : 9
g : 7

Known:
1(unique), 4(unique), 7(unique), 

*/

string digits[15];


int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    string in;
    ll count = 0;
    while(cin >> in) {
        map<char, int> wires;
        for(int i = 0; i < 10; ++i) {
            digits[i] = in;
            
            for(auto d : digits[i]) wires[d] += 1;
            cin >> in;
        }

        // Divider

        // Calc mappings
        // 1, 4, 7, 8, 3 (has 1), 6 (does not have 1/2),  


        string text;
        int value = 0;
        for(int i = 0; i < 4; ++i) {
            cin >> text;
            value *= 10;
            if(text.size() == 2) {
                value += 1;
            } else if (text.size() == 4) {
                value += 4;
            } else if (text.size() == 3) {
                value += 7;
            } else if(text.size() == 7) {
                value += 8;
            } else {
                int digitValue = 0;
                for(auto d: text) {
                    digitValue += wires[d];
                }

                switch (digitValue)
                {
                case 34:
                    value += 2;
                    break;
                case 39:
                    value += 3;
                    break;
                case 37:
                    value += 5;
                    break;
                case 41:
                    value += 6;
                    break;
                case 45:
                    value += 9;
                    break;
                default:
                    break;
                }

            }
        }
        count += value;
    }
    cout << count << '\n';
}