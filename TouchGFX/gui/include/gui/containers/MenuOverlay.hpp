#ifndef MENUOVERLAY_HPP
#define MENUOVERLAY_HPP

#include <gui_generated/containers/MenuOverlayBase.hpp>
#include <touchgfx/Callback.hpp>

class GameScreenView;


class MenuOverlay : public MenuOverlayBase
{
public:
    MenuOverlay();
    virtual ~MenuOverlay() {}

    virtual void initialize();

    void buttonResumeClicked();
    void buttonRestartClicked();
    void buttonHowToPlayClicked();

    //callback for button on screen
    touchgfx::Callback<GameScreenView> resumeCallback;
    touchgfx::Callback<GameScreenView> restartCallback;
    touchgfx::Callback<GameScreenView> howToPlayCallback;

    void setHowToPlayCallback(touchgfx::Callback<GameScreenView> cb)
    {
    	howToPlayCallback = cb;
    }

    void setResumeCallback(touchgfx::Callback<GameScreenView> cb)
    {
        resumeCallback = cb;
    }

    void setRestartCallback(touchgfx::Callback<GameScreenView> cb)
    {
        restartCallback = cb;
    }
protected:
};

#endif // MENUOVERLAY_HPP
