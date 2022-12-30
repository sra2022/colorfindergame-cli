#include "randomnumber.h"
#include "terminalstyle.h"
#include "screen.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <ctime>

void ignore_line()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void print_rules()
{
	Screen::clear_screen();
	Screen::move_cursor_to(0,0);
	std::cout<<Style::bold()<<std::setw(41)<<"COLOUR FINDER GAME"<<Style::reset()<<"\n\n";
	std::cout<<">> One square is different in color\n>> Find the square which is different in colour\n>> You have 1 minute\n";
	std::cout<<">> Get maximum points within the time\n>> Press 0 anytime to exit\n>> Press y to start the game\n";
}

void print_points(int points)
{
	std::cout<<'\n'<<std::setw(60)<<"POINTS : "<<points<<'\n';
}

void print_points_final(int points)
{
	std::cout<<">> "<<Style::bold()<<"POINTS : "<<points<<Style::reset()<<'\n';
}

void draw_squares(int correct_answer)
{
	int r=Random::get(50,225);
	int g=Random::get(50,225);
	int b=Random::get(50,225);
	Fgcolor black{0,0,0};
	Fgcolor fgcolor{r,g,b};
	Fgcolor fgcolor2{r-15,g-15,b-15};
	Bgcolor bgcolor{r,g,b};
	Bgcolor bgcolor2{r-15,g-15,b-15};
	std::cout<<'\n';
	int box_number{1};
	int row{1};
	while (row<=6)
	{
		int semirow{1};
		while (semirow<=4)
		{
			int column{1};
			while (column<=8)
			{
				if (box_number==correct_answer && (semirow==1 || semirow==3))
					std::cout<<"  "<<fgcolor2<<bgcolor2<<std::setw(6)<<box_number<<Style::reset();
				if (box_number==correct_answer && semirow==2)
					std::cout<<"  "<<black<<bgcolor2<<std::setw(6)<<box_number<<Style::reset();
				if (box_number!=correct_answer && (semirow==1 || semirow==3))
					std::cout<<"  "<<fgcolor<<bgcolor<<std::setw(6)<<box_number<<Style::reset();
				if (box_number!=correct_answer && semirow==2)
					std::cout<<"  "<<black<<bgcolor<<std::setw(6)<<box_number<<Style::reset();
				if (column==8)
				{
					std::cout<<'\n';
					box_number-=7;
				}
				else
					box_number++;
				column++;
			}
			if (semirow==4)
				std::cout<<'\n';
			semirow++;
		}
		row++;
		box_number+=8;
	}
}

int get_player_input()
{
	while(true)
	{
		std::cout<<">> Enter answer : ";
		int answer{};
		std::cin>>answer;
		if (std::cin.fail() || answer<0 || answer>48)
		{
			std::cin.clear();
			ignore_line();
			std::cerr<<">> Answer must be the number of any of the boxes or press 0 to exit!\n";
		}
		else
		{
			ignore_line();
			return answer;
		}
	}
}

int game()
{
	int score{};
	std::time_t game_time=std::time(NULL)+60;
	while(std::time(NULL)<=game_time)
	{
		Screen::clear_screen();
		Screen::move_cursor_to(0,0);
		print_points(score);
		int correct_answer=Random::get(1,48);
		draw_squares(correct_answer);
		int player_input{get_player_input()};
		if (player_input==0)
			break;
		else if (player_input!=correct_answer)
		{
			std::cout<<">> Wrong! Correct answer is "<<correct_answer<<'\n';
			break;
		}
		else
			score++;
	}
	return score;
}

void start_game()
{
	char answer{};
	std::cout<<">> Start game? ";
	std::cin>>answer;
	ignore_line;
	if(answer=='y' || answer=='Y')
	{
		int points=game();
		print_points_final(points);
	}
}

int main()
{
	print_rules();
	start_game();
	return 0;
}
