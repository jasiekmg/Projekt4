// Project1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Paddle.h"

using namespace std;
using namespace sf;

int main()
{
	Paddle paddle(400, 550);
	RenderWindow window{ VideoMode {800,600}, "dzwig" };
	window.setFramerateLimit(60);
	Event event;
	while (true)
	{
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		paddle.update();
		window.draw(paddle);
		window.display();

	}


	return 0;
}