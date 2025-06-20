#ifndef ENTERNAME_HPP
#define ENTERNAME_HPP

#include <gui_generated/containers/EnterNameBase.hpp>

class EnterName : public EnterNameBase
{
public:
    EnterName();
    virtual ~EnterName() {}

    void setChar(uint8_t idx, char c);
    void setCurrChar(uint8_t idx);

    virtual void initialize();
protected:
    Unicode::UnicodeChar char1Buffer[2];
    Unicode::UnicodeChar char2Buffer[2];
    Unicode::UnicodeChar char3Buffer[2];
};

#endif // ENTERNAME_HPP
