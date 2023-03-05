//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

using namespace std;
string str;
enum type {
    upper, lower, digit
};

int w, s;
vector<int> code;

void encode() {
    type t = upper;
    vector<int> res;
    for (int i = 0; i < str.size(); ++i) {
        if (isupper(str[i])) {
            if (t == upper) {

            } else if (t == lower) {
                // 目前是小写模式，先转到数字模式，再转到大写模式
                res.push_back(28);
                res.push_back(28);
                t = upper;
            } else {
                res.push_back(28);
                t = upper;
            }
            res.push_back(str[i] - 'A');
        } else if (islower(str[i])) {
            if (t == upper) {
                // 大写模式转小写模式
                res.push_back(27);
                t = lower;
            } else if (t == digit) {
                res.push_back(27);
                t = lower;
            }
            res.push_back(str[i] - 'a');

        } else if (isdigit(str[i])) {
            if (t == upper) {
                // 大写模式转小写模式
                res.push_back(28);
                t = digit;
            } else if (t == lower) {
                res.push_back(28);
                t = digit;
            }
            res.push_back(str[i] - '0');
        }
    }
    int sz = res.size();
    if (sz % 2 == 1) {
        res.push_back(29);
    }

    for (int i = 0; i < res.size(); i += 2) {
        code.push_back(res[i] * 30 + res[i + 1]);
    }
    sz = code.size();
    int pd = 0;
    int len = (sz + 1);
    if ((sz + 1) % w != 0) {
        pd = w - (sz + 1) % w;
        len += pd;
    }
    //cout << len << endl;
    code.insert(code.begin(), len);
    for (int i = 0; i < pd; ++i) {
//        cout << 900 << endl;
        code.push_back(900);
    }
    for (int i = 0; i < code.size(); ++i) {
        cout << code[i] << endl;
    }

}

void checksum() {
    int k = pow(2, s + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> s;

    cin >> str;
    encode();
    if (s != -1) {
        checksum();
    }
    return 0;
}
