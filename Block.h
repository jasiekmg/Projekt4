#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;



class Block : public sf::Drawable
{
public:
	Block(float t_X, float t_Y);
    Block() = delete;
	~Block() = default;
	void update();
	void rysuj();
	float right();
	float left();
	float top();
	float bottom();
	int masa = 300;

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
	const float blockWidth{ 40.0f };
	const float blockHeight{ 40.0f };
	const float blockVelocity{ 4.0f };
	Vector2f velocity{ blockVelocity, blockVelocity };
};

