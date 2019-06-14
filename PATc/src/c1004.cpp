#include "c1004.h"


/*
    知识点：1.运算符重载

    错误：  1.list类非List类，头文件<list>
            2.类的初始化是 c1004 stu 或 c1004 *stu = new c1004() , new的需要delete;
            3.list的访问没有for(temp:tempList)用法,
              可以用迭代器iterator，有begin()、end()、++等用法；
            4.运算符重载，类没用引用，导致错误
*/



c1004::c1004() {
    //ctor
}

c1004::~c1004() {
    //dtor
}

//  输入对象
istream & operator >> ( istream &in,c1004 &student) {
    in >> student.name >> student.sno >> student.score ;
    return in;
}
//  输出对象
ostream & operator << ( ostream &out,c1004 &student) {
    out<< student.name << " " << student.sno <<endl;
    return out;
}
//  获取最大值对象
c1004 c1004::getMax(list<c1004> students) {
    int max = 0;
    c1004 maxStu;
    list<c1004>::iterator it;
    for( it = students.begin(); it != students.end(); ++it) {
        c1004 stu = *it;
        if(stu.score > max) {
            maxStu = stu;
            max = stu.score;
        }
    }
    return maxStu;

}
//  获取最小值对象
c1004 c1004::getMin(list<c1004> students) {
    int min = 100;
    c1004 minStu;
    list<c1004>::iterator it;
    for(  it = students.begin(); it != students.end(); ++it) {
        c1004 stu = *it;
        if(stu.score < min) {
            min = stu.score;
            minStu = stu;
        }
    }
    return minStu;
}
//  主要操作
void c1004::getInf() {
    int num;
    list<c1004> stuList;
    c1004 student;
    //  输入行数
    cin >> num;
    //  存储
    while( 0 != num--) {
        c1004 tempStu;
        cin >> tempStu;
        stuList.push_back(tempStu);
    }
    //  输出最大最小
    c1004 max = student.getMax(stuList);
    cout << max;
    c1004 min = student.getMin(stuList);
    cout << min;

}
