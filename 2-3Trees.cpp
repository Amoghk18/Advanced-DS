#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int lval, rval;
        Node* left;
        Node* middle;
        Node* right;
};

Node* createNode(int val){
    Node* newnode = new Node();
    newnode->lval = val;
    newnode->rval = -1;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->middle = NULL;
    return newnode;
}

Node* insert(Node* root, int val){
    if(root == NULL) return createNode(val);
    if(root->rval == -1 && val > root->lval){
        root->rval = val;
    }
    else{
        if(val < root->lval)
            root->left = insert(root->left, val);
        else if(val > root->rval)
            root->right = insert(root->right, val);
        else if(val < root->rval && val > root->lval)
            root->middle = insert(root->middle, val);
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL) return root;
    if(val < root->lval)
        root->left = deleteNode(root->left, val);
    else if(val < root->rval && val > root->lval)
        root->middle = deleteNode(root->middle, val);
    else if(val > root->rval && root->rval != -1)
        root->right = deleteNode(root->right, val);
    else if(val == root->lval || val == root->rval){
        if(root->lval == val){
            if(root->left == NULL){
                if(root->right != NULL){
                    root->lval = root->right->lval;
                    root->right->lval = root->right->rval;
                    root->right->rval = -1;
                }
                else if(root->rval != -1){
                    root->lval = root->rval;
                    root->rval = -1;
                }
                else return NULL;
            }else{
                if(root->rval != -1){
                    root->lval = root->rval;
                    root->rval = -1;
                }
                else{
                    if(root->left->rval != -1){
                        root->lval = root->left->rval;
                        root->left->rval = -1;
                    }
                    else{
                        root->lval = root->left->lval;
                        root->left = NULL;
                    }
                }
            }
        }else if(root->rval == val){
            if(root->right == NULL){
                root->rval = -1;
            }else{
                root->rval = root->right->rval;
                root->right->rval = -1;   
            }
        }
    }
    return root;
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    if(root->rval == -1 && root->lval == -1){
        return;
    }
    if(root->rval == -1){
        cout << root->lval << ":" << "- ";
    }else{
        cout << root->lval << ":" << root->rval << " ";   
    }
    printPreorder(root->left);
    printPreorder(root->middle);
    printPreorder(root->right);
}

int main(){
    Node* root = NULL;
    int x = 0;
    while(x==0){
        cout << "Enter \n 1 to insert \n 2 to delete \n 3 to print \n 4 to exit" << endl;
        cin >> x;
        switch(x){
        case 1:
            cout << "Enter number to be inserted : ";
            cin >> x;  
            root = insert(root, x);
            break;
        case 2:
            if(root == NULL){
                cout << "Cannot delete as tree is empty" << endl;
                break;
            }
            cout << "Enter number to be deleted : ";
            cin >> x;
            root = deleteNode(root, x);
            break;
        case 3:
            if(root == NULL){
                cout << "Nothing to show, Tree is NULL" <<  endl;
                break;
            }
            cout << "Preorder : ";
            printPreorder(root);
            cout << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Enter valid number";
            break;
        }
        x = 0;
    }
    return 0;
}

// root = insert(root, 40);
//     root = insert(root, 20);
//     root = insert(root, 60);
//     root = insert(root, 10);
//     root = insert(root, 50);
//     root = insert(root, 55);
//     root = insert(root, 80);
//     root = insert(root, 70);
//     root = insert(root, 75);
//     printPreorder(root);
//     cout << endl;
//     deleteNode(root, 60);
//     printPreorder(root);
//     cout << endl;