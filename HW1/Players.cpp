#include "Players.h"



Players::Players()
{
}


Players::~Players()
{
}

void Players::Show1() const
{
	std::cout << id << ", ���� 1:" << score1 << "(" << rank1 << ")��" << std::endl;
}
void Players::Show2() const
{
	std::cout << id << ", ���� 2:" << score2 << "(" << rank2 << ")��" << std::endl;
}

void Players::Show() const
{
	std::cout << id << ", ���� 1:" << score1 << "(" << rank1 << ")��, ���� 2:" 
									<< score2 << "(" << rank2 << ")��" << std::endl;
}