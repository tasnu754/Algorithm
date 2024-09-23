#include <bits/stdc++.h>

using namespace std;

const int N = 8; // Size of the chessboard
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> d = {{-2,1},{-2,-1},{2,1},{2,-1}, {-1,2}, {1,2}, {-1,-2}, {1,-2}};

bool isInvalid(int i, int j) {
    return (i < 0 || i >= N || j < 0 || j >= N);
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;

        for (auto& move : d) {
            int ci = pi + move.first;
            int cj = pj + move.second;

            if (!isInvalid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                dis[ci][cj] = dis[pi][pj] + 1;
                vis[ci][cj] = true;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;

        bfs(si, sj);

        cout << dis[di][dj] << endl;
    }

    return 0;
}
