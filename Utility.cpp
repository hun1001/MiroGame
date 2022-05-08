#include "Utility.h"

Utility::Utility()
{
}

Utility::~Utility()
{
}

void Utility::LetterIntegrate(char& letter)
{
	if(letter >= 'a' && letter <= 'z')
	{
		letter = letter - 32;
	}
}
