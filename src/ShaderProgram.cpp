//
// Created by sam on 2/20/19.
//

#include "ShaderProgram.h"

struct ShaderProgram *new_shader(char *vertexSource, char *fragmentSource) {
  struct ShaderProgram* s =(struct ShaderProgram*) malloc(sizeof(struct ShaderProgram));

  compile_vertex_shader(s, vertexSource);
  compile_fragment_shader(s, fragmentSource);

  s->shaderProgram = glCreateProgram();
  glAttachShader(s->shaderProgram, s->vertexShader);
  glAttachShader(s->shaderProgram, s->fragmentShader);
  glLinkProgram(s->shaderProgram);

  int success;
  char infolog[1024];
  glGetProgramiv(s->shaderProgram, GL_LINK_STATUS, &success);


  if (!success) {
    glGetProgramInfoLog(s->shaderProgram, 1024, NULL, infolog);
    printf("Failed Program Compilation, error incoming. \n %s", infolog);
  }

  s-> time_variable = glGetUniformLocation(s->shaderProgram, "seconds");
  s-> scanline_variable = glGetUniformLocation(s->shaderProgram, "scanline");


  return s;
}

void check_success_of_shader(unsigned int shader, char* type) {
  int success;
  char infolog[1024];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(shader, 1024, NULL, infolog);
    printf("Failed Shader: %s, error incoming. \n %s", type, infolog);
  }

}

void compile_vertex_shader(struct ShaderProgram *s, char *source) {

  s->vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const char* safe_source = source;
  glShaderSource(s->vertexShader, 1, &safe_source, NULL);
  glCompileShader(s->vertexShader);
  check_success_of_shader(s->vertexShader, "Vertex Shader");


}

void compile_fragment_shader(struct ShaderProgram *s, char *source) {
  s->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char* safe_source = source;
  glShaderSource(s->fragmentShader, 1, &safe_source, NULL);
  glCompileShader(s->fragmentShader);
  check_success_of_shader(s->fragmentShader, "Fragment Shader");
}
