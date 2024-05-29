#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
#define loop(n) for(int i = 0; i < n; i++)
#define pii pair<int, int>

int n,m;
int answer=0;
vector<vector<char>> grid(1005,vector<char>(1005));
vector<vector<int>> visited(1005,vector<int>(1005));
 
int neighborX[4]={0,0,1,-1};
int neighborY[4]={1,-1,0,0};
 
bool isValid(int x,int y){
    if(y<0 || x<0 || x>=n ||y>=m){
        return false;
    }
    else if(grid[x][y] == '#'){
        return false;
    }
    return true;
}
 
void dfs(int x,int y){
    visited[x][y]=1;
    loop(4){
        int dx = x+neighborX[i];
        int dy = y+neighborY[i];
        if(isValid(dx,dy)){
            if(!visited[dx][dy]){
                dfs(dx,dy);
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
      }
    }
 
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == '.' && !visited[i][j]) {
          dfs(i, j);
          answer++;
        }
      }
    }
    cout << answer << endl;
    return 0;
