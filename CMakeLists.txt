cmake_minimum_required(VERSION 3.10)

project(ExpenseTracker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Qt libraries needed
find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

# Add the executable and source files
add_executable(ExpenseTracker main.cpp)

# Enable Qt's automoc to process Q_OBJECT macro
set_target_properties(ExpenseTracker PROPERTIES AUTOMOC ON)

# Link Qt libraries
target_link_libraries(ExpenseTracker Qt5::Widgets Qt5::Sql)
