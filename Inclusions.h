#pragma once

// GLEW must be included before any OpenGL headers
#include <gl/glew/glew.h>

// Core OpenGL and Graphics Libraries
//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// GLM (OpenGL Mathematics) Libraries
#include <gl/glm/glm.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>
#include <gl/glm/gtc/type_ptr.hpp>

// Standard Libraries
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

// Game Engine Headers

#include "Shader.h"
#include "Texture2D.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "GameLevel.h"
#include "PowerUp.h"
#include "Game.h"
#include "BallObject.h"
#include "ParticleGenerator.h"
#include "PostProcessor.h"
