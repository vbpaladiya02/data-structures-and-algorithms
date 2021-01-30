
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
char st[MAX];
int top=-1;
void reverse(char str[]);
void push(char st[],char);
char pop(char st[]);
void infixtopostfix(char source[],char target[]);
int getPriority(char);
char infix[100],postfix[100],temp[100];
void reverse(char str[])
{
int len,i=0,j=0;
len=strlen(str);
j=len-1;
while(j>= 0)
{
if(str[j] == '(')
temp[i]=')';
else if(str[j]== ')')
temp[i]='(';
else
temp[i]=str[j];
i++;
j--;
}
temp[i]='\0';
}
void push(char st[],char val)
{
if(top==MAX-1)
printf("\n STACK OVERFLOW");
else
{
top++;
st[top]=val;
}
}
char pop(char st[])
{
char val=' ';
if(top==-1)
printf("\n STACK UNDERFLOW");
else
{val=st[top];
top--;
}
return val;
}
int getPriority(char op)
{
if(op=='/' || op=='*' || op=='%')
return 1;
else if(op=='+' || op=='-')
return 0;
}
void infixtopostfix(char source[], char target[])
{
int i=0,j=0;
char temp;
stpcpy(target,"");
while(source[i] != '\0')
{
if(source[i]=='(')
{
push(st,source[i]);
i++;
}
else if(source[i] == ')')
{
while((top != -1)&&(st[top] != '('))
{
target[j]=pop(st);
j++;
}
if(top==-1)
{
printf("\n INCORRECT EXPRESSION");
exit(1);
}
temp=pop(st); // remove left paranthesis
i++;
}
else if(isdigit(source[i]) || isalpha(source[i]))
{
target[j]=source[i];
j++;
i++;
}
else if(source[i] == '+' ||source[i] == '-' ||source[i] == '*' ||source[i] == '/' ||source[i] ==
'%')
{
while((top != -1) && (st[top] != '(') &&
(getPriority(st[top])>=getPriority(source[i]))){
target[j]=pop(st);
j++;
}
push(st,source[i]);
i++;
}
else
{
printf("\n INCORRECT ELEMENT IN EXPRESSION");
exit(1);
}
}
while((top!=-1) && (st[top] != '('))
{
target[j]=pop(st);
j++;
}
target[j]='\0';
}
int main()
{
printf("\n Enter any infix expression:");
gets(infix);
reverse(infix);
puts(temp);
stpcpy(postfix,"");
infixtopostfix(temp,postfix);
printf("\n the corresponding postfix expression is:");
puts(postfix);
stpcpy(temp,"");
reverse(postfix);
printf("\n the prefix expression is:\n");
puts(temp);
return 0;
}