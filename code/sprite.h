#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

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