#ifndef MENUOVERLAY_HPP
#define MENUOVERLAY_HPP

#include <gui_generated/containers/MenuOverlayBase.hpp>

class MenuOverlay : public MenuOverlayBase
{
public:
    MenuOverlay();
    virtual ~MenuOverlay() {}

    virtual void initialize();
protected:
};

#endif // MENUOVERLAY_HPP
