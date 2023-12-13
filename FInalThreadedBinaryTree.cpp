/*THIS IS A BINARY SEARCH TREE IMPLEMENTATION IF YOU WANT BINARY TREE ASK USER FOR CHOICE OF L/R AND 
  REPLACE (data<current->data) with choice==1 or choice ==2*/

#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    bool lthread;
    bool rthread;
    
    Node()
    {
        this->data = 0;
        this->left = this;
        this->right=this;
        rthread = lthread = true;
    }
    Node(int data)
    {
        this->data = data;
        this->left = this;
        this->right=this;
        rthread = lthread = true;
    }
};
class TBT
{
    
    Node* root=nullptr;
    Node *head=nullptr;
    public:
    TBT()
    {
        head = new Node(999);
    }
    void insert(int data)
    {
        if(head->lthread)
        {
            root= new Node(data);
            root->left= head;
            root->right=head;
            head->left=root;
            head->lthread=0;
        }
        else
        {
            Node* current = head->left;
            while(true)
            {
                if(data>current->data)
                {
                    if(current->rthread==true)
                    {
                        break;
                    }
                    current=current->right;
                }
                else if(data<current->data)
                {
                    if(current->lthread==true)
                    {
                        break;
                    }
                    current=current->left;
                }
                else{
                    return;
                }
            }
            Node* newNode = new Node(data);
            if(data<current->data)
            {
                newNode->left=current->left;
                current->lthread=0;
                current->left=newNode;
                newNode->lthread=1;
                newNode->right=current;
            }
            else{
                newNode->right=current->right;
                current->rthread=0;
                current->right=newNode;
                newNode->rthread=1;
                newNode->left=current;
            }
        }
    }
    bool searchNode(int data)
    {
        if(head->lthread==true)
        {
            return false;
        }
        Node* current = head->left;
        while(true)
        {
            if(data<current->data)
            {
                if(current->lthread==true)
                {
                    return false;
                }
                current=current->left;
            }
            else if(data>current->data)
            {
                if(current->rthread==true)
                {
                    return false;
                }
                current=current->right;
            }
            else
            {
                return true;
            }
        }

    }
    void inorderTraverse()
    {
        Node* current = head->left;
        while(current->lthread==false)
        {
            current=current->left;
        }
        while(current != head)
        {
            cout<<current->data<<" ";
            if(current->rthread==false)
            {
                current=current->right;
                while(current->lthread==false)
                {
                    current=current->left;
                }
            }
            else{
                current=current->right;
            }
        }
    }
    void preorderTraversal()
    {
        Node* current = head->left;
        while(current!=head)
        {
            cout<<current->data<<" ";
            if(current->lthread==false)
            {
                current=current->left;
            }
            else if(current->rthread==false)
            {
                current = current->right;
            }
            else
            {
                while(current->rthread==true)
                {
                    current=current->right;
                }
                current=current->right;
            }
        }
    }

};
int main()
{
    int a;
    TBT tree;
    while(cin>>a)
    {
        tree.insert(a);
    }
    cout<<"The inorder Traversal of the tree is : ";tree.inorderTraverse();
    cout<<endl;
    cout<<"The preorder Traversal of the tree is :";tree.preorderTraversal();
}