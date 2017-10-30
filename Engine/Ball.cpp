#include "Ball.h"

Ball::Ball(const Vec2 & pos)
	:
	pos(pos)
{
}

void Ball::Draw(Graphics & gfx)
{
	gfx.DrawCircle(pos,rad, c);
}

void Ball::Update(float dt)
{
}
