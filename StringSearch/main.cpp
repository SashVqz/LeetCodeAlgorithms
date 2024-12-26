#include <iostream>
#include <string>
using namespace std;

int stringSearch(const string& str, const string& pattern) {
    int n = str.length();
    int m = pattern.length();
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (str[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) return i; 
    }
    return -1;
}

int main() {
    string str, pattern;
    cin >> str >> pattern;

    int result = stringSearch(str, pattern);
    cout << result << endl;
    return 0;
}