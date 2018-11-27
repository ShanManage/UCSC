#include <bits/stdc++.h>
using namespace std;
#define MAX 10

vector<pair<int , int>> hashTable[MAX];

int hash_func(int key){
    return key % MAX;
}

int searchKey(int key){
    vector<pair<int , int>> cell = hashTable[hash_func(key)];

    for (int i = 0; i < cell.size(); i++){
        if(cell[i].first == key)
            return cell[i].second;
    }    

    return 0;
}

void insertKey(int key , int val){
    if(!searchKey(key))
        hashTable[hash_func(key)].push_back(make_pair(key , val));
    else
        cout << "Alrady exists.!\n";
}

int main(){
    insertKey(22 , 100);
    insertKey(25 , 200);
    insertKey(10 , 300);
    insertKey(15 , 400);
    insertKey(36 , 500);
    insertKey(41 , 600);

    int n;
    cout << "Key : ";
    cin >> n;

    if (searchKey(n))
        cout << n << " : " << searchKey(n);
    else 
        cout << "no key found.!";    

    printf("\n");
}



