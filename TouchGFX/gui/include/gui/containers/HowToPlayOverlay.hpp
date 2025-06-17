#ifndef HOWTOPLAYOVERLAY_HPP
#define HOWTOPLAYOVERLAY_HPP

#include <gui_generated/containers/HowToPlayOverlayBase.hpp>

class GameScreenView;

class HowToPlayOverlay : public HowToPlayOverlayBase
{
public:
    HowToPlayOverlay();
    virtual ~HowToPlayOverlay() {}

    virtual void initialize();

    void buttonReturnClicked();

    touchgfx::Callback<GameScreenView> returnCallback;

    void setReturnCallback(touchgfx::Callback<GameScreenView> cb)
	{
		returnCallback = cb;
	}
protected:
};

#endif // HOWTOPLAYOVERLAY_HPP
