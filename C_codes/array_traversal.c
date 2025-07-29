#include <stdio.h>

int main(){
    int a[5] ,size;
    printf("Enter the number of elements in array: ");
    scanf("%d",&size);
    printf("enter the elements: ");
    for(int i = 0;i < size+1;i++){
    scanf("%d",&a[i]);
    }
    printf("Elements: ");
    for(int i = 0; i < size+1 ; i++){
        printf("Element %d is %d \n",i,a[i]);
    }
    return 0;
}