#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <cmath>

using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
vector <vector<int>> graph(100001);
int vis[100001];

void dfs(int st){
    vis[st]=1;
    for(int ch:graph[st]){
        if(!vis[ch]){
            dfs(ch);
        }
    }
    return;
}


int main() {
    int n,m;
    cin>>n>>m;
    loop(m){
        int a,b;
        cin>> a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;
    vector<int> l;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            l.push_back(i);
            count++;
        }
    }

    cout << count - 1 << endl;

  // connect every components or road to 1st road
    for (int i = 1; i < count; i++) {
        cout << l[0] << " " << l[i] << endl;
    }
    return 0;
}
