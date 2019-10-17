#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<pair<int,int>> v;
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            v.emplace_back(i, j);
        }
    }
    cout << v.size() << '\n';
    for (auto &i : v) cout << i.first << ' ' << i.second << '\n';
    return 0;
}
