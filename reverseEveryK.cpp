#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
        int val;
        Node *next;
};

void insert_front(Node** head, int data){
    Node* newNode = new Node();
    newNode->val = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void printit(Node* head){
    Node *p = head;
    while(p!=NULL){
        cout << p->val << endl;
        p = p->next;
    }
}

Node* reverseit (Node *head, int k)  
{  
    Node* current = head;  
    Node* next = NULL;  
    Node* prev = NULL;  
    int count = 0;  
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
    if (next != NULL)  
    head->next = reverseit(next, k);  
    return prev;  
} 

int main(){
    Node* head = NULL;
    insert_front(&head, 8);
    insert_front(&head, 7);
    insert_front(&head, 6);
    insert_front(&head, 5);
    insert_front(&head, 4);
    insert_front(&head, 3);
    insert_front(&head, 2);
    insert_front(&head, 1);
    head = reverseit(head, 3);
    printit(head);
    return 0;
}
