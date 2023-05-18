#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 50;
const int MAXH = 6;
const int DX[4] = {0, 0, -1, 1};
const int DY[4] = {-1, 1, 0, 0};

int n;
int map[MAXN][MAXN];
int dist[MAXN][MAXN][MAXH];

bool is_valid(int x, int y, int h, int t) {
    if (h + t > MAXH) return false;
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (map[x][y] > h + t) return false;
    return true;
}

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < MAXH; k++) {
                dist[i][j][k] = INT_MAX;
            }
        }
    }
    dist[0][0][0] = 0;

    while (!q.empty()) {
        int x = get<0>(q.front()), y = get<1>(q.front()), h = get<2>(q.front());
        q.pop();
        if (x == n - 1 && y == n - 1) return dist[x][y][h];

        // Update time
        int t = (dist[x][y][h] + 1) % (MAXH * 2);
        if (t >= MAXH) {
            h--;
        } else {
            h++;
        }

        // Try moving to neighbors
        for (int i = 0; i < 4; i++) {
            int nx = x + DX[i], ny = y + DY[i];
            if (is_valid(nx, ny, h, t) && dist[x][y][h] + 1 < dist[nx][ny][h]) {
                dist[nx][ny][h] = dist[x][y][h] + 1;
                q.push(make_tuple(nx, ny, h));
            }
        }
    }

    return -1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int ans = bfs();
    cout << ans << endl;

    system("pause");
    return 0;
}
