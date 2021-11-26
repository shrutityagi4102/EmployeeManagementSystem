#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct emp_data
{
    int  empno;
    char empName[MAX];
    char designation[MAX];
    struct emp_data *next;
}*p;

struct emp_data *insert(struct emp_data *front, int id, char name[],char desg[])
{
    struct emp_data *temp;

    temp = (struct emp_data*)malloc(sizeof(struct emp_data));

    if (temp == NULL)
    {
        printf("\n Allocation failed \n");
        exit(2);
    }
    
    temp->empno = id;
    strcpy(temp->empName, name);
    strcpy(temp->designation, desg);
    temp->next = front;
    front = temp;
    return(front);
}

void printNode(struct emp_data *p)
{
    printf("\n Employee Details:\n");
    printf("\n Employee No    : %d", p->empno);
    printf("\n Name           : %s", p->empName);
    printf("\n Designation    : %s\n", p->designation);
    printf("-------------------------------------\n");
}

struct emp_data* deleteNode(struct emp_data *front, int id)
{
    struct emp_data *ptr;
    struct emp_data *bptr;

    if (front->empno == id)
    {
        ptr = front;
        printf("\n Node deleted:");
        printNode(front);
        front = front->next;
        free(ptr);
        return(front);
    }
    for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,
bptr = bptr->next)
    {
        if (ptr->empno == id)
        {
            printf("\n Node deleted:");
            printNode(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("\n Employee Number %d not found ", id);
    return(front);
}

void search(struct emp_data *front, int key)
{
    struct emp_data *ptr;

    for (ptr = front; ptr != NULL; ptr = ptr -> next)
    {
        if (ptr->empno == key)
        {
            printf("\n Key found:");
            printNode(ptr);
            return;
        }
    }
    printf("\n Employee Number %d not found ", key);
}

void display(struct emp_data  *front)
{
    struct emp_data *ptr;

    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printNode(ptr);
    }
}

void menu()
{
    printf("---------------------------------------------\n");
    printf("Enter option: \n");
    printf("1 to INSERT a record into the database       \n");
    printf("2 to DELETE a record from the database       \n");
    printf("3 to DISPLAY the records                 \n");
    printf("4 to SEARCH the records                   \n");
    printf("5 to EXIT                              \n");
    printf("---------------------------------------------\n");
}


// main function
void main()
{
    struct emp_data *linkList;
    char name[21], desig[51];
    int choice;
    int eno;
    int flag = 0;

    linkList = NULL;
    printf("\n MAIN MENU \n");
    menu();

    while(flag != 1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n Enter the Employee Number: ");
                scanf("%d", &eno);
                printf(" Enter the Employee name: ");
                fflush(stdin);
                gets(name);
                printf(" Enter the Employee Designation: ");
                gets(desig);
                linkList = insert(linkList, eno, name, desig);
                break;

            case 2:
                printf("\n\n Enter the employee number to be deleted: ");
                scanf("%d", &eno);
                linkList = deleteNode(linkList, eno);
            break;

            case 3:
                if (linkList == NULL)
                {
                    printf("\n List is empty.");
                    break;
                }
                display(linkList);
            break;

            case 4:
                printf("\n\n Enter the employee number to be searched: ");
                scanf("%d", &eno);
                search(linkList, eno);
            break;

            case 5:
            exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

}
