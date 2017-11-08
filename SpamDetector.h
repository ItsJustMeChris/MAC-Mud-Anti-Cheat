#pragma once
#define SEARCHABLEADT_H
#include "stdafx.h"

#include <SpamDetector.h>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

class SD
{
private:
	int m_spamThreshold;
	int m_spamHumanization;
	bool m_enabled;
	bool m_humanizedDetection;
	std::vector< std::vector<int> > m_Vector;

public:
	SD(int, int, bool, bool, int);
	bool check(int, std::string);
	void toggleHumanize();
	void toggleDetection();
	int setThreshold(int);
	int setHumanization(int);

};