/*Write a program to input an infix expression and convert into its equivalent post fix
form and display. Operands can be single character.
Completed!
*/

#include<iostream>
using namespace std;
#include<cstring>

enum precedence{lparan,rparan,pluss,minuss,times,divide,mod,eos,operand};
    int icp[]={20,19,12,12,13,13,13,0};
    int isp[]={0,19,12,12,13,13,13,0};
precedence get_token(char c){
    switch(c){
        case '(': return lparan; break;
        case ')': return rparan; break;
        case '+': return pluss; break;
        case '-': return minuss; break;
        case '*': return times; break;
        case '/': return divide; break;
        case '%': return mod; break;
        case '#': return eos; break;
        default : return operand; break;
    }
}

class stack{

public:
    char a[50];
    int top;
    stack(){top=-1;}
    friend void im2postfix(char[]);
    void push(char x){
    a[++top]=x;
    }
    char pop(){
    return a[top--];
    }
    };

void in2postfix(char infix[]){
    int i=0,j=0;
    precedence temp;
    char postfix[20];
    stack s;
    s.push('#');

    while(infix[i]!='\0'){
        temp=get_token(infix[i]);
        if(temp==operand){
            postfix[j++]=infix[i];
        }
        else if(temp==rparan){
            while(s.a[s.top]!='('){
                postfix[j++]=s.pop();
            }
            s.pop();
        }
        else{
            while(icp[temp]<=isp[get_token(s.a[s.top])]){
                postfix[j++]=s.pop();
            }
            s.push(infix[i]);
        }
        i++;
    }
    while(s.top>0){
        postfix[j++]=s.pop();
    }
    postfix[j]='\0';
    cout<<"Postfix expression is: "<<postfix;
}

int main() {
    char infix[100];
    cout<<"Enter the infix expression: ";
    cin>>infix;
    in2postfix(infix);

return 0;
}
