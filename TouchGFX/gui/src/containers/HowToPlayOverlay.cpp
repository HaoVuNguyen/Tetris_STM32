#include <gui/containers/HowToPlayOverlay.hpp>

HowToPlayOverlay::HowToPlayOverlay()
{

}

void HowToPlayOverlay::initialize()
{
    HowToPlayOverlayBase::initialize();
}

void HowToPlayOverlay::buttonReturnClicked()
{
	if (returnCallback.isValid())
	{
		returnCallback.execute();  // Gọi về GameScreenView
	}
}
