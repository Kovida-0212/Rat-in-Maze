#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
    if (x >= n || y >= n || arr[x][y] == 0 || arr[x][y] % 3 != 0) {
        return false;
    }
    return true;
}

bool agentMove(int** arr, int x, int y, int n, int** solArr, vector<pair<int, int>>& path) {
    solArr[x][y] = 1;

    if (x == n - 1 && y == n - 1) {
        path.push_back(make_pair(x, y));
        return true;
    }

    if (x + 1 < n && isSafe(arr, x + 1, y, n)) {
        if (agentMove(arr, x + 1, y, n, solArr, path)) {
            path.push_back(make_pair(x, y));
            return true;
        }
    }

    if (y + 1 < n && isSafe(arr, x, y + 1, n)) {
        if (agentMove(arr, x, y + 1, n, solArr, path)) {
            path.push_back(make_pair(x, y));
            return true;
        }
    }

    return false;
}

int findNearestLocation(int** solArr, int n) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == n - 1 && y == n - 1) {
            return abs(x) + abs(y);
        }

        if (x + 1 < n && solArr[x + 1][y] == 1 && !visited[x + 1][y]) {
            q.push({x + 1, y});
            visited[x + 1][y] = true;
        }

        if (y + 1 < n && solArr[x][y + 1] == 1 && !visited[x][y + 1]) {
            q.push({x, y + 1});
            visited[x][y + 1] = true;
        }
    }

    int nearestLocation = INT_MAX;
    int nearestPathDistance = INT_MAX;
    vector<pair<int, int>> nearestPath;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                int currentDistance = abs(i) + abs(j);
                if (nearestLocation > currentDistance) {
                    nearestLocation = i;
                    nearestPathDistance = currentDistance;
                    nearestPath.clear();
                }
                if (nearestPathDistance == currentDistance) {
                    nearestPath.push_back(make_pair(i, j));
                }
            }
        }
    }

    for (int i = 0; i < visited.size(); i++) {
        for (int j = 0; j < visited[0].size(); j++) {
            if (visited[i][j]) {
                solArr[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < nearestPath.size(); i++) {
        solArr[nearestPath[i].first][nearestPath[i].second] = 1;
    }

    return nearestPathDistance;
}

void printVisitedLocations(const vector<pair<int, int>>& path, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < path.size(); i++) {
        visited[path[i].first][path[i].second] = true;
    }

    cout << "\nVisited Cells:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (visited[i][j] ? "V " : ". ");
        }
        cout << endl;
    }
}

void findPathAndPrint(int** arr, int n) {
    vector<pair<int, int>> path;
    int** solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n]();
    }

    bool hasSolution = agentMove(arr, 0, 0, n, solArr, path);

    if (hasSolution) {
        cout << "\nTraces of the Agent's Path from Destination:" << endl;
        cout << "\nAgent's Traveled Path:" << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << "(" << path[i].first << ", " << path[i].second << ") ";
        }
        cout << endl;

        cout << "\nAgent's Path Symbol Codes:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solArr[i][j] == 1) {
                    cout << "#" << " ";
                } else {
                    cout << "X" << " ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "\nNo path to destination found." << endl;
        cout << "\nNearest Path to Destination:" << endl;
        int nearestPathDistance = findNearestLocation(solArr, n);
        cout << "\nDistance to nearest path: " << nearestPathDistance << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solArr[i][j] == 1) {
                    cout << "#" << " ";
                } else {
                    cout << "X" << " ";
                }
            }
            cout << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] solArr[i];
    }
    delete[] solArr;
}

int main() {
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    cout << "Enter the maze elements (0 for obstacles, any number for open paths):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int** solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n]();
    }

    vector<pair<int, int>> path;
    if (agentMove(arr, 0, 0, n, solArr, path)) {
        cout << "\nSolution:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solArr[i][j] == 1) cout << "Secure ";
                else cout << "Insecure ";
            }
            cout << endl;
        }

        cout << "\nBinary Codes:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << bitset<3>(solArr[i][j]) << " ";
            }
            cout << endl;
        }

        findPathAndPrint(arr, n);
        printVisitedLocations(path, n);
    } else {
        cout << "\nNo solution exists." << endl;
        findPathAndPrint(arr, n);
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;

    return 0;
}
