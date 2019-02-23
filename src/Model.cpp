
// Created by sam on 2/20/19.


#include "Model.h"

// Define these only in *one* .cc file.
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
// #define TINYGLTF_NOEXCEPTION // optional. disable exception handling.
#include "tiny_gltf.h"



void unbind_vao() {
  glBindVertexArray(0);
}

int load_model(tinygltf::Model* m, char* path) {
  tinygltf::TinyGLTF loader;
  std::string err;
  std::string warn;

  bool ret = loader.LoadBinaryFromFile(m, &err, &warn, path);

  if (!warn.empty()) {
    printf("Warn: %s\n", warn.c_str());
  }

  if (!err.empty()) {
    printf("Err: %s\n", err.c_str());
  }

  if (!ret) {
    printf("Failed to parse glTF\n");
    return -1;
  }

  return 0;

}

struct Model* create_model(char* model_filepath, struct ShaderProgram* s) {
  auto m = (Model*) malloc(sizeof(struct Model));
  glGenVertexArrays(1, &(m->vaoID));
  glBindVertexArray(m->vaoID);
  GLuint vbo = 0;
  GLuint ebo = 0;
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);


  tinygltf::Model gltf;

  load_model(&gltf, model_filepath);





  /*m->vertexCount = data_size;
  m->s = s;





  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, data_size*sizeof(float), data, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size*sizeof(GLuint), indices, GL_STATIC_DRAW);
  //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

  glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);


  */
  unbind_vao();

  return m;
}

void draw(struct Model *m) {

  glUseProgram(m->s->shaderProgram);
  glBindVertexArray(m->vaoID);
  //glDrawArrays(GL_TRIANGLES, 0, m->vertexCount);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  unbind_vao();

}

