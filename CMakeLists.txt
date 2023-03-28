cmake_minimum_required(VERSION 3.12)
project(minesweeper CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(minesweeper_core src/MinesweeperBoard.cpp src/MSBoardTextView.cpp src/MSTextController.cpp)
target_include_directories(minesweeper_core PUBLIC include)

add_executable(minesweeper src/main.cpp)
target_link_libraries(minesweeper minesweeper_core)






