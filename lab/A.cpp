#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#include <random>
#include <stdexcept>

using namespace std;

struct segment {
    int index1, index2;
    double border;

    segment(int index1, int index2, double border)
            : index1(index1), index2(index2), border(border) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis;

    int n, q;
    cin >> n >> q;
    vector<int> sticks(n);
    int sum = 0;
    for (auto &el : sticks) {
        cin >> el;
        sum += el;
    }
    double avg = sum / (double) n;

    vector<pair<double, int>> less, greater;
    for (size_t i = 0; i < sticks.size(); i++) {
        double val = sticks[i];
        (val < avg ? less : greater).emplace_back(val, i + 1);
    }

    vector<segment> segments;

    size_t i1 = 0, i2 = 0;
    while (i1 < less.size() || i2 < greater.size()) {
        if (i1 == less.size() || i2 == greater.size()) {
            auto &s = i1 == less.size() ? greater[i2++] : less[i1++];
            segments.emplace_back(s.second, s.second, s.first / avg);
            continue;
        }
        auto &g = greater[i2];
        auto &l = less[i1];
        segments.emplace_back(l.second, g.second, l.first / avg);
        g.first -= (avg - l.first);
        if (g.first < avg) {
            swap(l, g);
            i2++;
        } else {
            i1++;
        }
    }

    for (size_t i = 0; i < q; i++) {
        double val = dis(gen);
        double dpos = val * segments.size();
        int pos = (int) dpos;
        cout << (dpos - pos < segments[pos].border ? segments[pos].index1 : segments[pos].index2) << " ";
    }

    return 0;
}
