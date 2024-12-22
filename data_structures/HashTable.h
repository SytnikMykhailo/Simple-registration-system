class HashTable{
public:
    HashTable() = default;
    HashTable(int numberOfElements, int capacity);
    int hashFunction(HashTable &hashTable, char *key);
    ~HashTable();
private:
    int numberOfElements;
    int capacity;
    struct node **arr;
};

struct node{
    char *key;
    char *value;
    struct node *next;
};