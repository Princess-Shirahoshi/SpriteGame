// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include "sprite.h"


using namespace sf;
using namespace std;

Sprite::Sprite() : s_Window(VideoMode(1920, 1080), "Flower Fields", Style::Default)

int main()
{
	// Create a video mode object
	//VideoMode vm(1920, 1080);

	//RenderWindow window(vm, "Flower Fields", Style::Default);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("mondt_theme.png");
	cout << "Texture size: "<< textureBackground.getSize().x << " x " << textureBackground.getSize().y << " y " << endl;

	// Create a sprite
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);


    View view(FloatRect(0, 0, static_cast<float>(textureBackground.getSize().x), static_cast<float>(textureBackground.getSize().y)));
    window.setView(view);

	 Font font;
    if (!font.loadFromFile("Pacifico.ttf")) 
    {
        // Displays message to user if font domesn't load
        cout << "Error loading font!" << endl;
        // returns error and exits program
        return -1;
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


	while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
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
                    window.setView(view);
                }
                else
                {
                    // Window is taller than the image, adjust width
                    float newWidth = static_cast<float>(event.size.height) * aspectRatioImage;
                    View view(FloatRect(0, 0, newWidth, static_cast<float>(event.size.height)));
                    window.setView(view);
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
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);
		window.draw(titleText);

		// Show everything we just drew
		window.display();


	}

	return 0;
}
