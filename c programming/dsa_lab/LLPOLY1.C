#include <stdio.h>
#include <stdlib.h>
struct node{
    int num;
    int poww;
    struct node *link;
};
  
struct node* create(int coeff, int poww){
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr->num = coeff;
    ptr->poww = poww;
    ptr->link =NULL;
    return (ptr);
}

struct node* insert_end(struct node *head, int coeff, int poww){
    struct node *temp = create(coeff, poww);
    struct node *ptr;
    if(head == NULL){
        head = temp;
    }else{
        ptr = head;
        while(ptr->link != NULL){
            ptr=ptr->link;
        }
        ptr->link = temp;
    }
    return(head);
}

void traverse(struct node *head){
    struct node * temp;
    if(head == NULL){
        printf("The polynomial is empty");
    }else{
        temp = head;
        while(temp != NULL){
            if(temp->link == NULL){
                printf("%dx^%d",temp->num, temp->poww);
            }else{
                printf("%dx^%d --> ",temp->num, temp->poww);
            }
            temp = temp->link;
        }
    }
}

//a = coefficient 
//b = power
void addTwo(struct node* head1, struct node* head2){
    struct node *ptr1 = head1, *ptr2 = head2;
    int a, b;
    struct node *temp = NULL;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->poww == ptr2->poww){
            a = ptr1->num + ptr2->num;
            b = ptr1->poww;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->poww > ptr2->poww){
            a = ptr1->num;
            b = ptr1->poww;
            ptr1=ptr1->link;
        }else{
            a = ptr2->num;
            b = ptr2->poww;
            ptr2=ptr2->link;
        }
        temp = insert_end(temp, a, b);
    }
    if(ptr1 == NULL && ptr2 != NULL){
        while(ptr2 != NULL){
            temp = insert_end(temp, ptr2->num, ptr2-> poww);
            ptr2 = ptr2->link;
        }
    }
    if(ptr1 != NULL && ptr2 == NULL){
        while(ptr1 != NULL){
            temp = insert_end(temp, ptr1->num, ptr1-> poww);
            ptr1 = ptr1->link;
        }
    }
    traverse(temp);
}

// void addSort(struct node* head){
//     struct node *ptr1, *ptr2;
//     struct node *temp;
//     ptr1 = head;
//     while(ptr1 != NULL){
//         ptr2 = ptr1->link;
//         while (ptr2 != NULL){
//             if(ptr1->poww == ptr2->poww){
//                 ptr1->num = ptr1->num + ptr2->num;
//                 temp = ptr2;
//                 free(temp);
//             }
//             ptr2 = ptr2->link;
//         }
//         ptr1 = ptr1->link;
//     }
// }

void removeDuplicates(struct node* start)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;
 
        // Compare the picked element
        // with rest of the elements
        while (ptr2->link != NULL) {
 
            // If powerer of two elements are same
            if (ptr1->poww == ptr2->link->poww) {
 
                // Add their coefficients and put it in 1st element
                ptr1->num = ptr1->num + ptr2->link->num;
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
 
                // remove the 2nd element
                free(dup);
            }
            else
                ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
}

void multiplyTwo(struct node* head1, struct node* head2){
    struct node *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    int coeff, poww;
    struct node *temp =NULL;
    while(ptr1 != NULL){
        while(ptr2 != NULL){
            poww = ptr1->poww + ptr2->poww;
            coeff = ptr1->num * ptr2->num;
            temp = insert_end(temp, coeff, poww);
            ptr2 = ptr2->link;
        }
        ptr2 = head2;
        ptr1 = ptr1->link;
    }
    removeDuplicates(temp);
    traverse(temp);
}

int main()
{
    struct node *head1 = NULL;
    int coeff, poww;
    for(int i =0; i<2;i++){
        printf("Enter the Coefficient :\n");
        scanf("%d",&coeff);
        printf("Enter the Power :\n");
        scanf("%d",&poww);
        head1 = insert_end(head1, coeff,poww);    
    }
    printf("The first Polynomial is : \n");
    traverse(head1);
    printf("\n");
    struct node *head2 = NULL;
    for(int i =0; i<2;i++){
        printf("Enter the Coefficient :\n");
        scanf("%d",&coeff);
        printf("Enter the Power :\n");
        scanf("%d",&poww);
        head2 = insert_end(head2, coeff,poww);    
    }
    printf("The second Polynomial is : \n");
    traverse(head2);
    printf("\nThe addition of the two given Polynomial is :\n");
    addTwo(head1, head2);
    printf("\nThe multiplication of the two given Polynomial is :\n");
    multiplyTwo(head1, head2);
    
    printf("\n");    
    return 0;
}