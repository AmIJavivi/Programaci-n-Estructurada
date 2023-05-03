#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void updateLavaLevel(int& lavaLevel, bool& lavaRising) {
    if (lavaRising) {
        lavaLevel++;
        if (lavaLevel == 5) {
            lavaRising = false;
        }
    } else {
        lavaLevel--;
        if (lavaLevel == 0) {
            lavaRising = true;
        }
    }
}

struct Node {
    int x, y, dist;
    Node(int x_, int y_, int dist_) : x(x_), y(y_), dist(dist_) {}
};

int escapeVolcano(vector<vector<int>>& volcanoMap) {
    const int n = volcanoMap.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    queue<Node> q;
    q.push(Node(0, 0, 0));

    int lavaLevel = 0;
    bool lavaRising = true;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.x == n - 1 && curr.y == n - 1) {
            return curr.dist;
        }

        if (volcanoMap[curr.x][curr.y] < lavaLevel) {
            continue;
        }

        visited[curr.x][curr.y] = true;

        if (curr.x > 0 && !visited[curr.x - 1][curr.y] && volcanoMap[curr.x - 1][curr.y] >= lavaLevel) {
            q.push(Node(curr.x - 1, curr.y, curr.dist + 1));
        }

        if (curr.x < n - 1 && !visited[curr.x + 1][curr.y] && volcanoMap[curr.x + 1][curr.y] >= lavaLevel) {
            q.push(Node(curr.x + 1, curr.y, curr.dist + 1));
        }

        if (curr.y > 0 && !visited[curr.x][curr.y - 1] && volcanoMap[curr.x][curr.y - 1] >= lavaLevel) {
            q.push(Node(curr.x, curr.y - 1, curr.dist + 1));
        }

        if (curr.y < n - 1 && !visited[curr.x][curr.y + 1] && volcanoMap[curr.x][curr.y + 1] >= lavaLevel) {
            q.push(Node(curr.x, curr.y + 1, curr.dist + 1));
        }

        updateLavaLevel(lavaLevel, lavaRising);
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> volcanoMap(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> volcanoMap[i][j];
        }
    }

    int shortestTime = escapeVolcano(volcanoMap);

    if (shortestTime == -1) {
        cout<<"-1"<<endl;
        }else{
            cout<<shortestTime<<endl;
        }
    system("pause");
    return 0;
}