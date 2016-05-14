#include <stdio.h>
#include <stdlib.h>                             //use for malloc!!!
#include <string.h>                             //use for strcat 
#include <math.h> 	                        //NEED TO LINK MATH -LM WHEN COMPILING
#include <gtk/gtk.h>

/*define constants*/
#define Node_Size sizeof(StackNode)

/*define stack structure */
struct stackNode {                          
    int data;
    struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;	        //alias for struct stackNode
typedef StackNode *StackNodePtr;		//alias for StackNode

/*function prototypes*/
int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);
void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
int isDigit(char c);
int isOperator(char c);
void printStack(StackNodePtr topPtr);
static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
static void destroy(GtkWidget *widget, gpointer data);
static void button_callback(GtkWidget *widget, GtkWidget *entry);

/*global variables*/
extern GtkWidget *entry;

