#include "students.hpp"
#include "teacher.hpp"
#include <iostream>
#include <string>
using namespace std;
void print(const Teachers& t)
{
    cout << "老师的名字是：" << t.name << endl;
    cout << "该老师带的学生信息如下：" << endl;
    cout << "name\t"
         << "score\t" << endl;
    for (int i = 0; i < 5; i++) {
        cout << t.s[i].name << "\t" << t.s[i].score << endl;
    }
}
int main()
{
    Teachers t[3];
    t[0].name = "teacher1";
    t[0].s[0].name = "t0s1";
    t[0].s[1].name = "t0s2";
    t[0].s[2].name = "t0s3";
    t[0].s[3].name = "t0s4";
    t[0].s[4].name = "t0s5";
    t[0].s[0].score = 60;
    t[0].s[1].score = 90;
    t[0].s[2].score = 80;
    t[0].s[3].score = 70;
    t[0].s[4].score = 100;
    print(t[0]);

    t[1].name = "teacher2";
    t[1].s[0].name = "t1s1";
    t[1].s[1].name = "t1s2";
    t[1].s[2].name = "t1s3";
    t[1].s[3].name = "t1s4";
    t[1].s[4].name = "t1s5";
    t[1].s[0].score = 60;
    t[1].s[1].score = 90;
    t[1].s[2].score = 80;
    t[1].s[3].score = 70;
    t[1].s[4].score = 100;
    print(t[1]);

    t[2].name = "teacher3";
    t[2].s[0].name = "t2s1";
    t[2].s[1].name = "t2s2";
    t[2].s[2].name = "t2s3";
    t[2].s[3].name = "t2s4";
    t[2].s[4].name = "t2s5";
    t[2].s[0].score = 60;
    t[2].s[1].score = 90;
    t[2].s[2].score = 80;
    t[2].s[3].score = 70;
    t[2].s[4].score = 100;
    print(t[2]);
}
