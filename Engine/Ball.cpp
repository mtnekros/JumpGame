#include "Ball.h"
#include <algorithm>

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
	if (vel.GetLengthSq() <= maxVel*maxVel)
	{
		vel += acc*dt;
	}
	pos += vel*dt;
}
