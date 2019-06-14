#ifndef C1004_H
#define C1004_H

#include <iostream>
#include <string>
#include <list>
#define MAX 11

using namespace std;

class c1004
{
    public:
        c1004();
        virtual ~c1004();
        friend istream & operator >> ( istream &in ,c1004 &student);
        friend ostream & operator << ( ostream &out ,c1004 &student);
        c1004 getMax(list<c1004> students);
        c1004 getMin(list<c1004> students);
        void getInf();

    protected:

    private:
        char name[MAX];
        char sno[MAX];
        int score;
};

#endif // C1004_H
