#include <iostream>
#include "screen.h"

void Screen::new_screen()
{
	std::cout<<"\x1b[?47h";
}

void Screen::previous_screen()
{
	std::cout<<"\x1b[?47l";
}

void Screen::clear_screen()
{
	std::cout<<"\x1b[2J";
}

void Screen::move_cursor_to(int line,int column)
{
	std::cout<<"\x1b["<<line<<';'<<column<<'H';
}
