class Solution {
public:
    // this function will mark all cells seen by one guard
    void counter(vector<vector<char>> &visited, int i, int j) {
        int m = visited.size();
        int n = visited[0].size();

        // up
        for (int x = i - 1; x >= 0; x--) {
            if (visited[x][j] == 'W' || visited[x][j] == 'G') break;
            if (visited[x][j] == 'F') visited[x][j] = 'T';
        }

        // down
        for (int x = i + 1; x < m; x++) {
            if (visited[x][j] == 'W' || visited[x][j] == 'G') break;
            if (visited[x][j] == 'F') visited[x][j] = 'T';
        }

        // left
        for (int y = j - 1; y >= 0; y--) {
            if (visited[i][y] == 'W' || visited[i][y] == 'G') break;
            if (visited[i][y] == 'F') visited[i][y] = 'T';
        }

        // right
        for (int y = j + 1; y < n; y++) {
            if (visited[i][y] == 'W' || visited[i][y] == 'G') break;
            if (visited[i][y] == 'F') visited[i][y] = 'T';
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> visited(m, vector<char>(n, 'F'));

        // mark guards and walls
        for (auto &pos : guards) visited[pos[0]][pos[1]] = 'G';
        for (auto &pos : walls) visited[pos[0]][pos[1]] = 'W';

        // call counter for every guard
        for (auto &pos : guards) {
            int i = pos[0], j = pos[1];
            counter(visited, i, j);
        }

        // count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j] == 'F') unguarded++;

        return unguarded;
    }
};
