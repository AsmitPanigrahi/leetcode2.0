//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node*ptr=NULL,*p=NULL;
        while(node1!=NULL)
        {
            ptr=node1;
            node1=node1->next;
            ptr->next=p;
            p=ptr;
        }
        node1=ptr;
        ptr=NULL,p=ptr;
        while(node2!=NULL)
        {
            ptr=node2;
            node2=node2->next;
            ptr->next=p;
            p=ptr;
        }
        node2=ptr;

     // into decending order
        ptr=NULL,p=ptr;
        if(node1==NULL)
        return node2;
        if(node2==NULL)
        return node1;
        
        if(node1->data<=node2->data)
        {
            p=node2;
            ptr=node2;
            node2=node2->next;
        }
        else
        {
            p=node1;
            ptr=node1;
            node1=node1->next;
        }
        while(node1!=NULL&&node2!=NULL)
        {
            if(node1->data>=node2->data)
            {
                ptr->next=node1;
                node1=node1->next;
            }
            else
            {
                ptr->next=node2;
                node2=node2->next;
                
            }
            ptr=ptr->next;
            
        }
        while(node1!=NULL)
        {
            ptr->next=node1;
            ptr=node1;
            node1=node1->next;
        }
         while(node2!=NULL)
        {
            ptr->next=node2;
            ptr=node2;
            node2=node2->next;
        }

      //merge 
        ptr->next=NULL;
        return p;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends