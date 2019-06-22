#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int> > &grid)
    {
        if (grid[0][0] != 0){
            return -1;
        }
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int> > q;
        vector<vector<int>> distance(n, vector<int>(m, __INT_MAX__));

        distance[0][0] = 1;

        q.emplace(0, 0);

        while (!q.empty())
        {
            pair<int, int> point = q.front();
            q.pop();

            for (int i = 0; i < 8; i++)
            {

                if (point.first + move[i].first >= 0 && point.first + move[i].first < n &&
                    point.second + move[i].second >= 0 && point.second + move[i].second < m &&
                    grid[point.first + move[i].first][point.second + move[i].second] == 0 &&
                    distance[point.first + move[i].first][point.second + move[i].second] > distance[point.first][point.second] + 1)
                {
                    distance[point.first + move[i].first][point.second + move[i].second] = distance[point.first][point.second] + 1;
                    q.emplace(point.first + move[i].first, point.second + move[i].second);

                    if (point.first + move[i].first == n - 1 && point.second + move[i].second == m-1){
                        break;
                    }
                }
            }
        }

        if (distance[n - 1][m - 1] != __INT_MAX__){
            return distance[n - 1][m - 1];
        }
        else
        {
            return -1;
        }

    }

    const vector<pair<int, int>> move = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1}};
};

int main() {
    cout << "hello" << endl;
}