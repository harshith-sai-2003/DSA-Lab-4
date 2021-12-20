/*Write a program that converts a post fix expression to a fully parenthesized infix expression
Completed!
*/
#include<iostream>
using namespace std;
#include<cstring>

class stack{
    char s[20][15];
    int top;

public: stack(){top=-1;}
void push(char a[]){
    strcpy(s[++top],a);
}
char*pop(){
    return s[top--];
}
};

void postfix(char p[]){
    char infix[50], t[3];
    int i=0,n=strlen(p);
    stack s;

    while(p[i]!='\0'){
        t[0]=p[i];
        t[1]='\0';
        if((p[i]>=65 && p[i]<=90) || (p[i]>=97 && p[i]<=122))
        s.push(t);
        else{
            char op1[10],op2[10],temp2[20];
            strcpy(op2,s.pop());
            strcpy(op1,s.pop());
            strcpy(temp2,"(");
            strcat(temp2,op1);
            strcat(temp2,t);
            strcat(temp2,op2);
            strcat(temp2,")");
            s.push(temp2);
        }
        i++;
    }
    cout<<"Infix expression is "<<s.pop();
}

int main(){
    char pof[50];
    cout<<"Enter the postfix expression: ";
    cin>>pof;
    postfix(pof);
    return 0;
}
