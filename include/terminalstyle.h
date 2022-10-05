#ifndef TERMINAL_STYLE_NIGHT_04_10_2022
#define TERMINAL_STYLE_NIGHT_04_10_2022
#include <iostream>
#include <string>

class Color
{
	protected:
		int m_r{};
		int m_g{};
		int m_b{};
	public:
		Color(int r=0,int g=0,int b=0);
};

class Fgcolor : public Color
{
	public:
		Fgcolor(int r=0,int g=0,int b=0);
		friend std::ostream& operator<<(std::ostream& out,const Fgcolor& fgcolor);
};

class Bgcolor : public Color
{
	public:
		Bgcolor(int r=0,int g=0,int b=0);
		friend std::ostream& operator<<(std::ostream& out,const Bgcolor& bgcolor);
};

namespace Style
{
	const std::string& reset();
	const std::string& bold();
}

#endif
