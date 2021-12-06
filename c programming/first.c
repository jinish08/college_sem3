#define SIZE 50
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char s[SIZE];
int top = -1;

void push(char e)
{
    s[++top] = e;
}

char pop()
{
    return s[top--];
}

int pr(char e)
{
    switch (e)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 4;
    default:
        break;
    }
}

void intoPost(char infx[50], char pofx[50])
{
    char ch;
    int i = 0, k = 0;
    push('#');

    while ((ch = infx[i++]) != '\0')
    {
        if (ch == ' ')
        {
            continue;
        }
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            pofx[k++] = ch;
            pofx[k++] = ' ';
        }
        else if (ch == ')')
        {
            while (s[top] != '(')
            {
                pofx[k++] = pop();
                pofx[k++] = ' ';
            }
            pop();
        }
        else
        {
            if (pr(s[top]) == 4 && pr(ch) == 4)
            {
                push(ch);
            }
            else
            {
                while (pr(s[top]) >= pr(ch))
                {
                    pofx[k++] = pop();
                    pofx[k++] = ' ';
                }
                push(ch);
            }
        }
    }
    while (s[top] != '#')
        pofx[k++] = pop();
    pofx[k++] = ' ';
    pofx[k] = '\0';

    printf("\n\nGiven Infix Expn: %s Postfix Expn : %s\n", infx, pofx);
}

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

int postEva(char postE[50])
{
    char ch;
    int i = 0, op1, op2;

    while ((ch = postE[i++]) != '\n')
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

    char infx[50], pofx[50], postE[50];
    printf("\n\nEnter the Infix Expression: ");
    gets(infx);
    intoPost(infx, pofx);
    // printf("Enter the Postfix Expression: ");
    // fgets(postE, 100, stdin);
    postEva(pofx);
}