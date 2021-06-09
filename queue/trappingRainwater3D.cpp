//
// Created by Zeeshan Shaikh on 6/9/21.
//

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(int heightMap[3][6]) {
        rows = 3; columns = 6;
        vector<vector<bool>> seen(rows, vector<bool>(columns));
        for (int i = 0; i < rows; i++) {
            pq.push({heightMap[i][0], i * columns});
            pq.push({heightMap[i][columns - 1], i * columns + columns - 1});
        }
        for (int j = 1; j < columns - 1; j++) {
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[rows - 1][j], (rows - 1) * columns + j});
        }
        int res = 0;
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            dfs(p.second / columns, p.second % columns, p.first, heightMap, seen, res);
        }
        return res;
    }

private:
    int rows, columns;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    void dfs(int row, int column, int value, int heightMap[3][6], vector<vector<bool>>& seen, int& output) {
        seen[row][column] = true;
        if (heightMap[row][column] > value) {
            pq.push({heightMap[row][column], row * columns + column});
            return;
        }

        output += value - heightMap[row][column];

        // Checking rows
        if (row > 0 && !seen[row - 1][column]){
            dfs(row - 1, column, value, heightMap, seen, output);
        }
        if (row < rows - 1 && !seen[row + 1][column]){
            dfs(row + 1, column, value, heightMap, seen, output);
        }
        // Checking columns
        if (column > 0 && !seen[row][column - 1]){
            dfs(row, column - 1, value, heightMap, seen, output);
        }
        if (column < columns - 1 && !seen[row][column + 1]){
            dfs(row, column + 1, value, heightMap, seen, output);
        }
    }
};

int main(){
    // Defining the array here
    int heightMap[3][6] = {1,4,3,1,3,2,3,2,1,3,2,4,2,3,3,2,3,1};

    Solution S;
    int output = S.trapRainWater(heightMap);

    cout << "The total amount of water possible to be trapped in this grid is: " << output << endl;
}