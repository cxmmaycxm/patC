#include "c1003.h"
#include <iostream>
#include <string.h>

#define YES "YES"
#define NO "NO"
#define P 'P'
#define A 'A'
#define T 'T'
#define MAX 101

using namespace std;

/*
    ˼·��  1.�ַ���һ�����ҽ���P��A��T�����ַ���
            2.�ַ�����P��T������һ�Σ�
            3.ǰ(numHeadA)����(numCenterA)����(numEndA)��A�����������numEndA == numHeadA * numCenterA�����м��A������һ����

    ����֮����  1.��򵥵Ĵ��󣺿�ʼ��ѭ��ʱû�н�������ʼ����
                2.����3�У�û�аѽ���������ٵ�����
                3.û���ж�P��T�Ƿ�ֻ��һ����
*/

c1003::c1003() {
    //ctor
}

c1003::~c1003() {
    //dtor
}

void c1003::sayYes() {
    int numP, numT, numHeadA, numCenterA, numEndA, row;
    char input[MAX];
    char c;
    string result = NO;
    bool succeed = true;
    numP = numT = numHeadA = numCenterA = numEndA = 0;
    cin>>row;
    while(0 != row--) {
        result = NO;
        succeed = true;
        numP = numT = numHeadA = numCenterA = numEndA = 0;
        cin>>input;
        int i=0;
        while( (c=input[i++]) != '\0') {
            //cout<<c<<" "<<numHeadA<<numP<<numCenterA<<numT<<numEndA<<endl;
            if( P == c && 0 == numP && 0 == numT) {
                //  ����ֵΪP��ǰ��P��T������������0��
                numP ++;
            } else if( T == c && 1 == numP && 0 < numCenterA && 0 == numT) {
                //  ����ֵΪT��������ȷ�����ǰ��P��1���� A������һ����Tû�У�
                numT ++;
            } else if( A == c) {
                //  ����ֵΪA����ǰ�к����������
                if( 0 == numP && 0 == numT) {
                    //  ǰ��P��T��û�г���
                    numHeadA ++;
                } else if( 1 == numP && 0 == numT) {
                    //  �У�P����һ�Ρ�Tû���ֹ�
                    numCenterA ++;
                } else if( 1 == numP && 1 == numT) {
                    //  ��P/T������һ��
                    numEndA ++;
                }
            } else {
                //  ������������Ķ��Ǵ����
                succeed = false;
                break;
            }
        }
        //  �ж������Ƿ���P��T
        if( 0 == numP || 0 == numT){
            succeed = false;
        }
        //  ��ȷ������ж�
        if(true == succeed) {
            if(numEndA == numHeadA * numCenterA){
                result = YES;
            }
        }
        //  ������
        cout<<result<<endl;
    }

}

