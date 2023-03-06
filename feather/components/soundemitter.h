#pragma once

#include <string>
#include <SDL2/SDL_mixer.h>
#include "feather/components/component.h"
#include "feather/entities/entity.h"

namespace fl {

class SoundEmitter : public fl::Component {
public:
    SoundEmitter(fl::Entity* owner);
    
    unsigned loadSoundFromFile(const std::string& path);
    void play();
private:
    unsigned m_soundID;


}; // class SoundEmmitter

}; // namespace fl
