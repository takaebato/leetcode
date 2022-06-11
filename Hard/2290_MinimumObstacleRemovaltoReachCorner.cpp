#include <bits/stdc++.h>
using namespace std;

/*
  01BFS or ダイクストラ.
  m,n<=10^5だが、m*n(=|V|)<=10^5の制約もあるから探索できる.
  グリッドグラフだから、|E|=|V|*2とかでだいぶ疎。
  01BFS: |E|+|V|
  ダイクストラ(Heap)): |V|+|E|log|V|
*/

// 01BFS
class Solution {
   public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));
        dist[0][0] = 0;
        deque<pair<int, int>> que;
        que.emplace_front(0, 0);

        int h[4] = {0, -1, 0, 1};
        int v[4] = {-1, 0, 1, 0};

        while (!que.empty()) {
            int y = que.front().first;
            int x = que.front().second;
            que.pop_front();

            for (int i = 0; i < 4; i++) {
                int ny = y + v[i];
                int nx = x + h[i];
                if (ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size()) continue;
                if (dist[ny][nx] != -1) continue;

                if (grid[ny][nx] == 0) {
                    dist[ny][nx] = dist[y][x];
                    que.emplace_front(ny, nx);
                } else if (grid[ny][nx] == 1) {
                    dist[ny][nx] = dist[y][x] + 1;
                    que.emplace_back(ny, nx);
                }
            }
        }
        return dist[grid.size() - 1][grid[0].size() - 1];
    }
};

// ダイクストラ(Heap)
class Solution {
   public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
        que.emplace(0, 0, 0);

        int h[4] = {0, -1, 0, 1};
        int v[4] = {-1, 0, 1, 0};

        while (!que.empty()) {
            int d = get<0>(que.top());
            int y = get<1>(que.top());
            int x = get<2>(que.top());
            que.pop();

            if (d > dist[y][x]) continue;

            for (int i = 0; i < 4; i++) {
                int ny = y + v[i];
                int nx = x + h[i];
                if (ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size()) continue;

                if (dist[ny][nx] > dist[y][x] + grid[ny][nx]) {
                    dist[ny][nx] = dist[y][x] + grid[ny][nx];
                    que.emplace(dist[ny][nx], ny, nx);
                }
            }
        }
        return dist[grid.size() - 1][grid[0].size() - 1];
    }
};
