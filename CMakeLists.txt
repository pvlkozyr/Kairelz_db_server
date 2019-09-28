cmake_minimum_required(VERSION 3.14)
project(Kairelz_db_server)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
find_package ( Threads REQUIRED )
add_executable(db_server
        Database.cpp
        Database.h
        gen.cpp
        gen.h
        th_serv.cpp Query.cpp Query.h)
add_executable(data_gen
        gen.cpp
        Database.cpp
        Database.h
        gen.h
        Query.cpp
        Query.h
        Record.h
        main.cpp
        )
add_executable(http_server
        Database.cpp
        Database.h
        gen.cpp
        gen.h
        Query.cpp Query.h http.cpp)
add_executable(client
        client.cpp)
target_link_libraries ( db_server ${CMAKE_THREAD_LIBS_INIT} )
target_link_libraries ( http_server ${CMAKE_THREAD_LIBS_INIT})
