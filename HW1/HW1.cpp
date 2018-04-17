#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include "Players.h"

using namespace std;

#define entire_num 100
#define num 10

void read(vector<Players>& v);
void save(vector<Players>& v);
void new_game(vector<Players>& v);
void replay1(vector<Players*>& v);
void replay2(vector<Players*>& v);

void game1(vector<Players>& v, vector<Players*>& f);
void game2(vector<Players>& v, vector<Players*>& s);

void game1_result(vector<Players*>& f);
void game2_result(vector<Players*>& s);


int main()
{
	vector<Players> v(entire_num);

	vector<Players*> first; 
	vector<Players*> second;

	// 파일 읽기 없으면 만들고
	read(v);	

	for (auto & p : v)
		p.Show();

	//10000 명 뽑기
	game1(v, first);
	game2(v, second);
	
	//플레이
	replay1(first);
	replay2(second);
	
	// 게임 정렬 및 출력
	game1_result(first);
	game2_result(second);


	for (auto & p : v)
		p.Show();


	// 저장
	//save(v);

}


void read(vector<Players>& v)
{
	/*ifstream in("선수데이터", ios::binary);
	
	if (in.is_open())
	{
		in.read((char*)v.data(), sizeof(Players) * entire_num);
	}
	else
	{
		new_game(v);
	}*/

	new_game(v);
}

void save(vector<Players>& v)
{
	ofstream out("선수데이터", ios::binary);
	out.write((char*)v.data(), sizeof(Players) * entire_num);
}

void new_game(vector<Players>& v)
{
	v.clear();
	v.reserve(entire_num);

	random_device rd;
	default_random_engine dre(rd());
	normal_distribution<> nd1(0, 0.1);
	normal_distribution<> nd2(0, 0.1);
	
	//for (int i = 0; i < entire_num - 1; ++i)
	//{
	//	v.emplace_back(to_string(i + 1) + string("번 선수"), uidN1(dre), uidN2(dre));
	//}
	//v.emplace_back(string("본인"), uidN1(dre), uidN2(dre));

	for (int i = 0; i < entire_num - 1; ++i)
	{
		float val1 = fabs(nd1(dre)) * 37000000;
		float val2 = fabs(nd2(dre)) * 410000000;
		if(val1 > 37000000) val1 = 37000000;
		if(val2 > 410000000) val2 = 410000000;

		v.emplace_back(to_string(i + 1) + string("번 선수"), val1, val2);
	}
	
	float val1 = fabs(nd1(dre)) * 37000000;
	float val2 = fabs(nd2(dre)) * 410000000;
	if(val1 > 37000000) val1 = 37000000;
	if(val2 > 410000000) val2 = 410000000;
	v.emplace_back(string("본인"), val1, val2);

}

void replay1(vector<Players*>& f)
{
	random_device rd;
	default_random_engine dre(rd());	
	normal_distribution<> nd1(0, 0.1);

	for (auto &p : f)
	{
		float val1 = fabs(nd1(dre)) * 37000000;
		if (val1 > 37000000) val1 = 37000000;

		if (val1 >= p->GetScore1()) // 지금 점수보다 크면 바꿔
			p->SetScore1(val1);		
	}
}

void replay2(vector<Players*>& s)
{
	random_device rd;
	default_random_engine dre(rd());
	normal_distribution<> nd2(0, 0.1);

	for (auto &p : s)
	{
		float val2 = abs(nd2(dre)) * 410000000;
		if (val2 > 410000000) val2 = 410000000;

		if (val2 >= p->GetScore2()) // 지금 점수보다 크면 바꿔
			p->SetScore2(val2);
	}
}

void game1(vector<Players>& v, vector<Players*>& f)
{
	{
		int i = 0;
		int who = 0;
		while (i < num - 1)
		{
			int r = rand() % 10 + 1;
			who += r;

			if (strcmp(v[who].id, "본인"))
				f.emplace_back(&v[who]);

			i++;
		}
		i = 0;
		while (i < entire_num)
		{
			if (!strcmp(v[i].id, "본인"))
				f.emplace_back(&v[i]);
			i++;
		}

	}
}

void game2(vector<Players>& v, vector<Players*>& s)
{
	{
		int i = 0;
		int who = 0;
		while (i < num - 1)
		{
			int r = rand() % 10 + 1;
			who += r;

			if (strcmp(v[who].id, "본인"))
				s.emplace_back(&v[who]);

			i++;
		}
		i = 0;
		while (i < entire_num)
		{
			if (!strcmp(v[i].id, "본인"))
				s.emplace_back(&v[i]);
			i++;
		}

	}
}

void game1_result(vector<Players*>& f)
{
	
	int cnt{ 0 };
	//정렬
	sort(f.begin(), f.end(), [&cnt](const Players* a, const Players* b)
	{
		++cnt;
		return a->GetScore1() > b->GetScore1();
	});

	//랭킹
	int n{ 1 };
	for (auto& d : f)
		d->SetRank1(n++);

	std::cout << "=================================" << std::endl;
	for (auto& d : f)
	{
		d->Show1();
		d->Save_Rank1();
	}
	std::cout << "=================================" << std::endl;

}

void game2_result(vector<Players*>& s)
{

	int cnt{ 0 };
	//정렬
	sort(s.begin(), s.end(), [&cnt](const Players* a, const Players* b)
	{
		++cnt;
		return a->GetScore2() > b->GetScore2();
	});

	//랭킹
	int n{ 1 };
	for (auto& d : s)
		d->SetRank2(n++);

	std::cout << "=================================" << std::endl;
	for (auto& d : s)
	{
		d->Show2();
		d->Save_Rank2();
	}
	std::cout << "=================================" << std::endl;

}
