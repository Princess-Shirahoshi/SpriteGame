#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    
    VideoMode vm(1920, 1080);

    RenderWindow window(vm, "Flower Fields", Style::Default);

    
    Texture textureBackground;
    textureBackground.loadFromFile("mondt_theme.png");

    Texture textureInfoBackground;
    textureInfoBackground.loadFromFile("main_background.png");


    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    Sprite spriteInfoBackground;
    spriteInfoBackground.setTexture(textureInfoBackground);

    View view(FloatRect(0, 0, static_cast<float>(textureBackground.getSize().x), static_cast<float>(textureBackground.getSize().y)));
    window.setView(view);

    Font font;
    if (!font.loadFromFile("Pacifico.ttf"))
    {
        cout << "Error loading font!" << endl;
        return -1;
    }

    Text titleText;
    titleText.setFont(font);
    titleText.setCharacterSize(250);
    titleText.setFillColor(Color(238, 130, 180));
    titleText.setOutlineColor(Color::White);
    titleText.setOutlineThickness(2);
    titleText.setPosition(150, 140);
    titleText.setString("Flower Fields");

    Text subText;
    subText.setFont(font);
    subText.setCharacterSize(100);
    subText.setFillColor(Color(252, 137, 172));
    subText.setOutlineColor(Color::White);
    subText.setOutlineThickness(1);
    subText.setPosition(300, 400);
    subText.setString("Press any button to continue!");

    Text infoText;
    infoText.setFont(font);
    infoText.setCharacterSize(100);
    infoText.setFillColor(Color(200, 100, 142));
    infoText.setOutlineColor(Color::White);
    infoText.setOutlineThickness(1);
    infoText.setPosition(700, 500);
    infoText.setString("How to play: \n 1: Flowers will spawn \n 2. Walk over to the flowers to loot them \n 3. That is it!");


    bool titleScreen = true;

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
                float aspectRatioWindow = static_cast<float>(event.size.width) / static_cast<float>(event.size.height);
                float aspectRatioImage = static_cast<float>(textureBackground.getSize().x) / static_cast<float>(textureBackground.getSize().y);

                if (aspectRatioWindow > aspectRatioImage)
                {
                    float newHeight = static_cast<float>(event.size.width) / aspectRatioImage;
                    View view(FloatRect(0, 0, static_cast<float>(event.size.width), newHeight));
                    window.setView(view);
                }
                else
                {
                    float newWidth = static_cast<float>(event.size.height) * aspectRatioImage;
                    View view(FloatRect(0, 0, newWidth, static_cast<float>(event.size.height)));
                    window.setView(view);
                }
            }
            else if (event.type == Event::KeyPressed)
            {
                titleScreen = false;
            }
        }

        if (titleScreen)
        {
            window.clear();

            // Title
            window.draw(spriteBackground);
            window.draw(titleText);
            window.draw(subText);

            window.display();
        }
        else
        {
            window.clear();

            window.draw(spriteInfoBackground);
            window.draw(infoText);

            window.display();

        }
    }

    return 0;
}