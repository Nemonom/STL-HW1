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
	std::cout << id << ", ��Ű�Ʒü� : " << score1 << "�� (" << rank1 << ")��"
		<< ", ��Ű�Ʒü� ��ŷ ��ȭ : " << past_rank1 - rank1
		<< ", ���� " << rank1*0.001 << "%" << std::endl;
	std::cout << "=================================" << std::endl;
}
void Players::Show2() const
{
	std::cout << "=================================" << std::endl;
	std::cout << id << ", ��Ż�� : " << score2 << "�� (" << rank2 << ")��"
		<< ", ��Ż�� ��ŷ ��ȭ : " << past_rank2 - rank2
		<< ", ���� " << rank2 * 0.001 << "%" << std::endl;
	std::cout << "=================================" << std::endl;
}

void Players::Show() const
{
	std::cout << id << ", ��Ű�Ʒü� : " << score1 << "�� (" << rank1 << ")��, ��Ż�� : " 
									<< score2 << "�� (" << rank2 << ")��" << std::endl;
}

