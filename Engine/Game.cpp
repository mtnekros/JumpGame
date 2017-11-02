/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <assert.h>
#include <algorithm>
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(200.0f, 50.0f)),
	walls(0.0f, float(Graphics::ScreenWidth), 150.0f, float(Graphics::ScreenHeight)-200.0f)
{
	std::random_device rd;
	std::mt19937 rng( rd() );
	std::uniform_real_distribution<float> gapBetweenObs(300.0f, 500.0f);
	float xStart = walls.right;
	for (int i = 0; i < nObstacles; i++)
	{
		obstacle[i] = Obstacle(walls,xStart);
		
		xStart += gapBetweenObs(rng);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0)
	{
		float dt = std::min(.0025f,elapsedTime);
		UpdateModel( dt );
		elapsedTime -= .0025f;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( float dt )
{
	if (!gameIsOver)
	{
		ball.Update(wnd.kbd, dt);
		ball.ClampToWall(walls);
		for (Obstacle& ob : obstacle)
		{
			ob.Update(dt);

			if (ob.GetRect().IsOverlappingWith(ball.GetRect()))
			{
				gameIsOver = true;
			}
			if (ob.GetRect().right < walls.left)
			{
				std::random_device rd;
				std::mt19937 rng( rd() );
				std::uniform_real_distribution<float> randomizer(0.0f,100.0f);
				ob.Respawn( walls, Graphics::ScreenWidth + randomizer(rng) ) ;
				
			}
		}

	}
}

void Game::DrawBorder()
{
	const RectF upperLine = RectF(walls.left, walls.right- 1.0f, walls.top - wallPadding, walls.top);
	const RectF groundLine = RectF(walls.left, walls.right - 1.0f , walls.bottom, walls.bottom + wallPadding);
	assert( upperLine.IsContainedBy(gfx.GetRect()) && groundLine.IsContainedBy(gfx.GetRect()) );
	gfx.DrawRect(upperLine, borderColor);
	gfx.DrawRect(groundLine, borderColor);
}

void Game::ComposeFrame()
{
	for (Obstacle& ob : obstacle)
	{
		ob.Draw(gfx, walls);
	}
	ball.Draw(gfx);
	
	DrawBorder();
}

