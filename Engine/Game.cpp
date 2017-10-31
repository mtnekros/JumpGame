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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(200.0f, 50.0f)),
	walls(0.0f, float(Graphics::ScreenWidth)-100.0f, 0.0f, float(Graphics::ScreenHeight)-100.0f)
{
	for (int i = 0; i < nObstacles; i++)
	{
		obstacle[i] = Obstacle(walls);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Update( wnd.kbd, dt);
	ball.ClampToWall( walls );
	for ( Obstacle& ob : obstacle )
	{
		ob.Update(dt);
	}
	for (Obstacle& ob : obstacle)
	{
		if (ob.GetRect().right < walls.left)
		{
			ob.Respawn(walls);
		}
	}
}

void Game::ComposeFrame()
{
	ball.Draw(gfx);
	for (Obstacle& ob : obstacle)
	{
		ob.Draw(gfx, walls);
	}
}
