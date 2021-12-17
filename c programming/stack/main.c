#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter the size of the stack");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack is full");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int pos)
{
    int x = -1;
    if (pos < 0 || pos >= st.size)
    {
        printf("Position out of bound");
    }
    else
    {
        x = st.S[st.top - pos + 1]; //cause of 1 based indexing of pos
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack st)
{
    int x = -1;
    if (isEmpty(st))
        printf("Stack is empty");
    else
        x = st.S[st.top];
    return x;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    int popedInt = pop(&st);
    int value = peek(st, 3); //x acc to 1 based indexing
    printf("%d\n", value);
    int topInt = stackTop(st);
    printf("%d\n", topInt);
    Display(st);
    return 0;
}