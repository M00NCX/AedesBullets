#include <SDL/SDL.h>
#include <GL/glew.h>
#include "SDL_opengl.h"
#include <Player.h>
#include <stdio.h>
#include <iostream>

bool init(SDL_Window*& window, SDL_GLContext& glContext) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erro ao inicializar o SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Combate ao Mosquito da Dengue", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "Erro ao criar a janela SDL: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "Erro ao criar o contexto OpenGL: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Erro ao inicializar o GLEW: " << glewGetErrorString(err) << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "Erro ao inicializar SDL_image: " << IMG_GetError() << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    std::cout << "Inicialização bem-sucedida!" << std::endl;
    return true;
}

void render(Player& player) {
    glClear(GL_COLOR_BUFFER_BIT);
    player.render();
}

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_GLContext glContext;

    if (!init(window, glContext)) {
        return -1;
    }

    Player player;
    if (!player.loadTexture("C:/Users/vinic/OneDrive/Documentos/Aedes Combat/img/Personagem_outono_lado_direito 2.png")) {
        std::cerr << "Erro ao carregar a textura do jogador" << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    Uint32 lastTime = SDL_GetTicks();

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            player.handleEvent(event);
        }

        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        player.update(deltaTime);
        render(player);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}