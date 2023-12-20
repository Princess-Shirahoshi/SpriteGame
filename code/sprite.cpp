#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


enum GameState
{
    Title,
    Info,
    Game
};

GameState currentState = GameState::Title;

int main()
{
    
    VideoMode vm(1920, 1080);

    RenderWindow window(vm, "Flower Fields", Style::Default);

    //Sprite here + Sprite stuffies so I don't get confused
    Texture spriteSheet;
    spriteSheet.loadFromFile("test_sprite_sheet.png");
    
    IntRect sourceRectLeft(150, 1475, 150, 415);
    IntRect sourceRectRight(150, 1000, 150, 415);
    IntRect sourceRect = sourceRectRight;
    Sprite sprite;
    sprite.setTexture(spriteSheet);
    sprite.setTextureRect(sourceRect);
    sprite.setPosition((window.getSize().x - sprite.getLocalBounds().width) / 2,
                   (window.getSize().y - sprite.getLocalBounds().height) / 2 + 600);
    //float movementSpeed = 5.0f;
    //_______________________________________//




    // Flowers here 
    Texture flowerOverlayTexture;
    flowerOverlayTexture.loadFromFile("spritesheet_flowers.png"); 

    IntRect sourceFlowerLeft(170, 5762, 670, 938);
    //IntRect sourceRectRight(150, 1000, 150, 415);
    //Sprite leftFlowerOverlay;
    //Sprite rightFlowerOverlay;
    
    //leftFlowerOverlay.setTexture(flowerOverlayTexture);
    //rightFlowerOverlay.setTexture(flowerOverlayTexture);
    Sprite flower;
    flower.setTexture(flowerOverlayTexture);
    flower.setTextureRect(sourceFlowerLeft);
    flower.setPosition((window.getSize().x - flower.getLocalBounds().width) / 2 + 800,
                   (window.getSize().y - flower.getLocalBounds().height) / 2 + 350);
    

    Texture flowerTexture;
    

    //___________________________________________//

    //Texture Backgrounds here    
    Texture textureBackground;
    textureBackground.loadFromFile("title.png");

    Texture textureInfoBackground;
    textureInfoBackground.loadFromFile("info.jpg");

    Texture textureGameBackground;
    textureGameBackground.loadFromFile("main.png");

    //Sprite backgrounds here
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    Sprite spriteInfoBackground;
    spriteInfoBackground.setTexture(textureInfoBackground);

    Sprite spriteMainBackground;
    spriteMainBackground.setTexture(textureGameBackground);
    

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
    infoText.setFillColor(Color(200, 100, 250));
    infoText.setOutlineColor(Color::White);
    infoText.setOutlineThickness(1);
    infoText.setPosition(700, 500);
    infoText.setString("How to play: \n 1: Flowers will spawn \n 2. Walk over to the flowers to loot them \n 3. Enjoy the flowers!");

    Text gameText; 
    gameText.setFont(font);
    gameText.setCharacterSize(100);
    gameText.setFillColor(Color::Green);
    gameText.setOutlineColor(Color::White);
    gameText.setOutlineThickness(1);
    gameText.setPosition(500, 300);
    //gameText.setString(""); // If I want to add text on the main flower scene


    //bool titleScreen = true;



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
            
                switch (currentState)
                {
                case GameState::Title:
                    currentState = GameState::Info;
                    break;
                case GameState::Info:
                    currentState = GameState::Game;
                    break;
                case GameState::Game:
                    break;
                }
            }
        }

        window.clear();


        switch (currentState)
        {
        case GameState::Title:
            window.draw(spriteBackground);
            window.draw(titleText);
            window.draw(subText);
            break;

        case GameState::Info:
            window.draw(spriteInfoBackground);
            window.draw(infoText);
            break;

        case GameState::Game:
             window.draw(spriteMainBackground);
            window.draw(gameText);
            window.draw(sprite);


            window.draw(flower);

            Vector2f spritePosition = sprite.getPosition();
            float movementSpeed = 5.0f;

            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                int xTexture = 0;
                xTexture = sprite.getPosition().x;
                IntRect sourceRect(xTexture, 137, 130, 118);
                spritePosition.x -= movementSpeed;
            }

            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                IntRect sourRect(10, 260, 130, 118);
                spritePosition.x += movementSpeed;
            }

            sprite.setPosition(spritePosition);

            break;
        }
 
        window.display();
    }

    return 0;
}