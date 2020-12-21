#include <bits/stdc++.h> 
using namespace std; 

struct Node{ 
	int val, degree; 
	Node *parent, *child, *sibling; 
}; 

Node *root = NULL; 

void link(Node *h1, Node *h2){
	h1->parent = h2; 
	h1->sibling = h2->child; 
	h2->child = h1; 
	h2->degree = h2->degree + 1; 
} 


Node *createNode(int n){
	Node *new_node = new Node; 
	new_node->val = n; 
	new_node->parent = NULL; 
	new_node->sibling = NULL; 
	new_node->child = NULL; 
	new_node->degree = 0; 
	return new_node; 
} 


Node *mergeBH(Node *h1, Node *h2) {
	if (h1 == NULL) return h2; 
	if (h2 == NULL) return h1; 
	Node *res = NULL; 
	if (h1->degree <= h2->degree) res = h1; 
	else if (h1->degree > h2->degree) res = h2; 
	while (h1 != NULL && h2 != NULL){
		if (h1->degree < h2->degree) h1 = h1->sibling; 
		else if (h1->degree == h2->degree){
			Node *sib = h1->sibling; 
			h1->sibling = h2; 
			h1 = sib; 
		}
		else{ 
			Node *sib = h2->sibling; 
			h2->sibling = h1; 
			h2 = sib; 
		} 
	} 
	return res; 
} 

Node *unionBH(Node *h1, Node *h2){
	if (h1 == NULL && h2 == NULL) return NULL; 
	Node *res = mergeBH(h1, h2); 
	Node *prev = NULL, *curr = res, 
	*next = curr->sibling; 
	while (next != NULL){
		if ((curr->degree != next->degree) || ((next->sibling != NULL) && (next->sibling)->degree == curr->degree)){
			prev = curr; 
			curr = next; 
		} 
		else{
			if (curr->val <= next->val){
				curr->sibling = next->sibling; 
				link(next, curr); 
			} 
			else{
				if (prev == NULL) res = next; 
				else prev->sibling = next; 
				link(curr, next); 
				curr = next; 
			} 
		} 
		next = curr->sibling; 
	} 
	return res; 
} 


void insertBH(int x){
	root = unionBH(root, createNode(x)); 
} 


void display(Node *h){
	while (h){
		cout << h->val << " "; 
		display(h->child); 
		h = h->sibling; 
	} 
} 

void revl(Node *h){ 
	if (h->sibling != NULL){
		revl(h->sibling); 
		(h->sibling)->sibling = h; 
	} 
	else root = h; 
} 


Node *extractMin(Node *h){
	if (h == NULL) return NULL; 
	Node *min_node_prev = NULL; 
	Node *min_node = h; 
	int min = h->val; 
	Node *curr = h; 
	while (curr->sibling != NULL){
		if ((curr->sibling)->val < min) {
			min = (curr->sibling)->val; 
			min_node_prev = curr; 
			min_node = curr->sibling; 
		} 
		curr = curr->sibling; 
	} 
	if (min_node_prev == NULL && min_node->sibling == NULL) h = NULL; 
	else if (min_node_prev == NULL) h = min_node->sibling; 
	else min_node_prev->sibling = min_node->sibling; 
	if (min_node->child != NULL){
		revl(min_node->child); 
		(min_node->child)->sibling = NULL; 
	} 
	return unionBH(h, root); 
} 


Node *findNode(Node *h, int val){
	if (h == NULL) return NULL; 
	if (h->val == val) return h; 
	Node *res = findNode(h->child, val); 
	if (res != NULL) 
	return res; 
	return findNode(h->sibling, val); 
} 



void decKeyBH(Node *H, int old_val, int new_val){
	Node *node = findNode(H, old_val); 
	if (node == NULL) return; 
	node->val = new_val; 
	Node *parent = node->parent; 	
	while (parent != NULL && node->val < parent->val){
		swap(node->val, parent->val); 
		node = parent; 
		parent = parent->parent; 
	} 
} 


Node *deleteBH(Node *h, int val){
	if (h == NULL) return NULL; 
	decKeyBH(h, val, INT_MIN); 
	return extractMin(h); 
} 


int main(){
	// insertBH(10); 
	// insertBH(20); 
	// insertBH(30); 
	// insertBH(40); 
	// insertBH(50); 
	// cout << "The heap is:\n"; 
	// display(root); 
	// root = deleteBH(root, 10); 
	// cout << "\nAfter deleing 10, the heap is:\n"; 
	// display(root); 
	// return 0; 
    int x = 0;
    while(x == 0){
        cout << "Enter 1 to insert, 2 to delete, 3 to print the heap, 4 to exit" << endl;
        cin >> x;
        switch (x){
            case 1:
                cout << "Enter the number to be inserted" << endl;
                cin >> x;
                insertBH(x);
                break;
            case 2:
                cout << "Enter the number to be deleted" << endl;
                cin >> x;
                root = deleteBH(root, x);
                break; 
            case 3:
                cout << "Heap: ";
                display(root);
                cout << endl;
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Not a valid input" << endl;
                break;
        }
        x = 0;
    }
	return 0; 
} 
