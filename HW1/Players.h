#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;


class Players
{
public:
	char id[13];		// 아이디
	int score1{ 0 };	// 1번 경기 최고 점수
	int score2{ 0 };	// 2번 경기 최고 점수
	int rank1{ 0 };		// 1번 경기 등수
	int rank2{ 0 };		// 2번 경기 등수

	int past_rank1{ 0 };
	int past_rank2{ 0 };

public:
	Players();
	Players(std::string s, int n1, int n2) : score1(n1), score2(n2)
	{
		strcpy_s(id, s.c_str());
	};
	~Players();

	void Show1() const;
	void Show2() const;
	void Show() const;

	int GetScore1() const { return score1; }
	int GetScore2() const { return score2; }

	void SetScore1(int n) { score1 = n; }
	void SetScore2(int n) { score2 = n; }

	void SetRank1(int n) { rank1 = n; }
	void SetRank2(int n) { rank2 = n; }

	void Save_Rank1() { past_rank1 = rank1; }
	void Save_Rank2() { past_rank2 = rank2; }

};

