#ifndef HOWTOPLAYOVERLAY_HPP
#define HOWTOPLAYOVERLAY_HPP

#include <gui_generated/containers/HowToPlayOverlayBase.hpp>

class HowToPlayOverlay : public HowToPlayOverlayBase
{
public:
    HowToPlayOverlay();
    virtual ~HowToPlayOverlay() {}

    virtual void initialize();
protected:
};

#endif // HOWTOPLAYOVERLAY_HPP
