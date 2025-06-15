#ifndef HOWTOPLAYSCREENVIEW_HPP
#define HOWTOPLAYSCREENVIEW_HPP

#include <gui_generated/howtoplayscreen_screen/HowToPlayScreenViewBase.hpp>
#include <gui/howtoplayscreen_screen/HowToPlayScreenPresenter.hpp>

class HowToPlayScreenView : public HowToPlayScreenViewBase
{
public:
    HowToPlayScreenView();
    virtual ~HowToPlayScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // HOWTOPLAYSCREENVIEW_HPP
