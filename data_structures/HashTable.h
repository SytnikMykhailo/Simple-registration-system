class HashTable{
public:
    HashTable();
    HashTable(int numberOfElements, int capacity);
    int hashFunction(const char *key);
    void setNode(struct node *node, char *key, char *value);
    void insert(const char *_key, const char *_value);
    void deleteKey(const char *key);
    char *search(const char *key);
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