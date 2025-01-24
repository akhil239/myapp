#include<stdio.h>
#include<stdlib.h>



struct Node
{   int data;
    struct Node *next;
    /* data */
};

int add_node(int data);
int traverse();
int del_node_pos(int pos);
int add_node_at_pos(int pos,int data);
int del_node_with_value(int value);
int length();
int mid_node();
void free_list();
struct Node *ptr = NULL;


int main(){
    // add_node(787);
    // add_node(3984);
    // traverse();
    // free_list();
    // printf("%p",ptr);
    char *arr[] = {"sldjsdjk",";sdifo;"};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("\n%s",arr[i]);
        /* code */
    }

    return 0;
    

}
void free_list(){
    struct Node *current = ptr;
    struct Node *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    ptr = NULL;
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
    current->next = temp;
    return 0;
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
    if(ptr == NULL && pos == 0 || pos > 0){
        ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        return 0;
    }
    if(pos > length()-1){
        printf("the position yoy proveded is not vaild... but i will place this at last position.");
        while(current->next != NULL){
            current = current->next;
        }
        current->next = (struct Node *)malloc(sizeof(struct Node));
        current->next->data = data;
        current->next->next = NULL;
        return 0;
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
int fisrt_node(){
    struct Node *first = ptr;
    return first->data;
}
int mid_node(){
    int mid = (length()/2) -1;
    struct Node *temp = ptr;
    for(int i= 0;i < mid; i++){
        if(temp->next != NULL){
            temp = temp->next;
        }
    }
    return temp->data;
}
int last_node(){
    struct Node *last = ptr;
    while (last->next != NULL)
    {
        last = last->next;
        /* code */
    }
    return last->data;
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
int traverse(){
    struct Node *current = ptr;
    if(ptr == NULL){
        printf("list is ematy ....");
        return -1;
    }
    while (current != NULL)
    {   printf("\n%d\n",current->data);
        current = current->next;
        /* code */
    }
}