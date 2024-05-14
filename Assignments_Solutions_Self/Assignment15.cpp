#include <iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
private:
node *root;


/*Some of extra functions are made in protected section because root is a private variable and cannot be accessed by object and 
passed as a parameter in the function. So we have designed a preorderpro function in which root will be passed by preorder
function.Now,we know preorder function is a member function so it can access root and pass it to the insertpro function.
Now you would think that Why preorderpro function is not directly accessing the root? The answer is that if we directly access the
member variable root then the member variable root's value will change and it will not point to first node.Also if we make copy 
member variable root in some other variable ptr then in recursion again and again ptr will be assigned root that is the first node
but we want ptr value should be assigned according to calling function so that is why we made this extra function.
Similar reason for inorderpro and postorderpro functions.
Also we have made these extra function protected so that they cannot be accesesd by the object of this class*/
protected:
void preorderpro(node *);
void inorderpro(node *);
void postorderpro(node *);
int delinorderpro(node *,int);
node* deleteNode(node *,int);

public:
BST();
bool isEmpty();
void insert(int);
void preorder();
void inorder();
void postorder();
void del(int);
node* search(int);
~BST();
};
BST::BST()
{
    root=NULL;
}
bool BST::isEmpty()
{
    return root==NULL;
}
void BST::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(isEmpty())
    {
        root=n;
    }
    else
    {
        node *ptr=root;
        while(ptr!=NULL)
        {
            if(ptr->item==data)
            {
                cout<<"Duplicate value cannot be inserted in binary search tree"<<endl;
                delete n;
                break;
            }
            else if(data<(ptr->item))
            {
                if(ptr->left==NULL)
                {
                    ptr->left=n;
                    break;
                }
                ptr=ptr->left;
            }
            else if(data>(ptr->item))
            {
                if(ptr->right==NULL)
                {
                    ptr->right=n;
                    break;
                }
                ptr=ptr->right;
            }
        }
    }
}
void BST::preorderpro(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->item<<" ";
        preorderpro(ptr->left);
        preorderpro(ptr->right);
    }
}
void BST::preorder()
{
    preorderpro(root);
}   
void BST::inorderpro(node *ptr)
{
    if(ptr)
    {
        inorderpro(ptr->left);
        cout<<ptr->item<<" ";
        inorderpro(ptr->right);
    }
}
void BST::inorder()
{
    inorderpro(root);
}   
void BST::postorderpro(node *ptr)
{
    if(ptr)
    {
        postorderpro(ptr->left);
        postorderpro(ptr->right);
        cout<<ptr->item<<" ";
    }
}
void BST::postorder()
{
    postorderpro(root);
}
node* BST::search(int data)
{
    node *t=root;
    while(t!=NULL)
    {
    if(data==(t->item))
    {
    break;
    }
    else if(data<(t->item))
    {
        t=t->left;
    }
    else if(data>(t->item))
    {
        t=t->right;
    }
    } 
    return t; //If element not found at last or tree is empty then NULL will be present in t and that will be returned 
} 
int BST::delinorderpro(node *ptr,int data)
{
    int x;
    if(ptr)
    {
        delinorderpro(ptr->left,data);
        if(ptr->item==data)
        return x;
        x=(ptr->item);
        delinorderpro(ptr->right,data);
    }
}
node* BST::deleteNode(node*ptr, int data)
{
    if(ptr==NULL)
        return NULL;
    if(data < ptr->item)
        ptr->left=deleteNode(ptr->left,data);
    else if(data > ptr->item)
        ptr->right=deleteNode(ptr->right,data);
    else
    {
        //No child
        if(ptr->left==NULL && ptr->right==NULL)
        {
            delete ptr;
            return NULL;
        }
        //single child
        if(ptr->left==NULL || ptr->right==NULL)
        {
            node *child=ptr->left?ptr->left:ptr->right;
            delete ptr;
            return child;
        }
        //two children
        node* pred, *parpred;
        parpred=ptr;
        pred=ptr->left;
        while(pred->right!=NULL)
        {
            parpred=pred;
            pred=pred->right;
        }
        ptr->item=pred->item;
        if(parpred->right==pred)
            parpred->right=deleteNode(pred, pred->item);
        else if(parpred->left==pred)
            parpred->left=deleteNode(pred,pred->item);
        
    }
    return ptr;
}
void BST::del(int data)
{
    root=deleteNode(root,data);
}
BST::~BST()
{
    while (root!=NULL)
    {
        del(root->item);
    }
}

