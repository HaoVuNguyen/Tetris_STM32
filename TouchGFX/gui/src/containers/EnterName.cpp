#include <gui/containers/EnterName.hpp>

EnterName::EnterName()
{

}

void EnterName::initialize()
{
    EnterNameBase::initialize();
}

void EnterName::setCurrChar(uint8_t idx)
{
	currChar.setPosition(64 + idx * 42, 34, 21, 28);
}

void EnterName::setChar(uint8_t idx, char c)
{
	switch(idx){
		case 0:
			Unicode::snprintf(char1Buffer, sizeof(char1Buffer), "%c", c);
			nameChar1.setWildcard(char1Buffer);
			break;
		case 1:
			Unicode::snprintf(char2Buffer, sizeof(char2Buffer), "%c", c);
			nameChar2.setWildcard(char2Buffer);
			break;
		case 2:
			Unicode::snprintf(char3Buffer, sizeof(char3Buffer), "%c", c);
			nameChar3.setWildcard(char3Buffer);
			break;
		default:
			break;
	}

}
