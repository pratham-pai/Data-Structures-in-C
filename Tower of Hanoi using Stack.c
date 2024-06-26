//Program 5b
#include<stdio.h>
#define MAX 10
typedef struct
{
    int values[MAX];
    int top;
}stack;
int empty(stack *s)
{
    return s->top==-1;
}
int pop(stack *s)
{
    return s->top>=0 ? s->values[(s->top)--]:-1;
}
void push(stack *s,int i)
{
    s->values[++(s->top)]=i;
}
stack *init()
{
    stack s=malloc(sizeof(stack));
    s->top=-1;
    return s;
}
void hanoi(int n,int beg,int aux,int end)
{
    stack *sbeg=init();
    stack *saux=init();
    stack *send=init();
    stack *sn=init();
    stack *sret=init();
    int nmoves=0;
    int ret=1,temp;
    while(1)
    {
        switch(ret)
        {
            case 1: if(n==1)
                    {
                        printf("\n%d:move from %d to %d\n",++nmoves,beg,end);
                        ret=5;
                    }
                    else
                        ret=2;
                    break;
            case 2: push(sbeg,beg);
                    push(saux,aux);
                    push(send,end);
                    push(sret,3);
                    push(sn,n);
                    --n;
                    temp=end;
                    end=aux;
                    aux=temp;
                    ret=1;
                    break;
            case 3: printf("\n%d:move from %d to %d\n",++nmoves,beg,end);
            case 4: push(sbeg,beg);
                    push(saux,aux);
                    push(send,end);
                    push(sret,5);
                    push(sn,n);
                    --n;
                    temp=beg;
                    beg=aux;
                    aux=temp;
                    ret=1;
                    break;
            case 5: if(empty(sn))
                        return;
                    n=pop(sn);
                    beg=pop(sbeg);
                    aux=pop(saux);
                    end=pop(send);
                    ret=pop(sret);
                    break;
        }
    }
}
int main()
{
    int n;
    printf("\nEnter number of disks");
    scanf("%d",&n);
    hanoi(n,1,2,3);
    return 0;
}
