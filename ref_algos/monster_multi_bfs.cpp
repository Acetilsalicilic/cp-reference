#include <vector>
#include <queue>
#include <climits>
#include <string>
using namespace std;
void multi_bfs(vector<pair<int, int>> const& monsters, 
        vector<string> const& grid,
        int r, int c)
{
    // Monster multisource BFS
    queue<pair<int, int>> next;
    vector<vector<int>> m_dist(r, vector<int>(c, INT_MAX - 1));
    for (auto m : monsters) {
        next.push(m);
        m_dist[m.second][m.first] = 0;
    }

    while (!next.empty()) {
        auto [x, y] = next.front();
        next.pop();
        //printf("On %d %d\n", x, y);

        for (auto [nx, ny] : vector<pair<int, int>>{{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}}) {
            if (nx < 0 || ny < 0 || nx >= c || ny >= r)
                continue;
            if (grid[ny][nx] == '#')
                continue;
            if (m_dist[y][x] + 1 < m_dist[ny][nx]) {
                //printf("Is better %d than %d on %d %d\n", m_dist[y][x] + 1, m_dist[ny][nx], nx, ny);
                m_dist[ny][nx] = m_dist[y][x] + 1;
                next.push({nx, ny});
            }
        }
    }
}
