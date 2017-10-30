#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball( const Vec2& pos);
	void Draw(Graphics& gfx);
	void Update( float dt );
private:
	Vec2 pos;
	static constexpr float rad = 20.0f;
	static constexpr Color c = Colors::White;

};