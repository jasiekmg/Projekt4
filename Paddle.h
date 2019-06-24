#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class Paddle : public sf::Drawable
{
public:
	Paddle(float t_X, float t_Y);
	Paddle() = delete;
	~Paddle() = default;
	void update();
	float right();
	float left();
	float top();
	float bottom();

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
	const float paddleWidth{ 3.0f };
	const float paddleHeight{ 400.0f };
	const float paddleVelocity{ 4.0f };
	Vector2f velocity{ paddleVelocity, paddleVelocity };
};

