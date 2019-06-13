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
    思路：  1.字符串一定有且仅有P、A、T三个字符；
            2.字符串中P、T仅出现一次；
            3.前(numHeadA)、中(numCenterA)、后(numEndA)的A满足该条件：numEndA == numHeadA * numCenterA，且中间的A至少有一个；

    错误之处：  1.最简单的错误：开始新循环时没有将条件初始化；
                2.条件3中，没有把结果当条件再迭代；
                3.没有判断P、T是否只有一个。
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
                //  输入值为P（前面P、T的数量都得是0）
                numP ++;
            } else if( T == c && 1 == numP && 0 < numCenterA && 0 == numT) {
                //  输入值为T（可能正确情况：前面P有1个， A至少有一个，T没有）
                numT ++;
            } else if( A == c) {
                //  输入值为A（分前中后三种情况）
                if( 0 == numP && 0 == numT) {
                    //  前：P、T都没有出现
                    numHeadA ++;
                } else if( 1 == numP && 0 == numT) {
                    //  中：P出现一次、T没出现过
                    numCenterA ++;
                } else if( 1 == numP && 1 == numT) {
                    //  后：P/T各出现一次
                    numEndA ++;
                }
            } else {
                //  不是以上情况的都是错误的
                succeed = false;
                break;
            }
        }
        //  判断文中是否有P、T
        if( 0 == numP || 0 == numT){
            succeed = false;
        }
        //  正确的情况判断
        if(true == succeed) {
            if(numEndA == numHeadA * numCenterA){
                result = YES;
            }
        }
        //  输出结果
        cout<<result<<endl;
    }

}

