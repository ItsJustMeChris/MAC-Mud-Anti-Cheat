#include "stdafx.h"

#include <SpamDetector.h>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>


SD::SD(int spamThreshold, int spamHumanization, bool enabled, bool humanizedDetection, int userCount)
{
	m_spamThreshold = spamThreshold;
	m_spamHumanization = spamHumanization;
	m_enabled = enabled;
	m_humanizedDetection = humanizedDetection;
	for (int i = 0; i < userCount; i++)
	{
		std::vector<int> null;
		null.push_back(NULL);
		null.push_back(NULL);
		m_Vector.push_back(null);
	}
}

void SD::toggleHumanize()
{
	if (m_spamHumanization)
	{
		m_spamHumanization = false;
	}
	else
	{
		m_spamHumanization = true;
	}
}

void SD::toggleDetection()
{
	if (m_enabled)
	{
		m_enabled = false;
	}
	else
	{
		m_enabled = true;
	}
}

int SD::setThreshold(int threshold)
{
	m_spamThreshold = threshold;
	return 0;
}

int SD::setHumanization(int humanization)
{
	m_spamHumanization = humanization;
	return 0;
}

bool SD::check(int userID, std::string message)
{
	if (m_enabled)
	{
		std::time_t _t = std::time(0);
		std::cout << m_Vector[userID][0] << std::endl;
		std::cout << m_Vector[userID][1] << std::endl;

		if (m_Vector[userID][0] != NULL)
		{
			double diff = difftime(_t, m_Vector[userID][1]);
			if (diff >= m_spamThreshold)
			{
				m_Vector[userID][0] = NULL;
				m_Vector[userID][1] = NULL;
				return true;
			}
			else
			{
				if (m_Vector[userID][0] < 2)
				{
					m_Vector[userID][0]++;
					m_Vector[userID][1] = _t;
					return true;
				}
				else
				{
					std::cout << diff << std::endl;
					return false;
				}
			}
		}
		else
		{
			m_Vector[userID][0] = 1;
			m_Vector[userID][1] = _t;

			return true;
		}
	}
	else
	{
		return true;
	}
}