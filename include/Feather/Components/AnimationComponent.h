#pragma once

#include <functional>
#include <forward_list>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <iostream>

#include <Feather/Components/Component.h>
#include <Feather/Components/Sprite.h>
#include <Feather/Utilities/Types.h>

namespace fl {

class AnimationSystem;

using FrameAction = std::function<void(void)>;
using ActionList = std::forward_list<FrameAction>;

struct FrameData {
	IDtype					textureID;
	IntRect					textureRect;
	float					displaySeconds;
	ActionList				actionList{};
}; // struct FrameData

struct Animation {
	std::vector<FrameData>	frames;
	bool					loop = false;
}; // struct Animation

class AnimationComponent : public Component {

friend class AnimationSystem;

public:
	AnimationComponent(Entity* owner);

	virtual void awake();

	void addAnimation(IDtype animationID, Animation animation);

	void setAnimation(IDtype animationID);

	IDtype getCurrentAnimationID() const;
	const Animation& getCurrentAnimation() const;
private:
	void updateFrame(float deltaTime);

	std::unordered_map<IDtype, Animation> 	m_animationMap;

	IDtype 					m_currentAnimationID{};

	std::size_t				m_currentFrame{};

	float					m_currentFrameTime{};

	Sprite*					m_sprite = nullptr;	

}; // class AnimationComponent

} // namespace ba