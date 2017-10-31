#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "Keyboard.h"

class Ball
{
public:
	Ball( const Vec2& pos);
	void Draw(Graphics& gfx) const;
	void Update( Keyboard& kbd, float dt );
	void ClampToWall( const RectF& walls );
	RectF GetRect() const;
private:
	void CheckAndResetJumpCounter( float bottomWall);
private:
	static constexpr float rad = 25.0f;
	static constexpr int maxJumps = 2;
	static constexpr float maxVel = 400.0f;
	static constexpr float upVel = -250.0f; // vel.y to be assigned when up is pressed
	static constexpr Color c = Colors::White;
	Vec2 pos; //pos -> center of the ball
	Vec2 vel = { 0.0f, 0.0f };
	Vec2 acc = { 0.0f, 400.0f };
	int jumpCounter = 0;



};