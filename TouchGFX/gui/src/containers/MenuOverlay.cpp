#include <gui/containers/MenuOverlay.hpp>

MenuOverlay::MenuOverlay()
{

}

void MenuOverlay::initialize()
{
    MenuOverlayBase::initialize();
}

void MenuOverlay::buttonResumeClicked()
{
    if (resumeCallback.isValid())
    {
        resumeCallback.execute();  // Gọi hàm được gán từ GameScreenView
    }
}

void MenuOverlay::buttonRestartClicked()
{
    if (restartCallback.isValid())
    {
        restartCallback.execute();  // Gọi về GameScreenView
    }
}
