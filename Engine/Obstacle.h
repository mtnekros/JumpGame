#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"

class Obstacle
{
public:
	Obstacle() = default;
	Obstacle( const RectF& walls, float xStart );
	void Respawn( const RectF& walls, float xStart );
	void Update( float dt );
	void Draw( Graphics& gfx, const RectF& walls );
	RectF GetRect() const;
private:
	static constexpr Color c = Colors::Red;
	static constexpr float maxWidth = 70;
	static constexpr float minWidth = 30;
	static constexpr float maxHeight = 110;
	static constexpr float minHeight = 50;
	static constexpr float vel_x = -200;
	Vec2 topLeft;
	float width;
	float height;
	
	
};