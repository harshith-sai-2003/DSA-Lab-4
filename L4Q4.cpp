/*Write a program to input an infix expression and convert into its equivalent prefix
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
    friend void in2prefix(char[]);
    void push(char x){
    a[++top]=x;
    }
    char pop(){
    return a[top--];
    }
    };

void in2prefix(char infix[]){
    int i=0,j=0;
    precedence temp;
    char prefix[20];
    stack s;
    s.push('#');

    while(infix[i]!='\0'){
        temp=get_token(infix[i]);
        if(temp==operand){
            prefix[j++]=infix[i];
        }
        else if(temp==rparan){
            while(s.a[s.top]!='('){
                prefix[j++]=s.pop();
            }
            s.pop();
        }
        else{
            while(icp[temp]<=isp[get_token(s.a[s.top])]){
                prefix[j++]=s.pop();
            }
            s.push(infix[i]);
        }
        i++;
    }
    while(s.top>0){
        prefix[j++]=s.pop();
    }
    prefix[j]='\0';
    cout<<"Prefix expression is: "<<prefix;
}

int main() {
    char infix[100],temp[100];
    int i=0;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    while(infix[i]!='\0'){
        temp[i]=infix[strlen(infix)-i-1];
    }
    in2prefix(temp);

return 0;
}
