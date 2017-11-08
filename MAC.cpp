// MAC.cpp : Defines the entry point for the console application.
//Mac is a Mud text game Anti Cheat system.  
//

#include "stdafx.h"
#include <iostream>
#include <SpamDetector.h>
#include <string>

int main()
{
	SD sd(2, 0, true, false, 1);

	while (true)
	{
		std::string msg;
		std::cin >> msg;
		if (sd.check(1, msg))
		{
			std::cout << "Message Accepted!" << std::endl;
		}
		else
		{
			std::cout << "Slow Down!" << std::endl;
		}
	}
    return 0;
}

