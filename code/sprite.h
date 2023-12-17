#pragma once
#include <SFML/Graphics.hpp>


namespace game 
{
class Sprite
	{
private:
	RenderWindow s_Window;
	Font s_font;
	Text text;
	Text titleText;
	Text startText;

	void input();
	void update();
	void draw();

	bool titleScreen;
	bool infoScreen;
	bool gameScreen;

	Texture backgroundTexture;
	Texture forest_texture;
	Texture spring_texture;
	Texture airy_texture;

public:
	Sprite();
	void run();
	};
}