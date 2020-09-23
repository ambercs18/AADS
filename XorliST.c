#include <stdio.h>
#include <stdlib.h> 
#include <inttypes.h> 
struct node
{
    int d;
    struct node* next;
};
typedef struct node * Node;

Node Xor(Node a,Node b)
{
    return (Node) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

Node front(Node head,int v)
{
    Node new = (Node) malloc (sizeof (struct node) );
    new->d=v;
    new->next=head;
    if(head!=NULL)
    {
        head->next=Xor(new,head->next);
    }
    
    head=new;
    return head;
}

Node end(Node head,int v)
{
    Node new = (Node) malloc (sizeof (struct node));
    new->d=v;
    Node p=head;
    Node q=NULL;
    Node r;
    
    if(head==NULL)
    {
    head=new;
    return head;
    }
    else
    {
        while(p!=NULL)
        {
            r=Xor(q,p->next);
            q=p;
            p=r;
        }
        
        new->next=q;
        q->next=Xor(new,q->next);
        // printf("%d",q->d);
        return head;
    }
}

void printList (Node head) 
{ 
    Node curr = head; 
    Node prev = NULL; 
    Node next; 
  
    printf ("Following are the nodes of Linked List: \n"); 
  
    while (curr != NULL) 
    { 
        printf ("%d ", curr->d); 

        next = Xor (prev, curr->next); 
  
        prev = curr; 
        curr = next; 
    } 
} 
int main()
{
    Node head=NULL;
    
    head=front(head,10);
    head=front(head,20);
    head=front(head,30);
    printList(head);

    printf("\n");
    
    head=end(head,40);
    printList(head);
    

    return 0;
}
