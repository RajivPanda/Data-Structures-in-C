/* This program is compiled using GCC compiler*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

    void insert(int *, int pos, int num);
    void del(int*, int pos);
    void reverse(int *);
    void display(int *);
    void search(int *, int num);

int main()
{
    int arr[MAX], i, num, pos, choice;
    char ch;
    system("clear");

    printf("Enter The elements into the array:");
    for(i=1; i<=MAX; i++)
    {
        scanf("%d",&num);
        insert(arr, i, num);
    }

    do
    {
        system("clear");
        printf("Elements of the Array:");
        display(arr);
        printf("\nEnter your choice: \n1.Insert \n2.Delete \n3.Reverse \n4.Search \n5.Display");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the number and it's position to insert:");
            scanf("%d %d",&num, &pos);
            insert(arr, pos, num);
            printf("After insertion:\n");
            display(arr);
            break;

            case 2:
            printf("Enter the position of the number to delete it:");
            scanf("%d",&pos);
            del(arr, pos);
            printf("After deletion:\n");
            display(arr);
            break;

            case 3:
            printf("The Array after reversing is:");
            reverse(arr);
            display(arr);
            break;

            case 4:
            printf("Enter the number to search it's position:");
            scanf("%d",&num);
            search(arr, num);
            break;

            case 5:
            printf("The elements currently prresent in the array are:");
            display(arr);
            break;

            default:
            printf("Please provide a valid input.");
        }

    printf("\nDo you want to try again?(Y/N)");
    ch=getche();
    
    }while(ch=='y'||'Y');

    return 0;
}

/*Inserts an element num at given position pos*/
void insert(int *arr, int pos, int num)
{
    /*Shifts Elements to the right*/
    int i;
    for(i=MAX-1; i>=pos; i--)
        arr[i]=arr[i-1];
    arr[i]=num;
}

/*deletes an element from the given position pos*/
void del(int *arr, int pos)
{
    /*Skip to the desired position*/
    int j;
    for(j=pos; j<MAX; j++)
        arr[j-1]=arr[j];
    arr[j-1]=0;
}

/*Reverses the entire Array*/
void reverse(int *arr)
{
    int i;
    for(i=0; i<MAX/2; i++)
    {
        int temp= arr[i];           //Switching
        arr[i]=arr[MAX-1-i];
        arr[MAX-1-i]=temp;
    }
}

/*Searches Array for a given element num*/
void search(int *arr,int num)
{
    /*Traverse the Array*/
    int i;
    for(i=0; i<MAX; i++)
    {
        if(arr[i]==num)
        {
            printf("\n\nThe element %d is present at %dth position.", num, i+1);
            break;
        }
    }

    if(i==MAX)
        printf("\n\nThe element %d is not present in the array",num);
}

/*Displays the contents of the Array*/
void display(int *arr)
{
    /*Traverse the enetire Array*/
    int i;
    printf("\n");
    for(i=0; i<MAX; i++)
        printf("%d\t",arr[i]);
}
