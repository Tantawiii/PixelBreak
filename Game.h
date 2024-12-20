#ifndef GAME_H
#define GAME_H

#include "Inclusions.h"

//using sf::SoundBuffer;
//using sf::Sound;

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Represents the four possible (collision) directions
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// Defines a Collision typedef that represents collision data
typedef std::tuple<bool, Direction, glm::vec2> Collision; // <collision?, what direction?, difference vector center - closest point>

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const float BALL_RADIUS = 12.5f;

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
//private:
//    std::vector<SoundBuffer> MusicBuffers; // Holds buffers for all levels
//    Sound BackgroundSound; // Single Sound object to play the current level's music
public:
    // game state
    GameState               State;
    unsigned int            Width, Height;
    std::vector<GameLevel>  Levels;
    std::vector<PowerUp>    PowerUps;
    unsigned int            Level;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt, const sf::Window& window);
    void Update(float dt);
    void Render();
    void DoCollisions();
    // reset
    void ResetLevel();
    void ResetPlayer();
    // powerups
    void SpawnPowerUps(GameObject& block);
    void UpdatePowerUps(float dt);

    //void InitMusic(); // Initialize music buffers
    //void playBackgroundMusic(int level); // Play music for the current level
};

#endif