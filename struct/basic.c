#include<stdio.h>

typedef struct student
{
    int rollno;
    float mark;
    char name[20];
}sdt;

void main(){
    sdt s[3];
    scanf("%d %f %s",&s[0].rollno,&s[0].mark,&s[0].name);
    printf("%d %f %s",s[0].rollno,s[0].mark,s[0].name);
}
