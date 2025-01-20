#include<stdio.h>
#include<stdlib.h>



struct Node
{   int data;
    struct Node *next;
    /* data */
};
int add_node(int data);
void traverse();
int del_node_pos(int pos);
int add_node_at_pos(int pos,int data);
int del_node_with_value(int value);
int length();
struct Node *ptr = NULL;


int main(){
     add_node(50);
     add_node(500);
     add_node(570);
     add_node(545);
    // add_node(5370);
    //del_node_with_value();
    add_node_at_pos(30,598);
    traverse();
    return 0;

}
int del_node_with_value(int value){
    struct Node *current = ptr;
    if(current == NULL){
        printf("this list is ematy.....");
        return -1;
    }
    if(current->data == value){
        if(current->next == NULL){
            free(current);
            return 0;
        }
        else{
            ptr = current->next;
            return 0;
        }
    }
    while(current->next->data != value){
        if(current->next->next == NULL){
            printf("\nelement not found in the list....\n");
            return 0;
        }
        current = current->next;
    }
    struct Node *temp = current->next->next;
    free(current->next);
    current->next = temp;
}
int length(){
    struct Node *temp = ptr;
    int count = 0; 
    while (temp != NULL)
    {   count +=1;
        temp = temp->next;
        /* code */
    }
    return count;
    
}
int add_node_at_pos(int pos,int data){
    int count = 0;
    struct Node *current = ptr;
    if(pos > length()-1){
        printf("the position yoy proveded is not vaild... but i will place this at last position.");
        while(current != NULL){
            current = current->next;
        }
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = data;
        current->next = NULL;
        return -1;
    }
    if(pos == -1){
        struct Node *temp = current;
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = data;
        current->next = temp;
        return 0;
    }
    while (count != pos){
        current = current->next;
        count += 1;
    }
    struct Node *current_next = current->next;
    current->next = (struct Node *)malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->next = current_next;

}
int del_node_pos(int pos){
    int count = 0 ;
    struct Node *current = ptr;
    struct Node *current_next_next = current->next->next;
    if(pos > length()-1){
        printf("position you proved is not vaild....");
        return -1;
    }
    if(current == NULL){
        printf("no element found in this list....");
        return -1;
    }
    if(pos == -1){
        ptr = current->next;
        return 0;
    }
    while(count != pos-1){
        current = current->next;
        count += 1;
    }
    printf("%d",pos);
    free(current->next);
    current->next = current_next_next;
    //printf("node deleted at %d",&pos);
//     printf("we are at %d",current->data);
//     printf("we are at %d",current_next_next->data);
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
    {   printf("\n%d\n",current->data);
        current = current->next;
        /* code */
    }
    

}