#include <iostream>
#include <climits>
using namespace std;

int n = 4;
int dist[10][10] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};

int visited[10];

int tsp(int city, int count, int cost) {
    if (count == n && dist[city][0]) {
        return cost + dist[city][0];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[city][i]) {
            visited[i] = 1;
            ans = min(ans, tsp(i, count + 1, cost + dist[city][i]));
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    visited[0] = 1;
    cout << "Minimum cost = " << tsp(0, 1, 0);
}