cmake_minimum_required(VERSION 3.12)
project(HomeAutomation)

set(CMAKE_CXX_STANDARD 11)

add_executable(HomeAutomation main.cc UtilityServer.cc UtilityServer.h)

target_link_libraries(HomeAutomation boost_system)
