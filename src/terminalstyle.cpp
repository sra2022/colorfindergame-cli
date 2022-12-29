#include "terminalstyle.h"
#include <iostream>
#include <string>
#include <cassert>

Color::Color(int r,int g,int b) : m_r{r},m_g{g},m_b{b}
{
	assert(r>=0 && r<256 && g>=0 && g<256 && b>=0 && b<256);
}

Fgcolor::Fgcolor(int r,int g,int b) : Color{r,g,b}
{
}

std::ostream& operator<<(std::ostream& out,const Fgcolor& fgcolor)
{
	out<<"\x1b[38;2;"<<fgcolor.m_r<<';'<<fgcolor.m_g<<';'<<fgcolor.m_b<<'m';
	return out;
}

Bgcolor::Bgcolor(int r,int g,int b) : Color{r,g,b}
{
}

std::ostream& operator<<(std::ostream& out,const Bgcolor& bgcolor)
{
	out<<"\x1b[48;2;"<<bgcolor.m_r<<';'<<bgcolor.m_g<<';'<<bgcolor.m_b<<'m';
	return out;
}

namespace Style
{
	std::string reset_string{"\x1b[0m"};
	const std::string& reset()
	{
		return reset_string;
	}

	std::string bold_string{"\x1b[1m"};
	const std::string& bold()
	{
		return bold_string;
	}
}
