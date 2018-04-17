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

int main()
{
	vector<Players> v(entire_num);

	//vector<Players*> first(num); 
	//vector<Players*> second(num);

	// 파일 읽기 없으면 만들고
	read(v);	

	// 10000 명 뽑기



	// 1게임 정렬 및 출력
	{
		int cnt{ 0 };
		//정렬
		sort(v.begin(), v.end(), [&cnt](const Players& a, const Players& b)
		{
			++cnt;
			return a.GetScore1() > b.GetScore1();
		}); 

		//랭킹
		int n{ 1 };
		for (Players& d : v)
			d.SetRank1(n++);

		std::cout << "=================================" << std::endl;
		for (auto i = v.begin(); i != v.end(); ++i)
		{
			i->Show1();
			i->Save_Rank1();
		}
		std::cout << "=================================" << std::endl;

	}

	// 2게임 정렬 및 출력
	{
		int cnt{ 0 };
		//정렬
		sort(v.begin(), v.end(), [&cnt](const Players& a, const Players& b)
		{
			++cnt;
			return a.GetScore2() > b.GetScore2();
		});

		//랭킹
		int n{ 1 };
		for (Players& d : v)
			d.SetRank2(n++);

		std::cout << "=================================" << std::endl;
		for (auto i = v.begin(); i != v.end(); ++i)
		{
			i->Show2();
			i->Save_Rank2();
		}
		std::cout << "=================================" << std::endl;
	}

	// 저장
	save(v);

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
	uniform_int_distribution<> uidN1(0, 370000000);
	uniform_int_distribution<> uidN2(0, 410000000);

	normal_distribution<> nd1(0, 1.0);
	normal_distribution<> nd2(0, 1.0);


	//for (int i = 0; i < entire_num - 1; ++i)
	//{
	//	v.emplace_back(to_string(i + 1) + string("번 선수"), uidN1(dre), uidN2(dre));
	//}
	//v.emplace_back(string("본인"), uidN1(dre), uidN2(dre));


	for (int i = 0; i < entire_num - 1; ++i)
	{
		float val1 = abs(nd1(dre)) * 37000000;
		float val2 = abs(nd2(dre)) * 410000000;
		if(val1 > 37000000) val1 /= 100;
		if(val2 > 410000000) val2 /= 100;

		v.emplace_back(to_string(i + 1) + string("번 선수"), val1, val2);
	}
	
	float val1 = abs(nd1(dre)) * 37000000;
	float val2 = abs(nd2(dre)) * 410000000;
	if(val1 > 37000000) val1 /= 100;
	if(val2 > 410000000) val2 /= 100;
	v.emplace_back(string("본인"), val1, val2);

}

void replay1(vector<Players*>& v)
{
	random_device rd;
	default_random_engine dre(rd());	
	normal_distribution<> nd1(0, 1.0);

	for (auto &p : v)
	{
		float val1 = abs(nd1(dre)) * 37000000;
		if (val1 > 37000000) val1 /= 100;

		if (val1 >= p->GetScore1()) // 지금 점수보다 크면 바꿔
			p->SetScore1(val1);		
	}
}

void replay2(vector<Players*>& v)
{
	random_device rd;
	default_random_engine dre(rd());
	normal_distribution<> nd2(0, 1.0);

	for (auto &p : v)
	{
		float val2 = abs(nd2(dre)) * 410000000;
		if (val2 > 37000000) val2 /= 100;

		if (val2 >= p->GetScore2()) // 지금 점수보다 크면 바꿔
			p->SetScore2(val2);
	}
}