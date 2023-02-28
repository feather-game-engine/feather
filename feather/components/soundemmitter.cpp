#include "soundemmitter.h"
#include "component.h"

namespace fl {

    SoundEmmitter::SoundEmmitter(fl::Entity* owner) 
        : Component(owner) {

    }

    unsigned SoundEmmitter::loadSoundFromFile(const std::string &path) {
        m_soundID = m_owner->CONTEXT->resources->loadSound(path);

        return m_soundID;
    }

    void SoundEmmitter::playSound() {
        Mix_PlayChannel(-1, m_owner->CONTEXT->resources->getSound(m_soundID), 0);
    }

}
