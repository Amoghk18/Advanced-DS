#include<bits/stdc++.h>
using namespace std;

void uniqueDigits(int l, int r){
    vector<char> vec;
    for(int i=l; i<r+1; i++){
        string s = to_string(i);
        int flag = 0;
        for(char c : s){
            if(find(vec.begin(), vec.end(), c) != vec.end()){
                flag = 1;
                break;
            }
            else{
                vec.push_back(c);
            }
        }
        if(flag == 0){
            cout << i << " ";
        }
        vec.clear();
    }
}

int main(){
    int l, r;
    cout << "Enter the left extreme: ";
    cin >> l;
    cout << "Enter the right extreme: ";
    cin >> r;
    uniqueDigits(l, r);
    return 0;
}