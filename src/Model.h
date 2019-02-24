//
// Created by sam on 2/20/19.
//

#ifndef WEALTHOFNATIONS_MODEL_H
#define WEALTHOFNATIONS_MODEL_H

#include <stdlib.h>

#include "../include/glad/glad.h"
#include "ShaderProgram.h"

#include <glm/glm.hpp>


struct Model {
  unsigned int vaoID;
  int vertexCount;
  struct ShaderProgram* s;

};


struct Model* create_model(char* model_filepath, struct ShaderProgram* s);
void draw(struct Model* m);
void delete_model(struct Model* m);



#endif //WEALTHOFNATIONS_MODEL_H
