#include "Players.h"



Players::Players()
{
}


Players::~Players()
{
}

void Players::Show() const
{
	std::cout << id << ", ���� 1:" << score1 << "(" << rank1 << ")��, ���� 2:"
		<< score2 << "(" << rank2 << ")��" << std::endl;
}