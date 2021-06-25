#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *link;
};

struct Node *first;   //pointer first created in stack

void createLinkedList(int* A, int n){
    struct Node *temp, *last;   
    first = new Node;  //struct node created in heap
    first->data = A[0];
    first->link = NULL;
    last = first;
    for (int i = 1; i < n;i++){              
        temp = new Node;
        temp->data = A[i];
        temp->link = NULL;
        last->link = temp;
        last=temp;

    }
}


void displayLinkedList(struct Node *p){

    
    while(p!=NULL){

        cout << p->data<<" ";
        p = p->link;
    }
}


int countNodes(struct Node *p){

    int count = 0;
    while(p!=NULL){

        count++;
        p = p->link;
      
    }
    cout <<count<<" nodes";
    return count;
}



void sum( struct Node* p){
   int sum = 0;
   while (p != NULL)
   {
       sum = sum + (p->data);
       p = p->link;
    }

    cout << sum;
}
int Rsum( struct Node* p){
  if(p==NULL)
      return 0;

  else{

      return Rsum(p->link) + p->data;
  }
  
}

void maxElement(struct Node* p){
    int m=p->data;
    p = p->link;
    while(p!=NULL){
        if(m < p->data){
            m = p->data;
        }
        p = p->link;
    }
    cout << m << " is the greatest element";
}


int RmaxElement(struct Node*p){
   static  int mx = 0;
    if(p==NULL){
        mx = -32678; //lowest possible int
        return mx;
    }
    else{
        RmaxElement(p->link);
        if(p->data >mx){
            mx = p->data;
            return mx;
        }
    }
}
int RminElement(struct Node*p){
   static  int mn = 0;
    if(p==NULL){
        mn = 32678; //largest possible int
        return mn;
    }
    else{
        RminElement(p->link);
        if(p->data <mn){
            mn = p->data;
            return mn;
        }
    }
}


void searchElement(struct Node*p,int key){
    while(p!=NULL){
            if((p->data)==key){
                cout << key << " exists";
            }
                p = p->link;
}
}

void improvedLinearSearch(struct Node*p, int key){

    struct Node* q;
    q = NULL;
    while(p){
        if(p->data==key){
            cout << "found" << endl;
            q->link = p->link;       //move to head method
            p->link=first;                      
            first = p;
            break;
        }
        q = p;
        p = p->link;
    }
}

void RimprovedLinearSearch(struct Node*p,struct Node*q,int key){

    if(p==NULL){
        cout << "Element not found";
    }

    else{
        if(p->data==key){
             cout << "found" << endl;
            q->link = p->link;       //move to head method
            p->link=first;                      
            first = p;
            return;
        }
        else RimprovedLinearSearch(p->link, p, 24);
    }

}


void insertFirstNode(int x){

    struct Node *head = new Node;
    head->data = x;

    head->link =first;
    first = head;
}


void insertMidNode(struct Node *p, int x,int index){
struct Node* t = new Node;
t->data = x;
for (int i = 0; i <=index;i++){
    if(i==index){
    t->link = p->link;
    p->link = t;
    }
   else p = p->link;
    }
    
}

void reverseLLData(struct Node*p){

    int a[10];
    int i = 0;
    while(p!=NULL){
        a[i] = p->data;
        p = p->link;
        i++;
    }
    p = first;
    i=i-1;
    while(p!=NULL){
        p->data = a[i];
        p = p->link;
        i--;
    }
}

void reverseLLNode(struct Node*p){

    struct Node *q= NULL;
    struct Node *r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;
}
int RreverseLLNode(struct Node*p,struct Node*q){

   
    if(p!=NULL){
        RreverseLLNode(p->link, p);
        p->link = q;
    }

    else
        first = q;
}



int main(){
//R= USING RECURSION
    int A[5] = {5,15,25,35,45};
    createLinkedList(A, 5);
    // displayLinkedList(first);
    // countNodes(first);
    // sum(first);
    // cout<<Rsum(first);
    // maxElement(first);
    // cout<< RmaxElement(first)<<" is the greatest element";
    // cout<< RminElement(first)<<" is the smallest element";
    // searchElement(first, 24); //no binary search in LL as LL is not indexed unlike array. bs's time complexity be same as ls so ls preffered.
    // improvedLinearSearch(first, 24);
    // RimprovedLinearSearch(first, NULL, 24);
    // insertFirstNode(10);
    // insertMidNode(first,69,9);
    // reverseLLData(first);
    // reverseLLNode(first);
    // RreverseLLNode(first,NULL); //sliding pointers
    // displayLinkedList(first);
    return 0;
}

