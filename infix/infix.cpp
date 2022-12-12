#include <iostream>
#include "stack.h"
#include <ctype.h>
using namespace std;
int ICP(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 3;
            break;
        case '^':
            return 6;
            break;
        case '(':
            return 9;
            break;
    }
}
int ISP(char c){
    switch(c){
        case '+':
        case '-':
            return 2;
            break;
        case '*':
        case '/':
            return 4;
            break;
        case '^':
            return 5;
            break;
        case '(':
            return 0;
            break;
    }
}
void infixtopostfix(string infix){
    stack <char> s;
    int i;
    s.push('(');
    cout <<"Postfix expression"<< endl;
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            cout<<infix[i];
        }
        else if(infix[i]=='!'){
            while(s.topstack()!='('){
                cout<<s.topstack();
                s.pop();
            }
            s.pop();
        }
        else if(ICP(infix[i])>ISP(s.topstack())){
                s.push(infix[i]);
        }
        else if(ICP(infix[i])<ISP(s.topstack())){
            while(ICP(infix[i])<ISP(s.topstack())){
                cout << s.topstack();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while(s.topstack()!='('){
        cout << s.topstack();
        s.pop();
    }
    s.pop();
}
int main(){
    string infix;
    cout << "Enter an infix expression " << endl;
    cin >> infix;
    infixtopostfix(infix);
    return 0;
}