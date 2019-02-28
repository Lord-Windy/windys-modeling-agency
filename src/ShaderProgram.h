//
// Created by sam on 2/20/19.
//

#ifndef WEALTHOFNATIONS_SHADERPROGRAM_H
#define WEALTHOFNATIONS_SHADERPROGRAM_H

#include "../include/glad/glad.h"

#include <stdlib.h>
#include <stdio.h>

struct ShaderProgram {
  unsigned int vertexShader;
  unsigned int fragmentShader;
  unsigned int shaderProgram;
  GLint time_variable;
  GLint scanline_variable;
};



struct ShaderProgram* new_shader(char* vertexSource, char* fragmentSource);
void compile_vertex_shader(struct ShaderProgram* s, char* source);
void compile_fragment_shader(struct ShaderProgram* s, char* source);

#endif //WEALTHOFNATIONS_SHADERPROGRAM_H

