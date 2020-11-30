#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
# define max 10
typedef struct Node{
    int data;
    struct Node *next;
} node;

class Dictionary{
public:
    int index;
    node *ptr[max],*root[max],*temp[max];

    Dictionary(){
        index=-1;
        for(int i=0; i<max; i++){
            root[i] = NULL;
            ptr[i] = NULL;
            temp[i] = NULL;
        }
    }

    void insert(int key){
        index = int(key % max);
        ptr[index] = (node*)malloc(sizeof(node));
        ptr[index]->data = key;
        if(root[index] == NULL){
            root[index] = ptr[index];
            root[index]->next = NULL;
            temp[index] = ptr[index];
        }
        else{
            temp[index] = root[index];
            while(temp[index]->next != NULL){
                temp[index] = temp[index]->next;
            }
            temp[index]->next = ptr[index];
        }
    }
    void search(int key){
        int flag = 0;
        index = int(key % max);
        temp[index] = root[index];
        while(temp[index] != NULL){
            if(temp[index]->data == key){
                cout<<"\nFound at "<<index<<endl;
                flag = 1;
                break;
            }
            else temp[index] = temp[index]->next;
        }
        if (flag==0) cout<<"\nNot Found\n";
    }
};

int main(){
    int x = 0;
    Dictionary dict;
    do{
        cout<<"Enter\n1. To Insert";
        cout<<"\n2. To Search\n3. To Exit\n";
        cin>>x;
        switch(x){
            case 1:
                cout<<"\nEnter the element to be inserted:";
                cin>>x;
                dict.insert(x);
                break;
            case 2:
                cout<<"\nEnter the element to be searched:";
                cin>>x;
                dict.search(x);
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Choice.";
        }
        x = 0;
    }while(x == 0);
    return 0;
}