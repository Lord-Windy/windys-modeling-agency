
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

void bind_node() {

}

struct Model* create_model(char* model_filepath, struct ShaderProgram* s) {
  auto m = (Model*) malloc(sizeof(struct Model));
  glGenVertexArrays(1, &(m->vaoID));
  glBindVertexArray(m->vaoID);

  //glGenBuffers(1, &vbo);
  //glGenBuffers(1, &ebo);

  m->gltf = new tinygltf::Model();

  load_model(m->gltf, model_filepath);

  auto* vbo = new GLuint[m->gltf->bufferViews.size()];
  auto* ebo = new GLuint[m->gltf->bufferViews.size()];

  for (int i = 0; i < m->gltf->bufferViews.size(); i++) {
    auto &bufferView = m->gltf->bufferViews[i];
    if (bufferView.target == 0) {
      printf("BufferView is not configured or something. I dunno\n");
      continue;
    }
    tinygltf::Buffer buffer = m->gltf->buffers[bufferView.buffer];
    glGenBuffers(1, &vbo[i]);
    glBindBuffer(bufferView.target, vbo[i]);
    glBufferData(bufferView.target, bufferView.byteLength,
                 &buffer.data.at(0) + bufferView.byteOffset, GL_STATIC_DRAW);
  }






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
  delete[] vbo;
  delete[] ebo;

  return m;
}

void draw(struct Model *m) {

  glUseProgram(m->s->shaderProgram);
  glBindVertexArray(m->vaoID);
  //glDrawArrays(GL_TRIANGLES, 0, m->vertexCount);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  unbind_vao();

}

