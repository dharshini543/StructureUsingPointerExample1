#include <stdio.h>
#include<stdlib.h>

struct Student
{
    char * Name;
    char * Address;
    unsigned int Student_ID;
};

int main()
{
    int numofstudents;
    printf("Enter number of students\n");
    scanf("%d",&numofstudents);
    if(numofstudents < 10)
    {
        return 1;
    }

    struct Student *ptr=(struct Student *)malloc(numofstudents*(sizeof(struct Student)));
    if(ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter Student details\n");
    for(int i = 0;i < numofstudents;i++)
    {

        (ptr+i)->Student_ID = i+1;
        printf("For Student Id = %d\n",(ptr+i)->Student_ID);
        (ptr+i)->Name = (char*)malloc(sizeof(50));
        printf("Enter Student Name\n");
        scanf("%s",(ptr+i)->Name);
        (ptr+i)->Address = (char*)malloc(sizeof(100));
        printf("Enter Student Address\n");
        scanf("%s",(ptr+i)->Address);
    }

    printf("  Student Record Details\n");

    printf("ID\tNAME\t\tADDRESS\n");
    for(int i = 0;i < numofstudents;i++)
    {

        printf("%d\t%s\t\t%s\n",(ptr+i)->Student_ID,(ptr+i)->Name,(ptr+i)->Address);
        free((ptr+i)->Name);
        free((ptr+i)->Address);
    }
    free(ptr);


    return 0;
}







