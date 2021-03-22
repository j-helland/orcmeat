// std
#include <iostream>

// extern
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// game_library
#include <lib.hpp>

// TODO: probably move window creation/management to separate source file
// TODO: probably move main game loop to a "game_engine" or smth in the game library

GLFWwindow* open_window();
void error(int code, const char* description, bool quit);
void glfw_error(int code, const char* description);
void game_loop(GLFWwindow* window);

int main(void) {

    // Create window and start game loop
    GLFWwindow* window = open_window();
    game_loop(window);

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void game_loop(GLFWwindow* window) {

    while (!glfwWindowShouldClose(window)) {
        
        // input
        glfwPollEvents();

        // update

        // render
        // Need to do glClear before glfwSwapBuffers, otherwise we get crazy flashing (on my macbook at least) due to use of uninitialized framebuffer memory. 
        glClear(GL_COLOR_BUFFER_BIT); 
        glfwSwapBuffers(window);
    }

}

GLFWwindow* open_window() {

    // Will be called anytime a GLFW error occurs
    glfwSetErrorCallback(glfw_error);

    // Initialize GLFW, throw error if GLFW_FALSE returned
    if (!glfwInit()) error(-1, "could not initialize GLFW", true);
    
    // This is fun: https://www.glfw.org/docs/latest/spaces.svg
    // Screen coordinates != pixels; think mac retina

    // Set window hints
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);        // Window should be resizable
    glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);          // To piss you off if you open it & want to do smth else while it opens
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);     // Enable double buffering
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API); // As opposed to OpenGL ES or smth
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // MacOS bullshit
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window which also serves as our context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Orcmeat", NULL, NULL);
    if (!window) error(-1, "could not create window", true);
    glfwMakeContextCurrent(window);
    
    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) error(-1, "couldn't initialize GLAD", true);

    // Enable Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return window;
}   

void error(int code, const char* description, bool quit) {
    std::cerr << "ERROR (code: " << code << "): " << description << std::endl;
    if (quit) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    } 
}

void glfw_error(int code, const char* description) { 
    error(code, description, false); // quit = false bc "Reported [GLFW] errors are never fatal"
} 
