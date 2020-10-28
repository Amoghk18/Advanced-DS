#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        int h;
};

int maxi(int a, int b){
    return a > b ? a : b;
}

Node* createNode(int data){
    Node* newnode = new Node();
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->h = 1;
    return newnode;
}

int giveh(Node* n){
    if(n == NULL) return 0;
    return n->h;
}

Node* rotateLeft(Node* node){
    Node* r = node->right;
    Node* leftOfr = r->left;

    r->left = node;
    node->right = leftOfr;
    r->h = maxi(giveh(r->left), giveh(r->right)) + 1;
    node->h = maxi(giveh(node->left), giveh(node->right)) + 1;
    return r;
}

Node* rotateRight(Node* node){
    Node* l = node->left;
    Node* rightOfl = l->right;

    l->right = node;
    node->left = rightOfl;
    l->h = maxi(giveh(l->left), giveh(l->right)) + 1;
    node->h = maxi(giveh(node->left), giveh(node->right)) + 1;
    return l;
}

Node* insertAVL(Node* root, int data){
    if(root == NULL){
        return (createNode(data));
    }
    if(root->val > data){
        root->left = insertAVL(root->left, data);
    }
    else if(root->val < data){
        root->right = insertAVL(root->right, data);
    }
    else{
        return root;
    }
    root->h = maxi(giveh(root->left), giveh(root->right)) + 1;
    int bal = giveh(root->left) - giveh(root->right);
    if(bal < -1 && data > root->right->val){
        return rotateLeft(root);
    }
    if(bal < -1 && data < root->right->val){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    if(bal > 1 && data < root->left->val){
        return rotateRight(root);
    }
    if(bal > 1 && data > root->left->val){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    return root;
}

Node* deleteAVL(Node* root, int data){  
    if (root == NULL) return root;  
    if (data < root->val){
        root->left = deleteAVL(root->left, data);
    } 
    else if(data > root->val){
        root->right = deleteAVL(root->right, data);
    }
    else{  
        if((root->left == NULL) || (root->right == NULL)){  
            Node* t;
            if(root->left != NULL) t = root->left;
            else t = root->right;

            if(t == NULL){  
                t = root; 
                root = NULL;  
            }  
            else *root = *t; 
            free(t);  
        }  
        else{  
            Node* t = root->right;
            while(t->left != NULL){
                t = t->left;
            }
            root->val = t->val;
            root->right = deleteAVL(root->right, t->val);  
        }  
    }  
    if (root == NULL)  
    return root;  
    root->h = maxi(giveh(root->left), giveh(root->right)) + 1;  
    int bal = giveh(root->left) - giveh(root->right);  
    if(bal > 1 && (giveh(root->left->left) - giveh(root->left->right)) >= 0){
        return rotateRight(root);
    }
    if(bal > 1 && (giveh(root->left->left) - giveh(root->left->right)) < 0){  
        root->left = rotateLeft(root->left);  
        return rotateRight(root);  
    }
    if(bal < -1 && (giveh(root->right->left) - giveh(root->right->right)) <= 0){
        return rotateLeft(root);
    }
    if(bal < -1 && (giveh(root->right->left) - giveh(root->right->right)) > 0){  
        root->right = rotateRight(root->right);  
        return rotateLeft(root);  
    }
    return root;  
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    Node* root = NULL;
    int x = 0;
    int n;
    while(x==0){
        cout << "Enter \n 1 to insert \n 2 to delete \n 3 to print \n 4 to exit" << endl;
        cin >> x;
        switch(x){
        case 1:
            cout << "Enter number to be inserted : ";
            cin >> n;  
            root = insertAVL(root, n);
            break;
        case 2:
            if(root == NULL){
                cout << "Cannot delete as tree is empty" << endl;
                break;
            }
            cout << "Enter number to be deleted : ";
            cin >> n;
            root = deleteAVL(root, n);
            break;
        case 3:
            if(root == NULL){
                cout << "Nothing to show, Tree is NULL" <<  endl;
                break;
            }
            cout << "Preorder : ";
            printPreorder(root);
            cout << "" << endl;
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

/*
root = insertAVL(root, 50);
    root = insertAVL(root, 30);
    root = insertAVL(root, 70);
    root = insertAVL(root, 15);
    root = insertAVL(root, 85);
    root = insertAVL(root, 80);
    cout << "Inorder : ";
    printInorder(root);
    cout << "" << endl;
    root = insertAVL(root, 10);
    cout << "Inorder : ";
    printInorder(root);
    cout << "" << endl;
    root = insertAVL(root, 5);
    cout << "Inorder : ";
    printInorder(root);
    cout << "" << endl;
    root = insertAVL(root, 13);
    cout << "Inorder : ";
    printInorder(root);
    cout << "" << endl;
    deleteAVL(root, 70);
    cout << "Inorder : ";
    printInorder(root);
    cout << "" << endl;
*/
