#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(const vector<int>& set) {
    int n = set.size();
    
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cout << set[i] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> set(n);
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    generateSubsets(set);
    return 0;
}