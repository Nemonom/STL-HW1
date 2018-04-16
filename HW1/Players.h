#pragma once
#include <iostream>
#include <string>

class Players
{
public:
	char id[13];		// ���̵�
	int score1{ 0 };			// 1�� ��� �ְ� ����
	int score2{ 0 };			// 2�� ��� �ְ� ����
	short rank1{ 0 };		// 1�� ��� ���
	short rank2{ 0 };		// 2�� ��� ���

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

	void SetRank1(int n) { rank1 = n; }
	void SetRank2(int n) { rank2 = n; }

};

