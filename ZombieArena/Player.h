#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	//Where is the player
	Vector2f m_Position;

	Sprite m_Sprite;
	Texture m_Texture;

	//Screen resolution
	Vector2f m_Resolution;

	//Arena size
	IntRect m_Arena;
	int m_TileSize;

	//Directions currently moving
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	
	int m_Health;
	int m_MaxHealth;
	Time m_LastHit;
	float m_Speed;

public:
	Player();
	void spawn(IntRect arena, Vector2f resolution, int tileSize);

	//Call this at the end of every game
	void resetPlayerStats();

	//Handle the player getting hit by a zombie
	bool hit(Time timeHit);

	Time getLastHitTime();
	FloatRect getPosition();
	Vector2f getCenter();
	float getRotation();
	Sprite getSprite();
	
	//Movment
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//Stop moving
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	void update(float elapsedTime, Vector2i mousePosition);

	void upgradeSpeed();
	void upgradeHealth();
	void increaseHealthLevel(int amount);
	int getHealth();
};
