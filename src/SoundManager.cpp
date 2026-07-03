#include "SoundManager.h"

#include "Pins.h"

SoundManager Speaker;

void SoundManager::begin()
{
    pinMode(BUZZER_PIN, OUTPUT);

    noTone(BUZZER_PIN);
}

void SoundManager::update()
{
}

void SoundManager::play(Sound sound)
{
    currentSound = sound;

    switch(sound)
    {
        case Sound::Startup:

            tone(BUZZER_PIN,1500,150);

            break;

        case Sound::Key:

            tone(BUZZER_PIN,2500,35);

            break;

        case Sound::Success:

            tone(BUZZER_PIN,2800,100);

            delay(110);

            tone(BUZZER_PIN,3500,150);

            break;

        case Sound::Error:

            tone(BUZZER_PIN,500,300);

            break;

        case Sound::Lock:

            tone(BUZZER_PIN,1200,120);

            break;

        case Sound::Unlock:

            tone(BUZZER_PIN,2200,120);

            break;

        case Sound::Warning:

            tone(BUZZER_PIN,700,500);

            break;

        default:

            break;
    }
}

void SoundManager::stop()
{
    noTone(BUZZER_PIN);

    currentSound = Sound::None;
}