#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<ctype.h>
#define MAX_STACK_SIZE 20
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;
char tmp[MAX_STACK_SIZE] = "";

// ���� �ʱ�ȭ �Լ�
void init(StackType *s) {
		s->top = -1;
	}
// ���� ���� ���� �Լ�
int is_empty(StackType *s) {
		return (s->top == -1);
	}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s) {
		return (s->top == (MAX_STACK_SIZE-1));
	}
// �����Լ�
void push(StackType *s, element item) {
		if ( is_full(s) ) {
			fprintf(stderr," \n");
			return;
		}else s->stack[++(s->top)] = item;
	
	}
// �����Լ�
element pop(StackType *s) {
	if ( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
		} else return s->stack[(s->top)--];
	}
// ��ũ�Լ�
element peek(StackType *s) {
	if ( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
		} else return s->stack[s->top];
	}

// �������� �켱������ ��ȯ�Ѵ�.
int prec(char op) {
	switch(op){
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		}
		return -1;
}

//infix to postfix
void infix_to_postfix(char infix[],char postfix[])
{
	
    StackType s;
    char x,token;
    int i,j;    //i-index of infix, j-index of postfix
    init(&s);
    j=0;
	
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
            postfix[j++]=token;
        else
            if(token=='(')
               push(&s,'(');
        else
            if(token==')')
                while((x=pop(&s))!='(')
                      postfix[j++]=x;
        else
        {
            while(!is_empty(&s) && (prec(token) <= prec(peek(&s))))
            {
                x=pop(&s);
                postfix[j++]=x;
            }
            push(&s,token);
        }
    }
 
    while(!is_empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }
 
    postfix[j]='\0';
	printf("\ninfix_to_postfix expression:%s\n",postfix);
	
}

char* postfix_to_infix(char postfix[], char infix[])
{
	
	/* fill in the blank */
	
	
	StackType s;
	char x,y, token;
	int i, j;    //i-index of infix, j-index of postfix
	init(&s);
	j = 0;

	//push and pop
	for (i = 0; postfix[i] != '\0'; i++)
	{
		token = postfix[i];
		if (isalnum(token))
			push(&s,token);
		else
		{	
			x = pop(&s);
			y = pop(&s);
			//if y = ), push until (
			if (y == ')') {
				
				char arr[10];
				int m = 0;
				arr[m] = y;
				while (arr[m++] != '(') {
					arr[m] = pop(&s);;
					
				}
				arr[m]= '(';
				
				while (arr[m] != ')') {
					push(&s, arr[m--]);
				}
				push(&s, arr[m]);
				push(&s, token);
				push(&s, x);
				push(&s, ')');
			}
			else {
				push(&s, '(');
				push(&s, y);
				push(&s, token);
				push(&s, x);
				push(&s, ')');
			}
		}
		
	}
	j = s.top;

	//printf("%d   top", s.top);
	infix[s.top + 1] = '\0';
	while (!is_empty(&s))
	{
		x = pop(&s);
		infix[j--] = x;
	}
	//printf("%c \n", infix[s.top]);
	
	
	
	printf("postfix_to_infix expression: %s \n", infix);
}

int postfixEval(char exp[])
{   

  /* fill in the blank */
	StackType s;
	char x, y, token;
	int i, j;    //i-index of infix, j-index of postfix
	init(&s);
	j = 0;

	//evaluate 
	for (i = 0; exp[i] != '\0'; i++)
	{
		token = exp[i];
		
		if (isalnum(token))
			push(&s, token);
		else
		{
			x = pop(&s);
			y = pop(&s);
			// char to int
			int a, b;
			a = x - 48;
			b = y - 48;
			if (token == '+') {
				x = a + b+48;
				push(&s, x);
			}
			else if (token == '-') {
				x =  b -a+ 48;
				push(&s, x);
				
			}
			else if (token == '*') {
				
				x = (a * b) + 48;
				push(&s, x );
			}
			else if (token == '/') {
				x = b/a + 48;
				push(&s, x);
			}
		}

	}

	return pop(&s);
}

int main() { 

	FILE *f;
	char postfix[30];
	char infix[30];
	char* tmp = (char*)malloc(sizeof(char)*20);
	
	f=fopen("input1.txt","r");
	fscanf(f,"%s", tmp);
	infix_to_postfix(tmp,postfix);
	printf("eval: %c \n", postfixEval(postfix)); 

	f=fopen("input2.txt","r");
	fscanf(f,"%s", tmp);
	postfix_to_infix(tmp,infix);                   
	printf("eval: %d \n", postfixEval(tmp)-48); 
	
	
	return 0;
}