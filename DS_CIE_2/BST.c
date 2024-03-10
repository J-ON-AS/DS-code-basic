//Binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void bst(struct node *new,struct node *root)
{
    if(new->data>root->data&&root->next==NULL)
    {
        root->next=new;
    }
    else if(new->data<root->data&&root->prev==NULL)
    {
        root->prev=new;
    }
    else
    {
        if(new->data>root->data)
        {
            bst(new,root->next);
        }
        if(new->data<root->data)
        {
            bst(new,root->prev);
        }
    }
}
struct node *trav()
{
    int i;
    struct node *Firstnode,*Newnode,*temp;
    Firstnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for node: ");
    scanf("%d",&Firstnode->data);
    Firstnode->prev=NULL;
    Firstnode->next=NULL;
    temp=Firstnode;
    while(1)
    {
        Newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node: ");
        scanf("%d",&i);
        if(i==-1)
        {
            break;
        }
        Newnode->data=i;
        Newnode->prev=NULL;
        Newnode->next=NULL;
        bst(Newnode,Firstnode);
    }
    return Firstnode;
}
void inorder(struct node *innode)
{
    if(innode!=NULL)
    {
        inorder(innode->prev);
        printf("%d ",innode->data);
        inorder(innode->next);
    }
}
void del(struct node **root,struct node **nxt,int n)
{
    struct node *ext;
    if((*nxt)->data==n)
    {
        if((*nxt)->next==NULL && (*nxt)->prev==NULL)
        {
            if((*root)->next==(*nxt))
            (*root)->next=NULL;
            else{
            (*root)->prev=NULL;
            free((nxt));
            (*nxt)=NULL;
            return;
            }
        }
        else if((*nxt)->next!=NULL && (*nxt)->prev==NULL)
        {
            if((*root)==(*nxt))
            {
                ext=(*nxt);
                (*nxt)=(*nxt)->next;
                free(ext);
                return;
            }
            ext=(*nxt);
            if((*root)->next==(*nxt))
            (*root)->next=(*nxt)->next;
            else
            (*root)->prev=(*nxt)->next;
            free(ext);
            return;
        }
        else if((*nxt)->next==NULL && (*nxt)->prev!=NULL)
        {
            if((*root)==(*nxt))
            {
                ext=(*nxt);
                (*nxt)=(*nxt)->prev;
                free(ext);
                return;
            }
            ext=(*nxt);
            if((*root)->next==(*nxt))
            (*root)->next=(*nxt)->prev;
            else
            (*root)->prev=(*nxt)->prev;
            free(ext);
            return;
        }
        else
        {
            ext=(*nxt)->next;
            int i=(*nxt)->data;
            (*nxt)->data=ext->data;
            ext->data=i;
            del(nxt,&ext,n);
        }
    }
    else if((*nxt)->data>n)
    del(nxt,&((*nxt)->prev),n);
    else
    del(nxt,&((*nxt)->next),n);
}
void main()
{
    int n;
    struct node *innode;
    innode=trav();
    inorder(innode);
    printf("\nEnter value to be deleted:");
    scanf("%d",&n);
    del(&innode,&innode,n);
    inorder(innode);
}