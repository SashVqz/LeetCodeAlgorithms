#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int calculateTotalDistance(const vector<vector<int>>& dist, const vector<int>& path) {
    int total = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        total += dist[path[i]][path[i + 1]];
    }
    total += dist[path[path.size() - 1]][path[0]]; 
    return total;
}

int travelingSalesman(const vector<vector<int>>& dist, int n) {
    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }
    
    int minDistance = INT_MAX;
    do {
        int currDistance = calculateTotalDistance(dist, cities);
        minDistance = min(minDistance, currDistance);
    } while (next_permutation(cities.begin() + 1, cities.end())); 
    
    return minDistance;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int result = travelingSalesman(dist, n);
    cout << result << endl;
    return 0;
}