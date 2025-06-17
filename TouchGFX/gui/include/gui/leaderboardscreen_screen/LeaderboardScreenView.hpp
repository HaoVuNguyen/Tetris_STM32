#ifndef LEADERBOARDSCREENVIEW_HPP
#define LEADERBOARDSCREENVIEW_HPP

#include <gui_generated/leaderboardscreen_screen/LeaderboardScreenViewBase.hpp>
#include <gui/leaderboardscreen_screen/LeaderboardScreenPresenter.hpp>

class LeaderboardScreenView : public LeaderboardScreenViewBase
{
public:
    LeaderboardScreenView();
    virtual ~LeaderboardScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();



protected:
    Unicode::UnicodeChar nameBuffer[6];
    Unicode::UnicodeChar scoreBuffer[7];
};

#endif // LEADERBOARDSCREENVIEW_HPP
