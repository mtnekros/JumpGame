#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"

class Ball
{
public:
	Ball( const Vec2& pos);
	void Draw(Graphics& gfx) const;
	void Update( float dt );
	void ClampToBottomWall( const RectF& walls );
	RectF GetRect() const;
private:
	Vec2 pos; //pos -> center of the ball
	Vec2 vel = { 0.0f, 0.0f };
	Vec2 acc = { 0.0f, 180.0f };
	static constexpr float rad = 20.0f;
	static constexpr float maxVel = 300.0f;
	static constexpr Color c = Colors::White;


};