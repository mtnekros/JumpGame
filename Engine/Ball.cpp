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
	while ( !kbd.KeyIsEmpty() )
	{
		const Keyboard::Event e = kbd.ReadKey();
		
		if ( e.IsPress() && e.GetCode() == VK_UP)
		{
			if (jumpCounter < maxJumps ) //checks to see if we've jumped more than the maxjumps 
			{
				vel.y = upVel;
				jumpCounter++;
			}
		}
		
		 
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
	CheckAndResetJumpCounter( walls.bottom );// to reset the jumpCounter to zero every time the ball hits the ground
}

RectF Ball::GetRect() const
{
	const Vec2 half = Vec2(rad, rad);
	return RectF( pos - half, pos + half);
}

void Ball::CheckAndResetJumpCounter( float bottomWall )
{
	if (pos.y + rad >= bottomWall)
	{
		jumpCounter = 0;
	}
}
