#include <Feather/Components/AnimationComponent.h>
#include <Feather/Entities/Entity.h>
#include <Feather/Systems/AnimationSystem.h>

namespace fl {

AnimationComponent::AnimationComponent(Entity* owner) :
	Component(owner)
{

}

void AnimationComponent::awake() {
	m_sprite = m_owner->getComponent<Sprite>().get();
	if(m_sprite == nullptr)
		throw std::runtime_error("Error! Sprite Component required when using AnimationComponent Component.");
	this->setAnimation(m_currentAnimationID);
}

void AnimationComponent::addAnimation(IDtype animationID, Animation animation) {
	m_animationMap.insert_or_assign(animationID, animation);

	if(m_sprite != nullptr && !m_sprite->hasTexture()) {
		setAnimation(animationID);
	}
}

void AnimationComponent::setAnimation(IDtype animationID) {
	if (!m_animationMap.contains(animationID)) {
		throw std::invalid_argument("INVALID! No matching animation ID found");
	}
	m_currentAnimationID = animationID;
	
	if (m_sprite == nullptr) {
		return;
	}

	FrameData& frame = m_animationMap.at(m_currentAnimationID).frames[0];
	m_sprite->setTexture(frame.textureID, frame.textureRect);

	m_currentFrame = 0;
	m_currentFrameTime = 0;
}

IDtype AnimationComponent::getCurrentAnimationID() const {
	return m_currentAnimationID;
}

const Animation& AnimationComponent::getCurrentAnimation() const {
	return m_animationMap.at(m_currentAnimationID);
}

void AnimationComponent::updateFrame(float deltaTime) {
	const Animation& a = this->getCurrentAnimation();

	if ((a.frames.size() > 1) && (a.loop || m_currentFrame < a.frames.size() - 1)) {
		m_currentFrameTime += deltaTime;

		if (m_currentFrameTime >= a.frames[m_currentFrame].displaySeconds) {
			m_currentFrameTime = 0.f;

			m_currentFrame = ((m_currentFrame + 1) % a.frames.size());
			m_sprite->setTexture(a.frames[m_currentFrame].textureID, a.frames[m_currentFrame].textureRect);

			if (!a.frames[m_currentFrame].actionList.empty()) {
				for (auto& action : a.frames[m_currentFrame].actionList) {
					action();
				}
			}
		}
	}
}

} // namepsace fl