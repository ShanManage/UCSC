#include <bits/stdc++.h>
#define MAX 10
using namespace std;

pair<int , int> hashTable[MAX];

int hash_func_1(int key){
    return key % MAX;
}

int hash_func_2(int key){
    return (key % (MAX-1)) + 1;
}

int searchKey(int key){
    int pos = hash_func_1(key);
    for(int i = 0; i < MAX; i++){
        if(hashTable[pos].first == key)
            return hashTable[pos].second;
        pos = (pos + 1) % MAX;
    }
    return 0;
} 

int hash_func(int key){
    for (int i = 1; i < (MAX-1)/2; i++){
        int pos = (hash_func_1(key) + i * hash_func_2(key)) % MAX;
        if(hashTable[pos].first == -1)
            return pos;
        }
    return 0;
}

void insertKey(int key , int val){
    int pos = hash_func_1(key);
    if(!searchKey(key)){
       if(hashTable[pos].first == -1){
           hashTable[pos].first = key;
           hashTable[pos].second = val;
       }else{
            int n = hash_func(key);
            if(n){
                hashTable[n].first = key;
                hashTable[n].second = val;
           }else
                cout << "hash table overflow.!\n";
       }
    }else
        cout << "Alrady exists.!\n";
}

void init(){
    for (int i = 0; i < MAX; i++){
        hashTable[i].first = -1;
    }
}

int main () {

    init();

    insertKey(22 , 100);
    insertKey(25 , 200);
    insertKey(10 , 300);
    insertKey(15 , 400);
    insertKey(36 , 500);
    insertKey(41 , 600);
    insertKey(12 , 100);
    insertKey(13 , 100);
    insertKey(14 , 100);
    insertKey(16 , 100);
    insertKey(17 , 100);

    int n;
    cout << "Key : ";
    cin >> n;

    if (searchKey(n))
        cout << n << " : " << searchKey(n);
    else 
        cout << "no key found.!";    

    printf("\n");
}