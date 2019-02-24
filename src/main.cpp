#include <iostream>

#include <stdio.h>

#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

#include "Helper.h"
#include "ShaderProgram.h"
#include "Model.h"

#define D_HEIGHT 800
#define D_WIDTH 800


void framebuffer_size_callback(GLFWwindow* w, int width, int height) {
  glViewport(0,0,width, height);
}

void process_input(GLFWwindow *window)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
}

struct ShaderProgram* test() {
  char* vert = nullptr;
  char* frag = nullptr;
  int size1 = load_from_file("./Shaders/vertexShader.vert", &vert);
  int size2 = load_from_file("./Shaders/fragmentShader.frag", &frag);


  if (size1 < 0 || size2 < 0) {
    printf("Couldn't load soz\n");
    return nullptr;
  } else {
    printf("Compiling Shader\n");
    return new_shader(vert,frag);
  }

}

int main(int argc, char** argv) {


  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  GLFWwindow* window = glfwCreateWindow(D_WIDTH, D_HEIGHT, "Wealth of Nations", NULL, NULL);

  if (window == NULL) {
    printf("Window failed to open\n");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    printf("Failed to initialize GLAD\n");
    return -1;
  }

  glViewport(0,0,D_WIDTH, D_HEIGHT);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  struct ShaderProgram* s = test();
  struct Model* m = create_model("Unfinished/Fridge.obj", s);


  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  while(!glfwWindowShouldClose(window))
  {
    process_input(window);



    glClearColor(0.78125f,0.6328125f,0.78125f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    draw(m);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;

}