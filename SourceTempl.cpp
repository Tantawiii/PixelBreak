#include "Inclusions.h"

using namespace std;
using namespace glm;

// The Width of the screen
const unsigned int SCREEN_WIDTH = 1200;
const unsigned int SCREEN_HEIGHT = 900;

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main()
{
    // Create an SFML window
    sf::Window window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Breakout", sf::Style::Close);
    window.setFramerateLimit(60);

    // Initialize game
    glewInit();
    Breakout.Init();

    // deltaTime variables
    float deltaTime = 0.0f;
    sf::Clock clock;

    // Game loop
    while (window.isOpen())
    {
        // Calculate delta time
        deltaTime = clock.restart().asSeconds();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }         
        }

        // Manage user input
        Breakout.ProcessInput(deltaTime, window);

        // Update game state
        Breakout.Update(deltaTime);

        // Render
        //window.clear(sf::Color::Black);
        Breakout.Render();
        window.display();
    }

    // Delete all resources as loaded using the resource manager
    ResourceManager::Clear();

    return 0;
}