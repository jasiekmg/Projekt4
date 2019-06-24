#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;



class Block1 : public sf::Drawable
{
public:
	Block1(float t_X, float t_Y);
	Block1() = delete;
	~Block1() = default;
	void update();
	void rysuj();
	float right();
	float left();
	float top();
	float bottom();
	int masa =100;

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
	const float block1Width{ 40.0f };
	const float block1Height{ 40.0f };
	const float block1Velocity{ 4.0f };
	Vector2f velocity{ block1Velocity, block1Velocity };
};

