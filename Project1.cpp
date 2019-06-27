// Project1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Paddle.h"
#include "Block.h"
#include "Block1.h"

using namespace std;
using namespace sf;

int masa = 200;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom(); //skala rosnie w dol
} 

bool kolizjatest(Block& block, Paddle& paddle)
{
	if (!isIntersecting(block, paddle)) return false;
	else if (block.masa <= masa) block.rysuj();
	else;

	if ((Keyboard::isKeyPressed(Keyboard::Key::A)));
	else block.grawitacja();

}

bool kolizjatest1(Block1& block1, Paddle& paddle)
{
	if (!isIntersecting(block1, paddle)) return false;
	else if (block1.masa <= masa) block1.rysuj();
	else;

	    if ((Keyboard::isKeyPressed(Keyboard::Key::A)));
		else block1.grawitacja();

	
}


bool gra(Block& block, Paddle& paddle)
{
	if (!isIntersecting(block, paddle)) block.grawitacja();
	else return false;

}

bool gra1(Block1 & block1, Paddle & paddle)
{
	if (!isIntersecting(block1, paddle)) block1.grawitacja();
	else return false;
}


int main()

{	
	sf::Texture tekstura;
	tekstura.loadFromFile("1.png");
	sf::Sprite obrazek;
	obrazek.setTexture(tekstura);


	Paddle paddle(370, 200);
	Block block(420, 470);
	Block1 block1(350, 470);
	RenderWindow window{ VideoMode {800,600}, "dzwig" };
	window.setFramerateLimit(60);
	Event event;
	while (true)
	{
		window.clear(Color::White);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		paddle.update();
		window.draw(block1);
		window.draw(block);
		

		window.draw(paddle);
		kolizjatest(block, paddle);
		kolizjatest1(block1, paddle);
		gra(block, paddle);
		gra1(block1, paddle);
		window.draw(obrazek);
		window.display();

	}


	return 0;
}