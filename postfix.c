#include "postfix.h"

int evaluatePostfixExpression(char *expr)
{
	int varx,vary;				
	int result;	
	StackNodePtr head;						//initialise stack
	head = NULL;										
	strcat(expr, "\0");						//append null character to end of string
	while(*expr!='\0'){						//while pointer isn't null
		if(isDigit(*expr)==0){					//and current item is a digit
			push(&head, *expr-'0');				//push it to the stack
			printStack(head);
		}
		else if(isOperator(*expr)==0){			        //if current item is an operator
			varx=pop(&head);				//pop elements from stack
			vary=pop(&head);
			int result = calculate(varx, vary, *expr);
			push(&head, result); 				//calculate, push to stack
			printStack(head);
		}
		expr++;							//increment pointer
	}
	result = pop(&head);
        g_print("Result is %d\n", result);
        return result;	
}

int calculate(int op1, int op2, char operator)
{
	int result;
	switch(operator){						//perform calculations
		case '+': 	result = op1+op2;
					break;
		case '-': 	result = op1-op2;
					break;
		case '*': 	result = op1*op2;
					break;
		case '/': 	result = op1/op2;
					break;
		case '^': 	result = pow(op1, op2);
					break;
		case '%': 	result = op1%op2;
	}
	return result;
}

void push (StackNodePtr *topPtr, int value)
{
 	StackNodePtr new;				//this node will become the new top node
	new = malloc(Node_Size);			//allocate required memory
	new->data = value;				//set data value for new node
	new->nextPtr = *topPtr;				//put new node on top
	*topPtr = new;					//set pointer to reference the new top node
}
 
int pop (StackNodePtr *topPtr)
{
 	StackNodePtr tmp = *topPtr;			//temporary node holds top pointer
	int val = (*topPtr)->data;			//fetch value from top node
	 if (topPtr == NULL){
        printf("Stack is empty\n");
        return 1;
    }
	*topPtr = (*topPtr)->nextPtr;		        //pop node
	free(tmp);					//free memory
	return val;					//return value
}

int isEmpty(StackNodePtr topPtr)
{
	if(topPtr==NULL){
		return 0;				//return true if top pointer is null
	}	
		return 1;						
}

int isDigit(char c)					//returns 0 if digit
{
	switch(c)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return 0;
		default:
			return 1;
	}
}

int isOperator(char c)					//returns 0 if operator
{
  	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '%':
			return 0;
		default:
			return 1;
	}
}

void printStack(StackNodePtr topPtr)
{
 	StackNodePtr tmp = topPtr;			//temp node holds top node
	while(tmp!=NULL){				//while temp isn't null
		printf("%d\t", tmp->data);		//print data
		tmp = tmp->nextPtr;			//set tmp node to next node
	}
	if(tmp=='\0'){
		printf("NULL \t");
	}
	printf("\n");
}
 
