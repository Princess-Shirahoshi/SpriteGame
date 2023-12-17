#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Sprite
{
    private:
        Font s_font;

        RenderWindow s_Window;

        Text text;
        Text titleText;
        Text startText;

        bool titleScreen = true;
        bool infoScreen = true;

        Texture backgroundTexture;
        Sprite backgroundSprite;

        // Backgrounds

        Texture forest_texture;
        Texture spring_texture;
        Texture airy_texture;

    public:
        Sprite();
}