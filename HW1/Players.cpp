#include "Players.h"

Players::Players()
{
}


Players::~Players()
{
}

void Players::Show1() const
{
	std::cout << "=================================" << std::endl;
	std::cout << id << ", ÄíÅ°ÈÆ·Ã¼Ò : " << score1 << "Á¡ (" << rank1 << ")µî"
		<< ", ÄíÅ°ÈÆ·Ã¼Ò ·©Å· º¯È­ : " << past_rank1 - rank1
		<< ", »óÀ§ " << rank1*0.001 << "%" << std::endl;
	std::cout << "=================================" << std::endl;
}
void Players::Show2() const
{
	std::cout << "=================================" << std::endl;
	std::cout << id << ", ¶¼Å»Ãâ : " << score2 << "Á¡ (" << rank2 << ")µî"
		<< ", ¶¼Å»Ãâ ·©Å· º¯È­ : " << past_rank2 - rank2
		<< ", »óÀ§ " << rank2 * 0.001 << "%" << std::endl;
	std::cout << "=================================" << std::endl;
}

void Players::Show() const
{
	std::cout << id << ", ÄíÅ°ÈÆ·Ã¼Ò : " << score1 << "Á¡ (" << rank1 << ")µî, ¶¼Å»Ãâ : " 
									<< score2 << "Á¡ (" << rank2 << ")µî" << std::endl;
}

