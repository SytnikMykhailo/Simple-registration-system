#include "user.h"

User::User() = default;
User::User(std::string_view name, std::string_view surname, user_status status, std::string_view email, std::string_view password){
    this->name = name;
    this->surname = surname;
    this->status = status;
    this->email = email;
    this->password = password;
}

User& User::set_name(std::string name){
    this->name = name;
    return *this;
}
User& User::set_surname(std::string surname){
    this->surname = surname;
    return *this;
}
User& User::set_name(user_status satus){
    this->status = status;
    return *this;
}
User& User::set_email(std::string email){
    this->email = email;
    return *this;
}
User& User::set_password(std::string password){
    this->password = password;
    return *this;
}
