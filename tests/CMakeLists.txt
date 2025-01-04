cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14, upgrading to C++17 for string_view support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Manually specify the path to SQLite3 library and include directory
set(SQLITE3_LIB_PATH ${CMAKE_SOURCE_DIR}/../sqlite3.lib)
set(SQLITE3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../)  # Директорія, де знаходиться sqlite3.h

# Check if the library and header files exist
if (EXISTS ${SQLITE3_LIB_PATH} AND EXISTS ${SQLITE3_INCLUDE_DIR}/sqlite3.h)
    message(STATUS "SQLite3 library found at ${SQLITE3_LIB_PATH}")
    include_directories(${SQLITE3_INCLUDE_DIR})
else()
    message(FATAL_ERROR "SQLite3 library or header not found.")
endif()

# Define hello_test executable
add_executable(hello_test hello_test.cpp)
target_link_libraries(hello_test GTest::gtest_main)

# Define HashTable_test executable
add_executable(HashTable_test HashTable_test.cpp ../data_structures/HashTable.cpp)
target_link_libraries(HashTable_test GTest::gtest_main)

# Define Database_test executable
add_executable(Database_test Database_test.cpp ../database/database.cpp)
target_link_libraries(Database_test GTest::gtest_main ${SQLITE3_LIB_PATH})

# Automatically discover and add tests
include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(HashTable_test)
gtest_discover_tests(Database_test)
