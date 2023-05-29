cmake_minimum_required(VERSION 3.21)
project(project_abs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(project_abs
        src/main.cpp
        include/list.h
        include/listNode.h
        include/file.h
        src/file.cpp
        include/menu.h
        src/menu.cpp
        include/admin.h
        src/admin.cpp
        include/account.h
        src/account.cpp
        include/accountList.h
        src/accountList.cpp
        include/function.h
        src/function.cpp
        )
