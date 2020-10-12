#include <bits/stdc++.h> 
using namespace std; 

class DSet{ 
	vector<int> r, p; 
	int n; 
	
	public: 
	DSet(int n){ 
		r.resize(n); 
		p.resize(n); 
		this->n = n; 
		makeSet(); 
	} 

	void makeSet(){ 
		for (int i=0;i<n;i++){
            p[i] = i; 
        }
	} 

	int find(int x){ 
		if (p[x] != x){ 
			return find(p[x]); 
		} 
		return x; 
	} 

	void Union(int x, int y){
        int xR = find(x); 
        int yR = find(y);  
        if (xR == yR) 
            return; 
        if (r[xR] < r[yR]) 
            p[xR] = yR; 
        else if(r[yR]<r[xR]) 
            p[yR] = xR; 
        else{
            p[yR] = xR; 
            r[xR] = r[xR] + 1; 
        } 
    } 
}; 


void countNumberOfIslands(vector<vector<int>> &arr){ 
	int n = arr.size(); 
	int m = arr[0].size(); 
	DSet *dset = new DSet(n * m); 
	for (int i = 0; i < n; i++){ 
		for (int j = 0; j < m; j++){ 
			if (arr[i][j] == 0) 
				continue;

			if (i+1 < n && arr[i+1][j]==1){
                dset->Union(i*(m)+j, (i+1)*(m)+j); 
            }
            if (i-1 >= 0 && arr[i-1][j]==1){
                dset->Union(i*(m)+j, (i-1)*(m)+j);
            }
            if (j+1 < m && arr[i][j+1]==1){
                dset->Union(i*(m)+j, (i)*(m)+j+1);
            } 
            if (j-1 >= 0 && arr[i][j-1]==1){
                dset->Union(i*(m)+j, (i)*(m)+j-1);
            }
            if (i+1<n && j+1<m && arr[i+1][j+1]==1){
                dset->Union(i*(m)+j, (i+1)*(m)+j+1);
            }
            if (i+1<n && j-1>=0 && arr[i+1][j-1]==1){
                dset->Union(i*m+j, (i+1)*(m)+j-1);
            }
            if (i-1>=0 && j+1<m && arr[i-1][j+1]==1){
                dset->Union(i*m+j, (i-1)*m+j+1);
            }   
            if (i-1>=0 && j-1>=0 && arr[i-1][j-1]==1){
                dset->Union(i*m+j, (i-1)*m+j-1);
            }
		} 
	} 

	
	int *c = new int[n * m]; 
	int numberOfIslands = 0; 
	for (int i = 0; i < n; i++){ 
		for (int j = 0; j < m; j++){ 
			if (arr[i][j] == 1){ 
				int x = dset->find(i * m + j); 
				if (c[x] == 0){ 
					numberOfIslands++; 
					c[x]++; 
				} 
				else c[x]++; 
			} 
		} 
	} 
    cout << "Number of Islands are : " << numberOfIslands << endl;
} 


int main(void) 
{ 
	vector<vector<int>> arr;
    int n = 5; // later user input

    cout << "Enter the values in the 2d matrix" << endl;
    for(int i=0;i<n;i++){
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        arr.push_back(a);
    }

    countNumberOfIslands(arr);
    return 0;
} 

/*

DFS Approach

#include <bits/stdc++.h>
using namespace std;

bool v[5][5];

bool canGoDiaL(int r, int c){
    if(r < 4 && c > 0) return true;
    else return false;
}

bool canGoDown(int r){
    if(r < 4) return true;
    else return false;
}

bool canGoDiaR(int r, int c){
    if(r < 4 && c < 4) return true;
    else return false;
}

bool canGoLeft(int c){
    if(c < 4) return true;
    else return false;
}

int **canGoTo(int r, int c){
    int **arr = 0;
    arr = new int*[4];
    for(int i=0;i<4;i++){
        arr[i] = new int[2];
        arr[i][0] = -1;
        arr[i][1] = -1;
    }
    int top = 0;
    if(canGoDiaL(r, c)){
        arr[top][0] = r+1;
        arr[top][1] = c-1;
        top++;
    }
    if(canGoDown(r)){
        arr[top][0] = r+1;
        arr[top][1] = c;
        top++;
    }
    if(canGoDiaR(r, c)){
        arr[top][0] = r+1;
        arr[top][1] = c+1;
        top++;
    }
    if(canGoLeft(c)){
        arr[top][0] = r;
        arr[top][1] = c+1;
        top++;
    }
    return arr;
}

void gotoNearby(int arr[5][5], int r, int c){
    int **cangoto = canGoTo(r, c);
    for(int i=0;i<4; i++){
        if(cangoto[i][0] == -1 || cangoto[i][1] == -1){
            continue;
        }
        if(arr[cangoto[i][0]][cangoto[i][1]] == 1 && v[cangoto[i][0]][cangoto[i][1]] == false){
            //cout << "Nearby : " << cangoto[i][0] << " ," << cangoto[i][1] << endl;
            v[cangoto[i][0]][cangoto[i][1]] = true;
            gotoNearby(arr, cangoto[i][0], cangoto[i][1]);
        }
    }
}

void findIslands(int arr[5][5]){
    int count = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(v[i][j] == false && arr[i][j] == 1){
                v[i][j] = true;
                //cout << i << " ," << j << endl;
                gotoNearby(arr, i, j);
                count++;
            }
        }
    }
    cout << "Number of Islands are : " << count << endl;
}

int main(){
    int arr[5][5];
    cout << "Enter the values in the 2d matrix" << endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            v[i][j] = false;
            cin >> arr[i][j];
        }
    }
    findIslands(arr);
    return 0;
}

*/