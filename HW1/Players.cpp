#include "Players.h"



Players::Players()
{
}


Players::~Players()
{
}

void Players::Show1() const
{
	std::cout << id << ", 점수 1:" << score1 << "(" << rank1 << ")등" << std::endl;
}
void Players::Show2() const
{
	std::cout << id << ", 점수 2:" << score2 << "(" << rank2 << ")등" << std::endl;
}

void Players::Show() const
{
	std::cout << id << ", 점수 1:" << score1 << "(" << rank1 << ")등, 점수 2:" 
									<< score2 << "(" << rank2 << ")등" << std::endl;
}