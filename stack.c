#include<stdio.h>
#define N 5

int stack[N];
int top = -1;

void push(){
    int x;
    printf("\nEnter the data to push\n");
    scanf("%d",&x);
    if(top == N-1){
        printf("\nStack full insertion failed!");
    }
    else{
        top++;
        stack[top] = x;
    }
}
void pop(){
    int item;
    if(top == -1){
        printf("\nstack is empty!");
    }
    else{
        item = stack[top];
        top--;
        printf("\n%d-th value deleted, value = %d",top+1,item);
    }

}
void peek(){
    if(top == -1){
        printf("\nstack is emoty");
    }
    else{
        printf("%d",stack[top]);
    }
}
void display(){
    int i;
    for(i = top;i>=0;i--){
printf("%d ",stack[i]);
    }
}

int main(){
    int ch;
    do{
        printf("\nEnter choice\n1. Push\n2. Pop\n3. Peek\n4. Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            default: printf("\ninvalid choice");
        }
    }while (ch!=0);
    return 0;
}
