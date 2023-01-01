CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
VPATH = src : include

colorfindergame : main.cpp terminalstyle.cpp terminalstyle.h screen.cpp screen.h randomnumber.cpp randomnumber.h
	$(CXX) $(CXXFLAGS) -I include $^ -o $@
