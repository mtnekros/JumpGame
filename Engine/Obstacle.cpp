#include "Obstacle.h"
#include <random>
#include <algorithm>

Obstacle::Obstacle( const RectF& walls)	
{
	Respawn( walls );
}


void Obstacle::Respawn(const RectF& walls)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> width_dist(minWidth, maxWidth);
	std::uniform_real_distribution<float> height_dist(minHeight, maxHeight);
	
	width = width_dist(rng);
	height = height_dist(rng);
	
	topLeft = Vec2(walls.right , walls.bottom - height);

}

void Obstacle::Update(float dt)
{
	topLeft.x += vel_x*dt;
}

void Obstacle::Draw(Graphics & gfx, const RectF& walls)
{
	const RectF rect = GetRect();
	for (int y = int(rect.top); y < int(rect.bottom); ++y)
	{
		for (int x = int(rect.left); x < int(rect.right); ++x)
		{

			if (walls.Contains(Vec2( float(x), float(y) )))
			{
				gfx.PutPixel(x, y, c);
			}
		}
	}
}

RectF Obstacle::GetRect() const
{
	return RectF(topLeft, width, height);
}
