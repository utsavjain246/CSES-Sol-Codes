#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <cmath>
using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
#define pii pair<int, int>

int n,m;
vector<vector<char>> grid(1005,vector<char>(1005));
vector<vector<int>> visited(1005,vector<int>(1005));
vector<vector<int>> prevstep(1005, vector<int>(1005, -1));  // used for backtracking at the last 
pii st,ed;  // st = start, ed = end


int neighborX[4]={0,0,1,-1};
int neighborY[4]={1,-1,0,0};
string step = "RLDU";


bool isValid(int x,int y){
    if(y<0 || x<0 || x>=n ||y>=m){
        return false;
    }
    else if(grid[x][y] == '#'){
        return false;
    }
    return true;
}

// Gives TLE But Can take a good idea that how to use DFS to find the shortest path in a graph problem

// void dfs(int x,int y){
//     if(x == ed.first && y == ed.second){
//         if (best_path.empty() || path.size() < best_path.size()) {
//             best_path = path;
//         }
//         return;
//     }
//     visited[x][y]=1;
//     loop(4){
//         int dx = x+neighborX[i];
//         int dy = y+neighborY[i];
//         if(isValid(dx,dy)){
//             path.push_back(i);
//             if(!visited[dx][dy]){
//                 dfs(dx,dy);
//             }
//             path.pop_back();
//         }
//     }
//     visited[x][y]=0;
// }

void bfs(pii st) {
    queue<pii> q;
    q.push(st);
    visited[st.first][st.second] =1;
    while(!q.empty()){
        pii cl = q.front();
        q.pop();
        loop(4){
            int nx = cl.first + neighborX[i];
            int ny = cl.second + neighborY[i];
            pii v = make_pair(nx,ny);
            if (isValid(nx, ny) && !visited[nx][ny]) {
                q.push(v);
                visited[nx][ny] = 1;
                prevstep[nx][ny] = i; 
                if (nx == ed.first && ny == ed.second) return;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> grid[i][j];
            visited[i][j] = 0;
            if(grid[i][j] =='A') st  ={i,j};
            if(grid[i][j] =='B') ed ={i,j};
        }
    }

    bfs(st);

    if (visited[ed.first][ed.second]){
        cout << "YES" << endl;
        vector<int> steps;
        while (ed != st){
            int p = prevstep[ed.first][ed.second];
            steps.push_back(p);
            ed = make_pair(ed.first - neighborX[p], ed.second - neighborY[p]);
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (int c : steps){
            cout << step[c];
        }
    } else{
        cout<<"NO"<<endl;
    }
    return 0;
}
