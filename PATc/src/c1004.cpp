#include "c1004.h"


/*
    ֪ʶ�㣺1.���������

    ����  1.list���List�࣬ͷ�ļ�<list>
            2.��ĳ�ʼ���� c1004 stu �� c1004 *stu = new c1004() , new����Ҫdelete;
            3.list�ķ���û��for(temp:tempList)�÷�,
              �����õ�����iterator����begin()��end()��++���÷���
            4.��������أ���û�����ã����´���
*/



c1004::c1004() {
    //ctor
}

c1004::~c1004() {
    //dtor
}

//  �������
istream & operator >> ( istream &in,c1004 &student) {
    in >> student.name >> student.sno >> student.score ;
    return in;
}
//  �������
ostream & operator << ( ostream &out,c1004 &student) {
    out<< student.name << " " << student.sno <<endl;
    return out;
}
//  ��ȡ���ֵ����
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
//  ��ȡ��Сֵ����
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
//  ��Ҫ����
void c1004::getInf() {
    int num;
    list<c1004> stuList;
    c1004 student;
    //  ��������
    cin >> num;
    //  �洢
    while( 0 != num--) {
        c1004 tempStu;
        cin >> tempStu;
        stuList.push_back(tempStu);
    }
    //  ��������С
    c1004 max = student.getMax(stuList);
    cout << max;
    c1004 min = student.getMin(stuList);
    cout << min;

}
