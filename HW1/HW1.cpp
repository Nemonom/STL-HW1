#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include "Players.h"

using namespace std;

#define num 10

void read(vector<Players>& v);
void save(vector<Players>& v);
void new_game(vector<Players>& v);

int main()
{
	vector<Players> v(num); // ? 이거 없애도 되나 걍 재할당 여러 번 하냐 한 번에 하냐 차이인듯
	vector<Players> first(num);
	vector<Players> second(num);
	
	read(v);
	
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
	}

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
	}

	save(v);

	for (auto i = v.begin(); i != v.end(); ++i)
		i->Show();
}


void read(vector<Players>& v)
{
	ifstream in("선수데이터", ios::binary);

	if (in.is_open())
	{
		in.read((char*)v.data(), sizeof(Players) * num);
	}
	else
	{		
		random_device rd;
		default_random_engine dre(rd());
		uniform_int_distribution<> uidN1(0, 370000000);
		uniform_int_distribution<> uidN2(0, 410000000);

		for (int i = 0; i < num; ++i)
			v.emplace_back(to_string(i + 1) + string("번 선수"), uidN1(dre), uidN2(dre));
		v.emplace_back(string("본인"), uidN1(dre), uidN2(dre));

	}
}

void save(vector<Players>& v)
{
	ofstream out("선수데이터", ios::binary);
	out.write((char*)v.data(), sizeof(Players) * num);
}

void new_game(vector<Players>& v)
{

}