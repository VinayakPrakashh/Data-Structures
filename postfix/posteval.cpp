#include<iostream>
#include <ctype.h>
#include "stack.h"
using namespace std;
void evalpostfix(char postfix[])
{
    stack <int> s;
    int i,x,y,val;
    char item;
    for(i=0;postfix[i]!='\0';i++){
    item=postfix[i];
    if(isalnum(item)){
        s.push(item-'0');
    }
    else{
        x=s.pop();
        y=s.pop();
        switch(item){
            case '/' :
            val=y/x;
            break;
            case '*':
            val=y*x;
            break;
            case '+' :
            val=y+x;
            break;
            case '-':
            val=y-x;
            break;
        }
        s.push(val);
    }
}
cout<<"Answer is "<<s.pop();
}
int main(){
    char postfix[100];
    cout<<"Enter the postfix expression"<<endl;
    cin>>postfix;
    evalpostfix(postfix);
}
