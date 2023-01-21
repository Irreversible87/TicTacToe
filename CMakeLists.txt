cmake_minimum_required(VERSION 3.25)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)

project(TicTacToe VERSION 1.0)

add_executable(
	TicTacToe 
	./TicTacToe/TicTacToe.cpp
	./TicTacToe/GameBoard.cpp
	./TicTacToe/Player.cpp
)
