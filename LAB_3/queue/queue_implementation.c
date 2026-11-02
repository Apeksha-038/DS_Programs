#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front =-1, rear=-1;

void insert(int val){
    if(rear==MAX-1){
        printf("\nQueue overflow");
    }
    if(front==-1 && rear ==-1){
        front = 0;
    }

    queue[++rear]= val;
    printf("\nThe added value is: %d",val);

}

int delete(){
    if((front==-1 && rear==-1) || front>rear){
        printf("\nQueue undrflow");
        return -1;
    }
    int val = queue[front];
    if(front==rear){
        front=rear=-1;
    }

    else{
        front++;
    }

    return val;
}

void display(){
    if(front==-1 && rear==-1){
        printf("\nQueue underflow");
    }
    printf("\nThe elements are: ");
    for(int i=front;i<=rear;i++){
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

int main(){
    int choice, n;
    while(1){
            printf("\n1.inserting, 2.deleting 3.display, 4.exit ");
            printf("\nEnter the choice: ");
            scanf("%d", &choice);
            switch(choice){
            case 1:
                printf("\nEnter the element to add:  ");
                scanf("%d", &n);
                insert(n);

                break;

            case 2:
                int num =  delete();
                if(num!=-1){
                    printf("\nThe deleted value is: %d", num);
                }

                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n-------Exiting------");
                exit(0);

            default:
                printf("\nEnter valid input");
            }

}

return 0;
}
