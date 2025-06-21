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

    void showEnterNameOverlay();

    void showNewHighScoreText();
    void destroyEnterNameOverlay();

    void updateNameChar(uint8_t idx, char c);
    void updatePlayerInfo(uint32_t score, char* name);

    void buttonRestartClicked();
    touchgfx::Callback<GameScreenView> restartCallback;
    void setRestartCallback(touchgfx::Callback<GameScreenView> cb)
	{
		restartCallback = cb;
	}

protected:
    Unicode::UnicodeChar scoreBuffer[10];

    Unicode::UnicodeChar playerScoreBuffer[7];
    Unicode::UnicodeChar playerNameBuffer[4];
};

#endif // GAMEOVERSCREEN_HPP
