#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include "Players.h"

using namespace std;

int main()
{
	vector<Players> v;
	v.reserve(1000); // ? 이거 없애도 되나 걍 재할당 여러 번 하냐 한 번에 하냐 차이인듯

	random_device rd;
	default_random_engine dre(rd());
	uniform_int_distribution<> uidN1(0, 4000000);
	uniform_int_distribution<> uidN2(0, 30000000);

	for (int i = 0; i < 999; ++i)
		v.emplace_back(to_string(i + 1) + string("번 선수"), uidN1(dre), uidN2(dre));
	v.emplace_back(string("*나*"), uidN1(dre), uidN2(dre));
	
	{
		int cnt{ 0 };
		sort(v.begin(), v.end(), [&cnt](const Players& a, const Players& b)
		{
			++cnt;
			return a.GetScore1() > b.GetScore1();
		});

		int n{ 1 };
		for (Players& d : v)
			d.SetRank1(n++);
	}

	{
		int cnt{ 0 };
		sort(v.begin(), v.end(), [&cnt](const Players& a, const Players& b)
		{
			++cnt;
			return a.GetScore2() > b.GetScore2();
		});

		int n{ 1 };
		for (Players& d : v)
			d.SetRank2(n++);
	}

	ofstream out("선수데이터", ios::binary);
	out.write((char*)v.data(), sizeof(Players) * 1000);

	for (auto i = v.begin(); i != v.end(); ++i)
		i->Show();
}


