#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Stack
{
  int size;
  int top;
  char *s;
};

struct StackInt
{
  int size;
  int top;
  long int *sp;
};

void create(struct Stack *st)
{
  st->size = 20;
  st->top = -1;
  st->s = (char *)malloc(sizeof(char) * st->size);
}

void push(struct Stack *st, int data)
{
  if (st->top > st->size - 1)
    printf("Stack Overloaded!\n");
  else
  {
    st->top++;
    st->s[st->top] = data;
  }
}

void pushh(struct StackInt *st, long int data) //Push function for the stack of type long int
{
  if (st->top > st->size - 1)
    printf("Stack Overloaded!\n");
  else
  {
    st->top++;
    st->sp[st->top] = data;
  }
}

int pop(struct Stack *st)
{
  if (st->top < 0)
    printf("Stack Underflow!\n");
  else
  {
    int x = st->s[st->top];
    st->top--;
    return x;
  }
  return -1;
}

long int
poph(struct StackInt *st) //Pop function for the new long int stack
{
  if (st->top < 0)
    printf("Stack Underflow!\n");
  else
  {
    long int x = st->sp[st->top];
    st->top--;
    return x;
  }
  return -1;
}

int isEmpty(struct Stack st)
{
  if (st.top < 0)
    return 1;
  else
    return 0;
}

int isFull(struct Stack st)
{
  if (st.top > st.size - 1)
    return 1;
  else
    return 0;
}

int isOperand(char x) //Check for knowing if char is an operand
{
  if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
    return 0;
  else
    return 1;
}

int preOut(char x) //Precedence out of the stack
{
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 3;
  else if (x == '^')
    return 6;
  else if (x == '(')
    return 7;
  else
    return 0;
}

int preIn(char x) //Precedence inside the stack
{
  if (x == '+' || x == '-')
    return 2;
  else if (x == '*' || x == '/')
    return 4;
  else if (x == '^')
    return 5;
  else if (x == '(')
    return 0;
  else
    return 0;
}

char *
infixToPostfix(char *infix)
{
  struct Stack st;
  create(&st);
  int i = 0, j = 0;
  char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
  while (infix[i] != '\0') //Postfix conversion through iteration
  {
    if (isOperand(infix[i]))
      postfix[j++] = infix[i++];
    else
    {
      if (preOut(infix[i]) > preIn(st.s[st.top]))
        push(&st, infix[i++]);
      else if (infix[i] == ')')
      {
        while (st.s[st.top] != '(')
          postfix[j++] = pop(&st);
        pop(&st);
        i++;
      }
      else
      {
        postfix[j++] = pop(&st);
      }
    }
  }
  while (st.top != -1)
    postfix[j++] = pop(&st);
  return postfix;
}

long int operation(char op, long int x, long int y) //Operations based on the operator received
{
  if (op == '+')
  {
    return x + y;
  }
  else if (op == '-')
  {
    return x - y;
  }
  else if (op == '*')
  {
    return x * y;
  }
  else if (op == '/')
  {
    return x / y;
  }
  else if (op == '^')
  {
    long int power = (long int)pow(x, y);
    return power;
  }
}

long int
postfixEvaluate(char *postfix)
{
  struct StackInt si;
  si.size = 20;
  si.top = -1;
  si.sp = (long int *)malloc(sizeof(long int) * si.size); //Assigning memory to the new stack created of type long int
  long int x, y;
  long int result;
  for (int i = 0; postfix[i] != '\0'; i++)
  {
    if (isOperand(postfix[i]))
    {

      long int val;

      printf("Enter value of %c: ", postfix[i]); //User prompt to enter the values

      scanf("%ld", &val);

      pushh(&si, val);
    }
    else
    {
      y = poph(&si);
      x = poph(&si);
      result = operation(postfix[i], x, y);
      pushh(&si, result);
    }
  }
  result = poph(&si);
  return result;
}
int main()
{

  int infix_length;

  printf("Enter length of infix expression: ");

  scanf("%d", &infix_length);

  char infix[infix_length + 1];

  printf("Enter the infix expression: ");

  scanf("%s", infix);

  char *postfix = infixToPostfix(infix);

  printf("Postfix: %s\n", postfix);

  long int eval = postfixEvaluate(postfix);

  printf("Evaluation: %ld\n", eval);
}
