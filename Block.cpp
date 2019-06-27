#include "Block.h"


Block::Block(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ this->blockWidth,this->blockHeight });
	shape.setFillColor(Color::Blue);
	shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);


}

void Block::draw(RenderTarget & target, RenderStates state) const
{
	target.draw(this->shape, state);

}

void Block::update()
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

void Block::rysuj()
{
	this->shape.move(this->velocity);
if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 220 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.x = -blockVelocity; }
else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 560 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.x = blockVelocity; }
else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.y = -blockVelocity; }
else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < 490 && (Keyboard::isKeyPressed(Keyboard::Key::A))) { velocity.y = blockVelocity; }
else
{
	velocity.x = 0;
	velocity.y = 0;
} 

}

void Block::grawitacja()
{
	this->shape.move(this->velocity);
     if (this->bottom() < 490) { velocity.y = blockVelocity; }
	else
	 {
		 velocity.x = 0;
		 velocity.y = 0;

	 }

}


float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Block::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}