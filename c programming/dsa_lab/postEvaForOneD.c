#define SIZE 50
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int ints[SIZE];
int topint = -1;
char pofx[20];
int flag = 0;

void pushint(int e)
{
    ints[++topint] = e;
    if (flag == 1)
    {
        int num;
        num = popint();
        ints[++topint] = e + 10 * num;
    }
    else if (flag == 0)
    {
        ints[++topint] = e;
        flag = 1;
    }
}

int popint()
{
    return ints[topint--];
}

void postEva()
{
    int n1, n2, n3;
    int i = 0;
    printf("\n\nRead the Postfix Expression ? ");
    gets(pofx);
    int l = strlen(pofx);
    for (int i = 0; i < l; i++)
    {

        if (isdigit(pofx[i]))
        {
            int x = pofx[i] - '0';
            pushint(x);
        }
        else if (pofx[i] == ' ')
        {
            flag = 0;
        }
        else
        {
            flag = 0;
            n1 = popint();
            n2 = popint();
            printf("%d %d", n1, n2);
            switch (pofx[i])
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            case '*':
                n3 = n1 * n2;
                break;

            default:
                printf("Unknown Operetor");
                break;
            }
            pushint(n3);
        }
    }
    printf("\nThe result is %d ", n3);
}

void main()
{
    postEva();
}