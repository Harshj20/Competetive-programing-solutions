#include <iostream>
#include <string>
using namespace std;

int extractNumber(const string& str) {
    if (str.empty() || str[0] == '0') {
        return -1;  // Ignore numbers starting with zero or empty strings
    }
    try {
        return stoi(str);
    } catch (const std::invalid_argument& e) {
        return -1;  // Handle invalid argument exception
    }
}


int getMaxNumbersInRange(int n, const string& t, int k, int m) {
    int maxCount = 0;

    // Original string case
    int count = 0;
    for (int a = 0; a <= n - m; a++) {
        string substr = t.substr(a, k);
        int num = extractNumber(substr);
        if (num != -1) {
            count++;
        }
    }
    maxCount = max(maxCount, count);

    // Modified string cases
    for (int i = 0; i < n; i++) {
        string modified = t;
        modified[i] = '1';  // Modify the digit at position i to 1

        count = 0;
        for (int a = 0; a <= n - m; a++) {
            string substr = modified.substr(a, k);
            int num = extractNumber(substr);
            if (num != -1) {
                count++;
            }
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    int n, k, m;
    string t;

    int T;
    cin>>T;
    for(int test_case = 0; test_case < T; test_case++) {
        cin >> n >> k >> m;
        cin >> t;

        int maxNumbers = getMaxNumbersInRange(n, t, k, m);
        cout << "Maximum number of numbers in the range: " << maxNumbers << endl;
    }

    return 0;
}
