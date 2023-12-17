// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include "sprite.h"


using namespace sf;
using namespace std;


namespace game {
Sprite::Sprite() : s_Window(VideoMode(1920, 1080), "Flower Fields", Style::Default)
{

	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("mondt_theme.png");
	cout << "Texture size: "<< textureBackground.getSize().x << " x " << textureBackground.getSize().y << " y " << endl;

	// Create a sprite
	Sprite spriteBackground;
	//spriteBackground.setTexture(textureBackground);
	//spriteBackground.setPosition(0, 0);


    View view(FloatRect(0, 0, static_cast<float>(textureBackground.getSize().x), static_cast<float>(textureBackground.getSize().y)));
    s_Window.setView(view);

	 Font font;
    if (!font.loadFromFile("Pacifico.ttf")) 
    {
        // Displays message to user if font domesn't load
        cout << "Error loading font!" << endl;
        // returns error and exits program
    }

	Text text;
	text.setFont(font);
	text.setCharacterSize(60);
	text.setString("Flower Fields");
	text.setPosition(10, 10);

	Text titleText;
    
    titleText.setFont(font);
    titleText.setCharacterSize(250);
    titleText.setFillColor(Color(238, 130, 180));
    titleText.setOutlineColor(Color::White);
    titleText.setOutlineThickness(2);
    titleText.setPosition(150, 140);
    titleText.setString("Flower Fields"); //Adds title screen 
}

void input()
{
	while (s_Window.isOpen())
    {
        Event event;
        while (s_Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                s_Window.close();
            }
            else if (event.type == Event::Resized)
            {
                // Adjust the view to maintain the correct aspect ratio
                float aspectRatioWindow = static_cast<float>(event.size.width) / static_cast<float>(event.size.height);
                float aspectRatioImage = static_cast<float>(textureBackground.getSize().x) / static_cast<float>(textureBackground.getSize().y);

                if (aspectRatioWindow > aspectRatioImage)
                {
                    // Window is wider than the image, adjust height
                    float newHeight = static_cast<float>(event.size.width) / aspectRatioImage;
                    View view(FloatRect(0, 0, static_cast<float>(event.size.width), newHeight));
                    s_Window.setView(view);
                }
                else
                {
                    // Window is taller than the image, adjust width
                    float newWidth = static_cast<float>(event.size.height) * aspectRatioImage;
                    View view(FloatRect(0, 0, newWidth, static_cast<float>(event.size.height)));
                    s_Window.setView(view);
                }
            }
        }
    }
}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/


		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last frame
		s_Window.clear();

		// Draw our game scene here
		s_Window.draw(spriteBackground);
		s_Window.draw(titleText);

		// Show everything we just drew
		s_Window.display();


	}
}