#pragma once

#include <string>
#include <SDL2/SDL_mixer.h>
#include "feather/components/component.h"

namespace fl {

class SoundEmmitter : public fl::Component {
public:
    SoundEmmitter(fl::Entity* owner);
    
    unsigned loadSoundFromFile(const std::string& path);
    void playSound();
private:
    unsigned m_soundID;


}; // class SoundEmmitter

}; // namespace fl
