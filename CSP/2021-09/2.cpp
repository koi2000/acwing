#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> diff;
    map<int, vector<int>> numPos;
    vector<int> num;
    num.push_back(0);
    int tp;
    for (int i = 1; i <= n; ++i) {
        cin >> tp;
        num.push_back(tp);
        diff.insert(tp);
        numPos[tp].push_back(i);
    }
    num.push_back(0);
    int maxnum = 0;
    for (int i = 1; i < num.size(); ++i) {
        if (num[i] != 0 && num[i + 1] == 0) {
            maxnum++;
        }
    }
    int nn = maxnum;
    for (auto number:diff) {
        if (number == 0) {
            continue;
        }
        for (int i = 0; i < numPos[number].size(); ++i) {
            int idx = numPos[number][i];
            int end = idx;
            if (num[idx] == 0) {
                continue;
            }
            while (num[end] == number) {
                num[end] = 0;
                end++;
            }
            end--;
            if (num[idx - 1] == 0 && num[end + 1] == 0) {
                nn--;
            }
            if (num[idx - 1] != 0 && num[end + 1] != 0) {
                nn++;
            }
        }
        maxnum = max(nn, maxnum);
    }
    cout << maxnum << endl;
    return 0;
}
