#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;
// print linked list
void print_list(node_t* head){
    node_t * curr = head; // allow iteration without destorying head*
    curr = curr->next; // do not print first node
    // iterate through list
    while(curr != NULL){
        
        if(curr->next == NULL){
            // print last node
            printf("%d\n", curr->val);
        }
        else{
            printf("%d -> ", curr->val); 
        }
        
        curr = curr->next;
    }   
}
// delete node at index i 
void delete(node_t * head, int index){
    node_t * curr = head; // allow iteration without destorying head*
    int i = 1; // track current position
        // check if index of last item
    if(index == head->val){
        //printf("last item needs to be removed\n");
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        curr->next = NULL;
    }
    else{
        while(i < index){
           curr = curr->next;
           i++;
        }
        curr->next = curr->next->next;
    }
    head->val--; // decrement length
    //printf("Deleted @%d\n", index);

}
// removes all nodes with specific value
int remove_all(node_t* head, int val){
    node_t * curr = head; // allow iteration without destorying head*
    curr = curr->next; // skip first node
    int i = 1;// track index
    int count = 0;
    // iterate through list
    while(curr->next != NULL){
        if(curr->val == val){
            delete(head,i);
            count++;
        }
        i++;
    }
    return count;
}
int remove_duplicates(node_t* head){
    
    node_t * curr = head; // allow iteration without destorying head*
    curr = curr->next; // skip first node
    node_t * dup = curr; // pointer for duplicate locating
    int count = 0; // count number of nodes removed
    int i = 1; // track index
    int j = 1; // track duplicate index
    // outer iterattion through list
    while(curr->next != NULL){
        // dup points to node after curr
        dup = curr->next;
        j = i+1; // define inner loop index
       // printf("index %d = %d\n", i, curr->val);
        // inner iteration
        while(dup != NULL){
           // printf("    dup @%d = %d\n", j, dup->val);
            if(dup->val == curr->val){
                delete(head,j);
                count++;
                j--; // prevent j index from incrementing later
            }
            dup = dup->next; // increment 
            j++;
        }
        i++;
        if(curr->next != NULL){
            // safe to continue
            curr = curr->next;  
        }
        else{
            // final element was removed
            break;
        }
        
    }
    return count;
}
//   1 -> 2 -> 3 -> 4 -> 5
//   1 <- 2 -> 3 -> 4 -> 5
//   d
//        c
//             t
// reverse order of singly linked list
void reverse(node_t* head){
    node_t * curr = head; // allow iteration without destorying head*
    curr = curr->next; // skip first node
    node_t * dup = curr; // 
    node_t * temp = curr; // temporary 
    // advance pointer to current last node
    while(curr->next->next != NULL){
        dup = curr;
        curr = curr->next;
        temp = dup->next->next;
        dup->next = dup;
        //curr = curr->next;
    }
    


}
// add node to end of list
void add_node(node_t* head, int val){
    node_t * curr = head; // allow iteration without destorying head*
    // create new node to add
    node_t * new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL; 
    // advance pointer to current last node
    while(curr->next != NULL){
        curr = curr->next;
    }
    // add new node
    curr->next = new_node;
    // update length in head
    head->val++;
    //printf("Added %d\n", val);
}

int main(int argc, char *argv[])
{
    node_t * head;
    head = (node_t *) malloc(sizeof(node_t));
    head->val = 0;
    head->next = NULL;
    //prompt user input
    printf("Define length of list: ");
    // get user input
    int num = 0;
    scanf("%d", &num); // reads user input
    while ( getchar() != '\n' ); // clear ENTER key from buffer

    // choose random number, used to select word
    int index; //  chosen random index
    srand(time(NULL));            // seed with time
    
    // populate linked list with random vals 1-10
    for(int i = 0; i < num; i++){
        index = (rand() % 10); // 1-10
        add_node(head, index);
    }
    print_list(head);
    delete(head, 10);
    print_list(head);
    printf("Removed %d duplicates!\n", remove_duplicates(head));

    print_list(head);
    reverse(head);
    print_list(head);



}