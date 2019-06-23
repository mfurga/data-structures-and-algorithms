Creating a linked list
void CreateList(int n) { struct node NewNode, temp; int info; head=( struct node)malloc(sizeof(struct node)); /Enter the data for first node/ scanf("%d",&info); head->data=info; head->next=NULL; temp=head; int i; for(i=2;i<=n;i++) { NewNode=(struct node)malloc(sizeof(struct node)); if(NewNode==NULL) { break; } else { scanf("%d",&info); NewNode->data=info; NewNode->next =NULL; temp->next=NewNode; temp=temp->next; } } }

Displaying the entire list
void displayList() { struct node* temp; temp=head;

while(temp!=NULL)
{
    printf("%d ",temp->data);
    temp=temp->next;
}
}

Insertion at the end
void insend(int r) { struct node *t,temp; t=(struct node)malloc(sizeof(struct node));

if(head==NULL)
{
    head=t;
    head->data=r;
    head->next=NULL;
    return ;
}
temp=head;
while(temp->next!=NULL)

    temp=temp->next;
    temp->next=t;
    t->data=r;
    t->next=NULL;
}

Insertion at the beginning
void insbeg(int o) { 
struct node t; t=(struct node)malloc(sizeof (struct node));
 if(START==NULL)
 { START=t;
 START->data=o; 
 START->next=NULL;
 return 0; 
 } t->data=o; 
 t->next=START;
 START=t; 
 }

Deleting the entire list
void deleteList2() { struct node *temp;

while(START!=NULL)
{
    temp= START;
    START = START->next;

    free(temp);
}
}

Deleting the first element
void pop() {

struct node*t;
int n;

if(START==NULL)
{
    printf("stack underflow\n");
    return;
}
n=START->data;
printf("%d\n",n);
t=START->next;
free(START);
START=t;
