#include "Players.h"



Players::Players()
{
}


Players::~Players()
{
}

void Players::Show1() const
{
	std::cout << id << ", ��Ű�Ʒü� : " << score1 << "�� (" << rank1 << ")��" << std::endl;
}
void Players::Show2() const
{
	std::cout << id << ", ��Ż�� : " << score2 << "�� (" << rank2 << ")��" << std::endl;
}

void Players::Show() const
{
	std::cout << id << ", ��Ű�Ʒü� : " << score1 << "�� (" << rank1 << ")��, ��Ż�� : " 
									<< score2 << "�� (" << rank2 << ")��" << std::endl;
}

void Players::My_Show() const
{
	std::cout << "=================================" << std::endl;
	std::cout << id << ", ��Ű�Ʒü� : " << score1 << "�� (" << rank1 << ")��"
		<< ", ��Ű�Ʒü� ��ŷ ��ȭ : " << rank1 - past_rank1
		<< ", ���� " << rank1 << "%" << std::endl;
	
	std::cout << "��Ż�� : " << score2 << "�� (" << rank2 << ")��"
		<< ", ��Ż�� ��ŷ ��ȭ : " << rank2 - past_rank2 
		<< ", ���� " << rank2 << "%" << std::endl;	
	std::cout << "=================================" << std::endl;
}