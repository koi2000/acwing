#include<bits/stdc++.h>

using namespace std;
stack<int> num;
stack<int> op;

void eval() {
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    int x;
    if (c == '+') x = a + b;
    else if (c == '-') x = a - b;
    else if (c == '*') x = a * b;
    else x = a / b;
    num.push(x);
}

int main() {
    map<char, int> pr{{'+', 1},
                      {'-', 1},
                      {'*', 2},
                      {'/', 2}};
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        auto c = str[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j])) {
                x = x * 10 + str[j++] - '0';
            }
            i = j - 1;
            num.push(x);
        } else if (c == '(') {
            op.push(c);
        } else if (c == ')') {
            while (op.top() != '(') eval();
            op.pop();
        } else {
            while (!op.empty() && op.top() != '(' && pr[op.top()] >= pr[c]) {
                eval();
            }
            op.push(c);
        }
    }
    while (!op.empty()) {
        eval();
    }
    cout << num.top() << endl;
    return 0;
}