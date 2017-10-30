#include "Ball.h"
#include <algorithm>

Ball::Ball(const Vec2 & pos)
	:
	pos(pos)
{
}

void Ball::Draw(Graphics & gfx) const
{
	gfx.DrawCircle(pos,rad, c);
}

void Ball::Update( Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		vel.y = upVel;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		vel.y = maxVel;
	}
	if (vel.GetLengthSq() <= maxVel*maxVel)
	{
		vel += acc*dt;
	}
	pos += vel*dt;
}

void Ball::ClampToWall(const RectF & walls)
{
	const RectF rect = GetRect();
	if (rect.bottom >= walls.bottom)
	{
		pos.y -= (rect.bottom - walls.bottom); // repositioning to the bottom
		vel.y = 0;// 0 cause i don't want it to bounce i want it to stop and not -vel.y/3.0f;		
	}
	else if (rect.top <= walls.top)
	{
		pos.y += (walls.top - rect.top); // repositioning to the bottom
		vel.y = 0;
	}
	
}

RectF Ball::GetRect() const
{
	const Vec2 half = Vec2(rad, rad);
	return RectF( pos - half, pos + half);
}
