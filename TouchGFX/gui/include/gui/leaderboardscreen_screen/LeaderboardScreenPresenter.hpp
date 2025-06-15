#ifndef LEADERBOARDSCREENPRESENTER_HPP
#define LEADERBOARDSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LeaderboardScreenView;

class LeaderboardScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LeaderboardScreenPresenter(LeaderboardScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~LeaderboardScreenPresenter() {}

private:
    LeaderboardScreenPresenter();

    LeaderboardScreenView& view;
};

#endif // LEADERBOARDSCREENPRESENTER_HPP
