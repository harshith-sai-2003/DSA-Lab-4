/*Write a program to evaluate a postfix expression. The input to the program is a postfix expression
Completed!
*/

#include<iostream>
using namespace std;

class stack{

public:
    int a[50];
    int top;
    stack(){top=-1;}
    void push(int x){
    a[++top]=x;
    }
    int pop(){
    return a[top--];
    }
    };

void eval(char ex[]){
    int i=0,a,b;
    stack s;
    while(ex[i]!='\0'){
        if(ex[i]>=48 && ex[i]<=57)
            s.push(ex[i]-48);
        else{
            b=s.pop();
            a=s.pop();
            switch(ex[i]){
                case '+':s.push(a+b);break;
                case '-':s.push(a-b);break;
                case '*':s.push(a*b);break;
                case '/':s.push(a/b);break;
                case '%':s.push(a%b);break;
            }
        }
        i++;
    }
    cout<<"Result: "<<s.pop();
}

int main(){
    char c[50];
    cout<<"Enter a postfix expression: ";
    cin>>c;
    eval(c);
    return 0;
}
