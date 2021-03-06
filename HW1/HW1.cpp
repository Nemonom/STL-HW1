#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include "Players.h"

using namespace std;

#define entire_num 100000
#define num 10000

void read(vector<Players>& v);
void save(vector<Players>& v);
void new_game(vector<Players>& v);
void replay1(vector<Players*>& v);
void replay2(vector<Players*>& v);

void game1(vector<Players>& v, vector<Players*>& f);
void game2(vector<Players>& v, vector<Players*>& s);

void game1_result(vector<Players>& f);
void game2_result(vector<Players>& s);

float absscore();

random_device rd;
default_random_engine dre(rd());
normal_distribution<> nd(1, 0.1);
uniform_int_distribution<> uid(1, 10);

int main()
{
	vector<Players> v(entire_num);
	vector<Players*> first; 
	vector<Players*> second;

	// 파일 읽기 없으면 만들고
	read(v);	

	int menu{ 0 };

	while (true)
	{
		cout << "=================================" <<endl;
		cout << "1. 전체 출력" << endl;
		cout << "2. 게임 플레이" << endl;
		cout << "3. 플레이 선수 출력" << endl;
		cout << "0. 종료" << endl;
		cout << "=================================" <<endl;
		cin >> menu;

		switch (menu)
		{
		case 1:
			for (const auto & p : v)
				p.Show();
			break;

		case 2:
			first.clear();
			second.clear();

			//10000 명 뽑기
			game1(v, first);
			game2(v, second);

			//플레이
			replay1(first);
			replay2(second);

			// 게임 정렬 및 출력
			game1_result(v);
			cout << endl;
			game2_result(v);

			save(v);
			break;

		case 3:
			for (const auto& p : first)
				p->Show();
			cout << endl;
			for (const auto& p : second)
				p->Show();
			break;

		case 0:
			return 0;
			break;
		}
	}


}


void read(vector<Players>& v)
{
	ifstream in("선수데이터", ios::binary);
	
	if (in.is_open())
	{
		in.read((char*)v.data(), sizeof(Players) * entire_num);
	}
	else
	{
		new_game(v);
	}
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

	int val1{ 0 }, val2{ 0 };
	
	for (int i = 0; i < entire_num - 1; ++i)
	{
		val1 = absscore() * 37000000 / 2;
		val2 = absscore() * 410000000 / 2;		
		v.emplace_back(to_string(i + 1) + string("번 선수"), val1, val2);
	}
	
	val1 = absscore() * 37000000 / 2;
	val2 = absscore() * 410000000 / 2;
	v.emplace_back(string("본인"), val1, val2);
}

void replay1(vector<Players*>& f)
{
	for (auto &p : f)
	{
		int val1 = absscore() * 37000000 / 2;
		if (val1 >= p->GetScore1()) // 지금 점수보다 크면 바꿔
			p->SetScore1(val1);		
	}
}

void replay2(vector<Players*>& s)
{	
	for (auto &p : s)
	{
		int val2 = absscore() * 410000000 / 2;
		if (val2 >= p->GetScore2()) // 지금 점수보다 크면 바꿔
			p->SetScore2(val2);
	}
}

void game1(vector<Players>& v, vector<Players*>& f)
{
	f.reserve(num);

	int i = 0;
	int who = 0;
	while (i < num - 1)
	{
		int r = uid(dre);
		who += r;

		if (strcmp(v[who].id, "본인"))
			f.emplace_back(&v[who]);
		++i;
	}	
	
	int cnt{ -1 };
	find_if(v.begin(), v.end(), [&cnt](const Players& a)
	{
		++cnt;
		return !strcmp("본인", a.id);
	});
	f.emplace_back(&v[cnt]);
}

void game2(vector<Players>& v, vector<Players*>& s)
{
	s.reserve(num);
	
	int i = 0;
	int who = 0;
	while (i < num - 1)
	{
		int r = uid(dre);
		who += r;

		if (strcmp(v[who].id, "본인"))
			s.emplace_back(&v[who]);

		i++;
	}

	int cnt{ -1 };
	find_if(v.begin(), v.end(), [&cnt](const Players& a)
	{
		++cnt;
		return !strcmp("본인", a.id);
	});
	s.emplace_back(&v[cnt]);
}

void game1_result(vector<Players>& v)
{
	//정렬
	sort(v.begin(), v.end(), [](const Players& a, const Players& b)
	{
		return a.GetScore1() > b.GetScore1();
	});

	//랭킹
	int n{ 1 };
	int find_me{ 0 };
	for (Players& d : v)
	{
		if (!strcmp(d.id, "본인"))
			find_me = n-1; 
		d.SetRank1(n++);	
	}

	// 내 앞뒤 출력
	for (int i = 0; i < 3; ++i)
	{
		if (find_me - 1 + i>=0 && find_me - 1 + i < v.size())
			v[find_me - 1 + i].Show1();
	}

	for (Players& d : v)
	{
		d.Save_Rank1();
	}

}

void game2_result(vector<Players>& v)
{
	//정렬
	sort(v.begin(), v.end(), [](const Players& a, const Players& b)
	{
		return a.GetScore2() > b.GetScore2();
	});

	//랭킹
	int n{ 1 };
	int find_me{ 0 };
	for (Players& d : v)
	{
		if (!strcmp(d.id, "본인"))
			find_me = n - 1;
		d.SetRank2(n++);
	}

	// 내 앞뒤 출력
	for (int i = 0; i < 3; ++i)
	{
		if (find_me - 1 + i >= 0 && find_me - 1 + i < v.size())
			v[find_me - 1 + i].Show2();
	}

	for (Players& d : v)
	{
		d.Save_Rank2();
	}

}

float absscore()
{
	float val = fabsf(nd(dre));
	if (val > 2)val = 2.0f;
	return val;
}
