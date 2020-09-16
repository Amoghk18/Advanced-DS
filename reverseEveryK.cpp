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

Node* revLL(Node* start, Node* end){
    Node* curr = start;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != end)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
    return start;
}

Node* revK(Node* head, int k){
    int cnt = 0;
    Node* curr = head;
    Node* ohead = head;
    Node* newHead = NULL;
    Node* retHead = NULL;
    int reverseCnt = 0;
    Node* prevTempHead = NULL;
    Node* arr[2];
    while(curr != NULL){
        cnt++;
        if(cnt % k == 0){
            Node* tempHead = ohead;
            Node* tempNext = curr->next;
            cout<< cnt << " " << curr->val << endl;
            newHead = revLL(ohead, curr->next);
            arr[reverseCnt] = newHead;
            reverseCnt++;
            if(reverseCnt == 1){
                retHead = newHead;
            }
            prevTempHead->next = newHead;
            tempHead->next = tempNext;
            curr = tempNext;
            ohead = tempNext;
            prevTempHead = tempHead;
            continue;
        }
        curr = curr->next;
    }
    // Node *newList = arr[0];
    // for(int i=0; i < 1;i++){
    //     Node* p = newList;
    //     while(p->next != NULL){
    //         p = p->next;
    //     }
    //     p->next = arr[i+1];
    // }

    return retHead;
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
