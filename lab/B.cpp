#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <cstdint>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#include <random>
#include <cassert>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <stdexcept>

using namespace std;

double const X = 2.6491586832;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double eps;
    cin >> eps;
    int q = (int) floor(X / (eps * eps));
    int cnt_one = 0;
    for (int i = 0; i < q; i++) {
        cout << -1 << endl;
        int a;
        cin >> a;
        cnt_one += a;
    }

    cout << (cnt_one * 1.) / q << endl;

    return 0;
}
