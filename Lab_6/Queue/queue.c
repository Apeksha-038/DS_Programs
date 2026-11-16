#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front=NULL, *rear=NULL;

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)), *temp;
    if(newNode==NULL){
        printf("\nMemory Allocation failed");
        return;
    }


    newNode->data=val;
    newNode->next=NULL;
    if(front==NULL && rear==NULL){
        front = rear = newNode;
        rear->next=NULL;
        return;
    }

    temp = rear;
    temp->next=newNode;
    rear=newNode;
}

void pop(){
if(front==NULL && rear==NULL){
    printf("\n Queue underflow");
    return;
}

struct Node* temp=front;
printf("\nThe elements popped is: %d", temp->data);
front=front->next;
if(front==NULL){
    rear = NULL;
}
free(temp);


}


void display()
{
if(front==NULL && rear==NULL){
    printf("\n Queue underflow");
    return;
}

struct Node* temp=front;
while(temp!=NULL){
    printf("%d\t", temp->data);
    temp=temp->next;
}

}


int main(){
int choice,num, ans;

while(1){
    printf("\nEnter the choice: \n");
    printf("\n1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%d", &choice);
    switch(choice){
case 1:
    printf("\nEnter the value to push: ");
    scanf("%d",&num);
    push(num);
    break;

case 2:
    pop();
    break;
case 3:
    display();
    break;


case 4:
    printf("----EXITING-----");
    exit(0);
}
}

return 0;
}
