#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
    cout << "Enter the expression: "<<endl;
    string str;
    getline(cin,str);
    stringstream ss(str);

    int num;
    ss>>num;
    int result = num;
    char op;
    while(ss>>op>>num){
        if(op == '+' ) result += num;
        if(op == '-' ) result -= num;
        if(op == '*' ) result *= num;
        if(op == '/' ) result /= num;
    }
    cout <<"Result: "<<result<<endl;
    return 0;
}