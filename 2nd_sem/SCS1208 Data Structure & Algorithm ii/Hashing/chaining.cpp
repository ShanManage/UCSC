#include <bits/stdc++.h>
using namespace std;
#define MAX 10

vector<int> hashtable[MAX];

int h(int k){
    return k % MAX;
}

bool searchKey(int key){
    for (auto x : hashtable[h(key)]){
        if (key == x) return 1;
    }
    return 0;
}

void addKey(int key){
    if(!searchKey(key))
        hashtable[h(key)].push_back(key);
    else
        cout << "Already exist.!";
}

int main(){
    addKey(22);
    addKey(25);
    addKey(10);
    addKey(15);
    addKey(35);
    addKey(32);
    addKey(41);

    if(searchKey(41))
        cout << "here is the value.!\n";
    else
        cout << "no word found.!\n";

    return 0;
}