#include "Players.h"



Players::Players()
{
}


Players::~Players()
{
}

void Players::Show1() const
{
	std::cout << id << ", ÄíÅ°ÈÆ·Ã¼Ò : " << score1 << "(" << rank1 << ")µî" << std::endl;
}
void Players::Show2() const
{
	std::cout << id << ", ¶¼Å»Ãâ : " << score2 << "(" << rank2 << ")µî" << std::endl;
}

void Players::Show() const
{
	std::cout << id << ", ÄíÅ°ÈÆ·Ã¼Ò : " << score1 << "(" << rank1 << ")µî, ¶¼Å»Ãâ : " 
									<< score2 << "(" << rank2 << ")µî" << std::endl;
}

void Players::My_Show() const
{
	std::cout << id << ", ÄíÅ°ÈÆ·Ã¼Ò : " << score1 << "(" << rank1 << ")µî" << std::endl;
	std::cout << "ÄíÅ°ÈÆ·Ã¼Ò ·©Å· º¯È­ : " << rank1 - past_rank1 << std::endl;
	
	std::cout << id << ", ¶¼Å»Ãâ : " << score2 << "(" << rank2 << ")µî" << std::endl;
	std::cout << "‹óÅ»Ãâ ·©Å· º¯È­ : " << rank2 - past_rank2 << std::endl;
}