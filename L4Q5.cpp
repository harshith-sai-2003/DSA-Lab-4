/*Write a program to evaluate prefix expression. The input to the program is a prefix expression.
Completed!
*/

#include<iostream>
using namespace std;
#include<cstring>

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
    int i=strlen(ex),a,b;
    stack s;
    while(i>-1){
        if(ex[i]>=48 && ex[i]<=57)
            s.push(ex[i]-48);
        else{
            a=s.pop();
            b=s.pop();
            switch(ex[i]){
                case '+':s.push(a+b);break;
                case '-':s.push(a-b);break;
                case '*':s.push(a*b);break;
                case '/':s.push(a/b);break;
                case '%':s.push(a%b);break;
            }
        }
        i--;
    }
    cout<<"Result: "<<s.pop();
}

int main(){
    char c[50];
    cout<<"Enter a prefix expression: ";
    cin>>c;
    eval(c);
}
