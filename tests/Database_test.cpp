#include <gtest/gtest.h>
#include "../database/database.h"
#include "../sqlite3.h"

TEST(DatabaseTest, CreateDb) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());
    ASSERT_NO_THROW(db.insert_user("test@example.com", "password123", "John", "Doe", "Test note"));
    int user_id = db.find_user("test@example.com");
    EXPECT_EQ(user_id, 1);

    ASSERT_NO_THROW(db.delete_table());
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, OpenDB) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, CreateTable) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());
    ASSERT_NO_THROW(db.insert_user("test@example.com", "password123", "John", "Doe", "Test note"));
    int user_id = db.find_user("test@example.com");
    EXPECT_EQ(user_id, 1);

    ASSERT_NO_THROW(db.delete_table());
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, InsertUser) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());
    ASSERT_NO_THROW(db.insert_user("test@example.com", "password123", "John", "Doe", "Test note"));
    int user_id = db.find_user("test@example.com");
    EXPECT_EQ(user_id, 1);

    ASSERT_NO_THROW(db.delete_table());
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, DeleteUser) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());

    ASSERT_NO_THROW(db.insert_user("test@example.com", "password123", "John", "Doe", "Test note"));
    int user_id = db.find_user("test@example.com");
    EXPECT_EQ(user_id, 1);
    ASSERT_NO_THROW(db.delete_user(1));
    user_id = db.find_user("test@example.com");
    EXPECT_EQ(user_id, -1);

    ASSERT_NO_THROW(db.delete_table());
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, FindUser) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());

    ASSERT_NO_THROW(db.insert_user("test@example.com", "password123", "John", "Doe", "Test note"));
    int user_id = db.find_user("test@example.com");
    EXPECT_EQ(user_id, 1);

    ASSERT_NO_THROW(db.delete_table());
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, FindNonExistentUser) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());
    int user_id = db.find_user("nonexistent@example.com");
    EXPECT_EQ(user_id, -1);

    ASSERT_NO_THROW(db.delete_table());
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, GetUserData) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());
    ASSERT_NO_THROW(db.insert_user("test@example.com", "password123", "John", "Doe", "Test note"));
    char *data = db.get_user_data(1);
    ASSERT_NE(data, nullptr);

    ASSERT_NO_THROW(db.delete_table());
    ASSERT_NO_THROW(Database::delete_db("test.db"));
}

TEST(DatabaseTest, DeleteTable) {
    Database::create_db("test.db");
    Database db("test.db");

    ASSERT_NO_THROW(db.open_db("test.db"));
    ASSERT_NO_THROW(db.create_table());
    ASSERT_NO_THROW(db.delete_table());
    int user_id = db.find_user("test@example.com");
    EXPECT_EQ(user_id, -1);

    ASSERT_NO_THROW(Database::delete_db("test.db"));
}
