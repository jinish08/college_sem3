#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define SIZE 50

int sint[SIZE];
int top2 = -1;
int flag = 0;
int popint()
{
    return (sint[top2--]);
}

int pushint(int elem)
{
    if (flag >= 1)
    {
        int num;
        num = popint();
        sint[++top2] = elem + 10 * flag * num;
    }
    else if (flag == 0)
    {
        sint[++top2] = elem;
        flag = 1;
    }
}

int postEva()
{
    char postEva[50], ch;
    int i = 0, op1, op2;
    printf("Enter the Postfix Expression:");
    fgets(postEva, 100, stdin);
    while ((ch = postEva[i++]) != '\n')
    {
        if (isdigit(ch))
            pushint(ch - '0');
        else if (ch == ' ')
            flag = 0;
        else
        {
            flag = 0;
            op2 = popint();
            op1 = popint();
            switch (ch)
            {
            case '+':
                pushint(op1 + op2);
                break;
            case '-':
                pushint(op1 - op2);
                break;
            case '*':
                pushint(op1 * op2);
                break;
            case '/':
                pushint(op1 / op2);
                break;
            case '^':
                pushint(pow(op1, op2));
                break;
            case '%':
                pushint(op1 % op2);
                break;
            default:
                printf("Input invalid ... give proper input\n");
                return 0;
            }
        }
    }
    printf("Result: %d\n", sint[top2]);
}

void main()
{
    postEva();
}