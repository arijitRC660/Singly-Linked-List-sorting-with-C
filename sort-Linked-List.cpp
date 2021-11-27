#include <stdio.h>
#include <stdlib.h>
/*creating the node type structure*/
struct node {
    int data;
    struct node *next;
};
typedef struct node node; //Abstruction
node *head , *start = NULL;

void addNode(int num)
{
    head = (node*)malloc(sizeof(node)); //creating node
    head->data = num; //adding data to node
    
    if(start !=NULL)
    {
        node* temp = start;
        while(temp->next !=NULL)
        temp=temp->next;

        head->next = temp->next;
        temp->next = head;
    }
    else 
    {
         head->next = start;
        start  = head;
    }
}
void display()
{
   
    node *temp = start;

    while(temp)
    {
        printf("%d ",temp->data); //printing the data of node
        temp=temp->next; //updating the temp's address
    }

}
void sortNode()
{
    node* current = start , *prevNode , *listTemp;
    //applying selection sort technique
    while(current)
    {
        int min = current->data; 
        prevNode = current->next;
        while(prevNode)
        {
            if(prevNode->data < min)
            {
                min = prevNode->data;
                listTemp = prevNode;
            }
            prevNode=prevNode->next;
        }
        int temp = listTemp->data;
        listTemp->data = current->data;
        current->data = temp;

        current=current->next;
    }
}

int main()
{
    int size;
    printf("How  many data do you want to enter: ");
    scanf("%d",&size);
    int *arr = (int*)malloc(size * sizeof(int)); //allocating memory to store data

    printf("Enter data: ");
    for(int i=0;i<size;++i)
    scanf("%d",&arr[i]);

    for(int i=0;i<size;++i)
    addNode(arr[i]);

    printf("Before sorting: ");
    display();
    printf("\n");

    sortNode();
    printf("After sorting: ");
    display();

    printf("\n");
    system("pause");
    return 0;
    

}
