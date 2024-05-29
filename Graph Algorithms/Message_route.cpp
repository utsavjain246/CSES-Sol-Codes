#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <cmath>
using namespace std;

#define loop(n) for(int i = 0; i < n; i++)

vector<vector<int>> graph(100001);
int vis[100001];
int prevNode[100001];

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int ch : graph[v]) {
            if (!vis[ch]) {
                vis[ch] = 1;
                prevNode[ch] = v;
                q.push(ch);
                if (ch == n) return;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    loop(m) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill(prevNode, prevNode + n +1, -1);

    bfs(1, n);

    if (prevNode[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int at = n; at != -1; at = prevNode[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
