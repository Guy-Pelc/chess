cmake_minimum_required(VERSION 3.9)
project(ChessCLION)

#set(CMAKE_CXX_STANDARD 11)

#target_include_directories(src)
add_executable(ChessCLION chess.cpp bishop.cpp board.cpp king.cpp knight.cpp point.cpp queen.cpp rook.cpp
                soldier.cpp units.cpp unix.cpp)