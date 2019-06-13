#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

/*
    ��֪ʶ��
    1.�ַ�תint���ͣ�atoi()������ʹ�ÿ⣺<stdlib.h>
    2.string��int���⻥ת:stringstream�࣬ʹ�ÿ�sstream��ʹ�����������
    3.stack���pop����ֻ��ɾ���������ȡֵ

*/

int main()
{
    string numStr[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    stack<string> sumStack;
    char num;
    int sum=0;
    //  ��ȡ����
    while( (num=cin.get()) != '\n' ){
        sum +=  atoi(&num);
    }
    //  ���ת������
    while(true){
        string temp = numStr[sum%10];
        sum /= 10;
        sumStack.push(temp);
        if( 0 != sum){
            sumStack.push(" ");
        }else{
            break;
        }
    }
    //  �������
    while(!sumStack.empty()){
        cout<<sumStack.top();
        sumStack.pop();
    }

    return 0;
}
