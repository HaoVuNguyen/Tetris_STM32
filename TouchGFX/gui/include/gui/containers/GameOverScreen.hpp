#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP

#include <gui_generated/containers/GameOverScreenBase.hpp>

class GameOverScreen : public GameOverScreenBase
{
public:
    GameOverScreen();
    virtual ~GameOverScreen() {}

    virtual void initialize();
protected:
};

#endif // GAMEOVERSCREEN_HPP
