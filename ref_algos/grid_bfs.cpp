#include <vector>
#include <queue>
#include <climits>
using namespace std;
void grid_bfs(pair<int, int> start, int r, int c)
{
    queue<pair<int, int>> next;
    next.push(start);
    vector<vector<int>> p_dist(r, vector<int>(c, INT_MAX - 1));
    p_dist[start.second][start.first] = 0;
    bool can = false;
    pair<int, int> ending;

    while (!next.empty()) {
        auto [x, y] = next.front();
        next.pop();
        //printf("On %d %d\n", x, y);
        //printf("Comparing %d on monsters with %d\n", m_dist[y][x], p_dist[y][x]);

        if (m_dist[y][x] <= p_dist[y][x]) {
            //printf("Exiting\n");
            continue;
        }

        if (x == 0 || y == 0 || x == c - 1 || y == r - 1) {
            //printf("Reached border\n");
            can = true;
            ending = {x, y};
            goto _end; // or something
        }
        for (auto [nx, ny] : vector<pair<int, int>>{{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}}) {
            if (nx < 0 || ny < 0 || nx >= c || ny >= r)
                continue;
            if (grid[ny][nx] == '#')
                continue;
            if (p_dist[ny][nx] < p_dist[y][x] + 1)
                continue;
            p_dist[ny][nx] = p_dist[y][x] + 1;
            next.push({nx, ny});
        }
    }
}
