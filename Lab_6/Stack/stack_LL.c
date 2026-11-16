#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("\nMemory Allocation failed");
        return;
    }

    newNode->data=val;
    if(top==NULL){
        top=newNode;
        top->next=NULL;
        return;
    }

    newNode->next=top;
    top=newNode;
}

void pop(){
if(top==NULL){
    printf("\nStack underflow");
    return;
}

struct Node* temp=top;
printf("\nThe elements popped is: %d", temp->data);
top=top->next;
free(temp);


}
int peek(){
    if(top==NULL)
{
    printf("\nStack underflow");
    return -1;
}

return top->data;
}

void display()
{
    if(top==NULL)
{
    printf("\nStack underflow");
    return;
}

struct Node* temp=top;
while(temp!=NULL){
    printf("%d\t", temp->data);
    temp=temp->next;
}

}


int main(){
int choice,num, ans;

while(1){
    printf("\nEnter the choice: \n");
    printf("\n1.push\n2.pop\n3.display\n4.peek\n5.exit\n");
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
    ans = peek();
    if(ans!=-1){
        printf("\nThe top value is: %d", ans);
    }
    break;

case 5:
    printf("----EXITING-----");
    exit(0);
}
}

return 0;
}
