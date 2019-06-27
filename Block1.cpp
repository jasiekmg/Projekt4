#include "Block1.h"


Block1::Block1(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ this->block1Width,this->block1Height });
	shape.setFillColor(Color::Green);
	shape.setOrigin(block1Width / 2.f, block1Height / 2.f);


}

void Block1::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->shape, state);

}

void Block1::update()
{
	/*this->shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0) { velocity.x = -paddleVelocity; }
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800) { velocity.x = paddleVelocity; }
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0) { velocity.y = -paddleVelocity; }
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < 600) { velocity.y = paddleVelocity; }
	else
	{
		velocity.x = 0;
		velocity.y = 0;
	} */
}

void Block1::rysuj()
{
	this->shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 220 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.x = -block1Velocity; }
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 560 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.x = block1Velocity; }
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.y = -block1Velocity; }
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < 490 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.y = block1Velocity; }
	else
	{
		velocity.x = 0;
		velocity.y = 0;
	}

}

void Block1::grawitacja()
{
	this->shape.move(this->velocity);
		if (this->bottom() < 490) { velocity.y = block1Velocity; }
		else
		{
			velocity.x = 0;
			velocity.y = 0;

		}
}


float Block1::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Block1::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Block1::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Block1::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}