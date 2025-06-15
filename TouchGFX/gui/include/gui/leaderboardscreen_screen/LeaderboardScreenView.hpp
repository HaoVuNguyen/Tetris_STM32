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
};

#endif // LEADERBOARDSCREENVIEW_HPP
