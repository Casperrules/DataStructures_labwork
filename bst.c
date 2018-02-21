#include<stdio.h>
#include<stdlib.h>
struct treenode
{
struct treenode *left;
int data;
struct treenode *right;
};

struct treenode *current;

struct treenode *parent;

struct treenode *root;


void insert(int data) // inserting a node in the tree
{
struct treenode *temp=(struct treenode*)malloc(sizeof(struct treenode));
temp->data=data;
temp->left =NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;//if no root , add the first node at root position
return;
}
else
{
current=root;
parent=NULL;
while(1)//iterate until find a place
{
parent=current;
if(data<parent->data)//if data>new_data, go left
{
current=current->left;
if(current==NULL){
parent->left=temp; return;}//inserting at left
}
else//new_data>data then go right
{
current=current->right;
if(current==NULL)
{parent->right=temp; return;}//inserting at right
}
}
}
}


struct treenode * search(int data)//searching given data
{
current=root;
while(current->data!=data)
{
if(current!=NULL){
if(data>current->data)//go to right
current=current->right;
else//got to left
current=current->left;
}
if(current==NULL)//data not found
return NULL;
}
return current; //pointer to the node where the data exist
}

void del(int data)
{

current=root;
parent=NULL;
while(current->data!=data)
{
parent=current;
if(current->data>data)
{
current=current->left;
}
else
{
current=current->right;
}

}
if(parent->left==current)
parent->left=NULL;
else
parent->right=NULL;
}

void inorder(struct treenode *root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d  ",root->data);
inorder(root->right);
}
}

void main()
{
insert(1);
insert(2);
insert(3);
insert(4);
inorder(&root);
del(4);
inorder(&root);

}
