#include <iostream>

using namespace std;

int main() {
    int n, i, j, adjacency[10][10], visited[10], distance[10], source, k, min, a;

    cout << "Enter the number of vertices" << endl;
    cin >> n;

    cout << "Enter the cost matrix" << endl;
    cout << "Enter 999 if no edge between vertices" << endl;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> adjacency[i][j];

    cout << "Enter the source vertex" << endl;
    cin >> source;

    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        distance[i] = adjacency[source][i];
    }
    distance[source] = 0;
    visited[source] = 1;

    for (k = 2; k <= n; k++) {
        min = 999;

        for (i = 1; i <= n; i++)
            if (visited[i] == 0 && distance[i] < min) {
                min = distance[i];
                a = i;
            }

        visited[a] = 1;

        for (i = 1; i <= n; i++)
            if (visited[i] == 0) {
                if (distance[i] > (distance[a] + adjacency[a][i]))
                    distance[i] = distance[a] + adjacency[a][i];
            }
    }

    cout << "The shortest distance from " << source << " is" << endl;
    for (i = 1; i <= n; i++)
        cout << source << "-->" << i << "=" << distance[i] << endl;

    return 0;
}
