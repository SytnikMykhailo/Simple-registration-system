#include <string_view>

enum user_status{
    unsigned_user = 1,
    signed_user = 2,
    admin = 4
};

class User{
    public:
    
    User() = default;
    User(std::string_view name, std::string_view surname, user_status status, std::string_view email, std::string_view password);
    User& set_name(std::string name);
    User& set_surname(std::string surname);
    User& set_name(user_status satus);
    User& set_email(std::string email);
    User& set_password(std::string password);

    private:

    std::string name = "John";
    std::string surname = "Developer";
    user_status status = unsigned_user;
    std::string email = "john.developer@develop";
    std::string password = "develop"; 
};