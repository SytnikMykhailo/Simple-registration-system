
#include "../sqlite3.h"

class Database{
public:
    Database(const char *name);
    void open_db(const char *name);
    void create_table();
    void delete_table();
    void delete_user(int id);
    int find_user(const char *email);
    char* get_user_data(int id);
    void insert_user(int id, const char *email, const char *password, const char *name, const char *surname, const char *note);
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    ~Database();
private:
    sqlite3 *db;
    const char *name;
};