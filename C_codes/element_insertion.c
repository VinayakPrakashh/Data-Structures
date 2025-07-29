#include <stdio.h>
void insert_elem(int *a,int *size){
    printf("Enter the number of elements in array: ");
    scanf("%d",size);
    while(*size > 50){
        printf("Size Exceeded! Enter size less than 50: \n");
        scanf("%d",size);
    }
    printf("enter the elements: ");
    for(int i = 0; i < *size ; i++ ){
    scanf("%d",&a[i]);
    }

}
void insert_at_position(int *a,int *size,int *pos,int *num){

    printf("ENter the number to insert: ");
    scanf("%d",num)
    printf("Enter the position: ");
    scanf("%d",pos);
    for(i = *size-1 ; i >= *pos-1 ; i--){
        a[i+1] = a[i];
    }
    a[pos-1] = *num;
    *size++;

}
int main(){
    int a[50] ,size,pos,num;

    insert_elem(a,&size);
    // printf("Elements: ");
    // for(int i = 0; i < size+1 ; i++){
    //     printf("Element %d is %d \n",i,a[i]);
    // }
    return 0;
}

