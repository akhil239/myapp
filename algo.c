#include<stdio.h>
#include<stdlib.h>



struct Node
{   int data;
    struct Node *next;
    /* data */
};
int add_node(int data);
void traverse();
int del_node_pos();
struct Node *ptr = NULL;

int main(){
    add_node(50);
    add_node(500);
    add_node(570);
    add_node(545);
    add_node(5370);
    del_node_pos(1);
    printf("%d",ptr->data);
    traverse();
    return 0;
}
int del_node_pos(int pos){
    int count = 0 ;
    struct Node *current = ptr;
    while(count != pos){
        current = current->next;
        count += 1;
    }
    printf("we are at %d",count);
}
int add_node(int data){
    if(ptr == NULL){
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        printf("new node as created sccuessfully...");
        return 0;
    }else{
        struct Node *current = ptr;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = (struct Node *)malloc(sizeof(struct Node));
        current->next->data = data;
        current->next->next = NULL;
    }

}
void traverse(){
    struct Node *current = ptr;
    while (current != NULL)
    {   printf("\n%d",current->data);
        current = current->next;
        /* code */
    }
    

}