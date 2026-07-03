#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <Arduino.h>

enum class Sound
{
    None,

    Startup,

    Key,

    Success,

    Error,

    Lock,

    Unlock,

    Warning
};

class SoundManager
{
public:

    void begin();

    void update();

    void play(Sound sound);

    void stop();

private:

    Sound currentSound = Sound::None;
};

extern SoundManager Speaker;

#endif