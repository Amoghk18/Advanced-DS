#include<bits/stdc++.h>
using namespace std;

void printExceptTwoGreatest(vector<int> &vec){
    sort(vec.begin(), vec.end());
    cout << "The values except two largest ones are: ";
    for(int i=0; i<vec.size()-2; i++){
        cout << vec[i] << " ";
    }
}

int main(){
    vector<int> vec;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: " << endl;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    printExceptTwoGreatest(vec);
    return 0;
}