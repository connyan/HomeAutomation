cmake_minimum_required(VERSION 3.12)
project(HomeAutomation)

set(CMAKE_CXX_STANDARD 14)

find_package( Threads REQUIRED )
find_package( Boost REQUIRED COMPONENTS)

add_executable(HomeAutomation
        src/main.cc src/WsServer.cc include/WsServer.h src/ConnectionHandler.cc include/ConnectionHandler.h include/ConnectionHandlerIF.h
        src/MessageHandler.cc include/MessageHandler.h include/MessageHandlerIF.h)

target_link_libraries(HomeAutomation ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )
target_include_directories(HomeAutomation PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include> )
