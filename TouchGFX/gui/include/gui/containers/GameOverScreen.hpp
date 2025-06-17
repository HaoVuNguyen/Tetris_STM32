#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP

#include <gui_generated/containers/GameOverScreenBase.hpp>

class GameScreenView;

class GameOverScreen : public GameOverScreenBase
{
public:
    GameOverScreen();
    virtual ~GameOverScreen() {}

    virtual void initialize();

    void setScore(int score);

    void buttonRestartClicked();
    touchgfx::Callback<GameScreenView> restartCallback;
    void setRestartCallback(touchgfx::Callback<GameScreenView> cb)
	{
		restartCallback = cb;
	}

protected:
    Unicode::UnicodeChar scoreBuffer[10];
};

#endif // GAMEOVERSCREEN_HPP
