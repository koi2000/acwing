#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
struct Student {
    int grade[4];
    int rank[4];
    int id;
} students[2000];
// 将学号映射到students数组中
int id[1000000];
// 要比较的科目索引
int compareGrade = -1;

bool cmp(Student a, Student b) { return a.grade[compareGrade] > b.grade[compareGrade]; }

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Student *stu;
    for (int i = 0; i < n; i++) {
        stu = &students[i];
        scanf("%d %d %d %d", &(stu->id), &(stu->grade[1]), &(stu->grade[2]), &(stu->grade[3]));
        stu->grade[0] = (stu->grade[1] + stu->grade[2] + stu->grade[3]) / 3;
    }
    for (int i = 0; i < 4; i++) {
        // 按当前科目重新排序
        compareGrade = i;
        sort(students, students + n, cmp);

        for (int j = 0; j < n; j++) {
            if (students[j].grade[i] == students[j - 1].grade[i]) {
                // 和前一名分数相等， 并列排名
                students[j].rank[i] = students[j - 1].rank[i];
            } else {
                // 否则排名为j + 1
                students[j].rank[i] = j + 1;
            }
        }
    }
    // 初始化映射数组，-1代表此学生不存在
    fill(id, id + 1000000, -1);

    // 建立学号到索引值的映射
    for (int i = 0; i < n; i++) {
        id[students[i].id] = i;
    }
    int search, index;
    char subjects[] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < m; i++) {
        scanf("%d", &search);
        index = id[search];
        if (index < 0) {
            printf("N/A\n");
        } else {
            // 学生最多2000名，所以排名一定小于2001
            int top = 2001, topJ = 0;
            for (int j = 0; j < 4; j++) {
                if (students[index].rank[j] < top) {
                    top = students[index].rank[j];
                    topJ = j;
                }
            }
            // 输出最高排名及排名方式
            printf("%d %c\n", top, subjects[topJ]);
        }
    }
    return 0;
}
