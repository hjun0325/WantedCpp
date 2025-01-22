#pragma once

#include "Actor/DrawableActor.h"
#include <Math/Vector2.h>

class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)

public:
	Player(Vector2 position);

	Player(const char* image);

	virtual void Update(float deltaTime);

	inline void Setposition(Vector2 position) { this->position = position; }
	inline Vector2 Getposition() { return position; }

private:
	Vector2 position;
};
