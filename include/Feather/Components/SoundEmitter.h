#pragma once

#include <string>
#include <SDL2/SDL_mixer.h>
#include "Feather/Components/Component.h"
#include "Feather/Entities/Entity.h"

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
