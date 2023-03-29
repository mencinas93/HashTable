
#include<iostream>
#include <vector>


using namespace std;

/*
 1.    Starting with the code for Hash Table example (hash.cpp)
 1.1.    Write your own main and insert function to insert the sequence of integers { 138, 99, 16, 134, 42, 0, 6, 9, 4, 53, 47, 66) using a table of size 17.
 1.2.    Implement your own rehashing algorithm of choice and run the same sequence of input using a table of size 7.

 */
class HashEntry{
public:
      int key;
      int value;
      HashEntry(int key, int value) {
            this->key = key;
            this->value = value;
      }
    int getKey(){
        return key;
    }
    int getValue(){
        return value;
    }
};
//const int TABLE_SIZE = 17;
class HashMap {
private:
    int TABLE_SIZE;
    HashEntry** table;
public:
    HashMap(int tableSize) {
        TABLE_SIZE = tableSize;
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++){
            table[i] = NULL;
        }
    }
 
      int get(int key) {
            int hash = (key % TABLE_SIZE);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                  hash = (hash + 1) % TABLE_SIZE;
            if (table[hash] == NULL)
                  return -1;
            else
                  return table[hash]->getValue();
      }
 
    void insert(int key, int value) {
       int hash = (key % TABLE_SIZE);
        if (get(key) == -1) {
         table[hash] =  new HashEntry(key, value);
       } else {
           table[hash]->value = value;
       }
     
   };
   
    void print(HashMap& x){
        for(unsigned i = 0;i <TABLE_SIZE; i++){
            if(x.table[i] != NULL){
                cout << x.table[i]->value << " ";
            }
        }
        cout << endl;
    }
 
      ~HashMap() {
            for (int i = 0; i < TABLE_SIZE; i++)
                  if (table[i] != NULL)
                        delete table[i];
            delete[] table;
      }
};

//int my_hash(const int keyElement, int Tablesize);

int my_hash(const int keyElement, int Tablesize){
    return (keyElement*9 + 10) % Tablesize;
}

int main(int argc, const char * argv[])
{
    int tablesize_one = 17;
    int tablesize_two = 7;
    int itemsCount = 12;
    int value = 0;
    HashMap Kirsten(tablesize_one);
    cout << "Enter your values to be inserted: ";
    //138, 99,16,134,42,0,6,9,4,53,47,66
    
    
    for (int i = 0; i < itemsCount; i++){
        cin >> value;
        Kirsten.insert(i, value);
        cout << my_hash(value, tablesize_one)<< endl;
    }
    cout << "First Hashmap table size is " << tablesize_one << endl;
    Kirsten.print(Kirsten);
   
    HashMap Kirsten2(tablesize_two);
    for (int i = 0; i < itemsCount; i++){
        value=Kirsten.get(i);
        if(value!= -1)
            Kirsten2.insert(my_hash(i,tablesize_two), value);
      //  cout << my_hash(i, tablesize_two) << endl;
        }
    cout << "Second Hashmap table size is " << tablesize_two << endl;
    Kirsten2.print(Kirsten2);
       
    
    return 0;
}
