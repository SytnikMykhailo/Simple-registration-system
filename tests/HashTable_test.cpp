#include "../data_structures/HashTable.h"
#include <gtest/gtest.h>
#include <iostream>


TEST(HashTableTest, AssertionTest){
    HashTable hashTable = HashTable();
    hashTable.insert("key", "value");
    hashTable.insert("key2", "value2");

    char *value = hashTable.search("key");
    ASSERT_STREQ(value, "value");
}

TEST(HashTableTest, DeleteTest){
    HashTable hashTable = HashTable();
    hashTable.insert("key", "value");
    hashTable.insert("key2", "value2");

    hashTable.deleteKey("key");
    char *value = hashTable.search("key");
    ASSERT_EQ(value, nullptr);
    std::cout << "1" << std::endl;
    hashTable.deleteKey("key2");
    value = hashTable.search("key2");
    ASSERT_EQ(value, nullptr);
    std::cout << "2" << std::endl;
    hashTable.insert("key", "value");
    hashTable.insert("key2", "value");
    std::cout << "3" << std::endl;
    hashTable.deleteKey("key2");
    value = hashTable.search("key2");
    ASSERT_EQ(value, nullptr);
}


