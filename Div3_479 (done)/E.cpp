#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
I keep misreading the bounds as just 1*10^5
*/

typedef long long ll;

vector<int> g[200005];
bool visited[200005];

bool isCycle(int u) {
    if(visited[u]) return false;

    if(g[u].size() != 2) return false;

    int prev = g[u][0];
    auto q = queue<int>({u});

    while(q.size()) {
        int cur = q.front();
        q.pop();

        if(g[cur].size() != 2) return false;

        visited[cur] = true;
        for(auto e : g[cur]) {
            if(e == prev) continue;
            if(e == u) {
                return true;
            } else if (!visited[e]) {
                q.push(e);
            }
        }
        prev = cur;
    }
    return false;
}

int main() {
    cin.tie(nullptr); cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int v, u;
    for(int i = 0; i < m; ++i) {
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int cycles = 0;
    for(int i = 1; i <= n; ++i) {
        if(isCycle(i)) ++cycles;
    }

    cout << cycles << '\n';
}