#include <iostream>
#include <map>
#include <set>
#include <cstdio>

using namespace std;
#define K 6
// 创建map数组
map<string, set<int>> m[K];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int id;
    string str;
    while (n-- > 0) {
        scanf("%d\n", &id);
        for (int i = 1; i < 6; i++) {
            // 书的关键词可能有多个，需要特殊处理
            if (i == 3) {
                while (cin >> str) {
                    m[i][str].insert(id);
                    // 使用一个getchar()来吸收关键词之间的空格或者行末的换行符
                    // 当读到\n时代表后面没有关键词了，跳出循环
                    if (getchar() == '\n') {
                        break;
                    }
                }
            } else {
                getline(cin, str);
                m[i][str].insert(id);
            }
        }
    }

    int q;
    scanf("%d", &q);
    while (q-- > 0) {
        int type;
        string key;
        scanf("%d: ", &type);
        getline(cin, key);

        // 根据查询的字段获取对应的map的引用
        map<string, set<int> > &mm = m[type];

        // 输出命令
        cout << type << ": " << key << "\n";

        // 输出书的id或者Not Found
        if (mm.find(key) != mm.end()) {
            for (auto it = mm[key].begin(); it != mm[key].end(); it++)
                printf("%07d\n", *it);
        } else {
            printf("Not Found\n");
        }
    }
    return 0;
}
