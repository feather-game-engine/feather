#include "Feather/Components/SoundEmitter.h"

namespace fl {

SoundEmitter::SoundEmitter(fl::Entity* owner) 
    : Component(owner) {

}

unsigned SoundEmitter::loadSoundFromFile(const std::string &path) {
    m_soundID = m_owner->CONTEXT->resources->loadSound(path);

    return m_soundID;
}

void SoundEmitter::play() {
    Mix_PlayChannel(-1, m_owner->CONTEXT->resources->getSound(m_soundID), 0);
}

}
