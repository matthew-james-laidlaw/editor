cmake_minimum_required(VERSION 3.22.1)
project(MANA)
set(CMAKE_CXX_STANDARD 20)

add_executable(mana main.cpp)
target_include_directories(mana PUBLIC ${PROJECT_SOURCE_DIR}/include)
