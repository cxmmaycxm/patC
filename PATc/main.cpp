#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

/*
    新知识：
    1.字符转int类型：atoi()函数，使用库：<stdlib.h>
    2.string和int任意互转:stringstream类，使用库sstream，使用输入输出流
    3.stack类的pop方法只会删除，不会获取值

*/

int main()
{
    string numStr[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    stack<string> sumStack;
    char num;
    int sum=0;
    //  读取输入
    while( (num=cin.get()) != '\n' ){
        sum +=  atoi(&num);
    }
    //  结果转成中文
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
    //  输出中文
    while(!sumStack.empty()){
        cout<<sumStack.top();
        sumStack.pop();
    }

    return 0;
}
