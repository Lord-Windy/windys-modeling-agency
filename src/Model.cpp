//
// Created by sam on 2/20/19.
//

//#include "Model.h"
//
//
//
//
//
//void unbind_vao() {
//  glBindVertexArray(0);
//}
//
//cgltf_result load_model(cgltf_data** data, char* path) {
//
//  cgltf_options options = {0};
//  cgltf_result result =cgltf_parse_file(&options, path, data);
//
//  if (result == cgltf_result_success) {
//    result = cgltf_load_buffers(&options, *data, path);
//  }
//
//  if (result == cgltf_result_success) {
//    result = cgltf_validate(*data);
//  }
//
//
//  return result;
//
//}
//
//
//struct Model* create_model(char* model_filepath, struct ShaderProgram* s) {
//  struct Model* m = malloc(sizeof(struct Model));
//  cgltf_data* data = NULL;
//
//  glGenVertexArrays(1, &(m->vaoID));
//  glBindVertexArray(m->vaoID);
//
//  if (load_model(&data, model_filepath) != cgltf_result_success) {
//    printf("Cannot load the model");
//    return NULL;
//  }
//
//  printf("Nodes Count:%lu\n",data->nodes_count );
//
//  for (int i = 0; i < data->nodes_count; i++) {
//    if (data->nodes[i].mesh != NULL) {
//      printf("\n");
//      printf("Node%d Primitive Count:%lu\n", i,data->nodes[i].mesh->primitives_count);
//
//
//      for (int j = 0; j < data->nodes[i].mesh->primitives_count; j++){
//        printf("\n");
//        /*printf("Primitives%d Indices Type:%u\n", j,data->nodes[i].mesh->primitives[j].indices->type);
//        printf("Primitives%d Indices Count:%lu\n", j,data->nodes[i].mesh->primitives[j].indices->count);*/
//        printf("Primitives%d Buffer Type:%u\n", j,data->nodes[i].mesh->primitives[j].indices->buffer_view->type);
//        printf("Primitives%d Buffer Size:%lu\n", j,data->nodes[i].mesh->primitives[j].indices->buffer_view->size);
//        printf("Primitives%d Buffer Offset:%lu\n", j,data->nodes[i].mesh->primitives[j].indices->buffer_view->offset);
//
//
//
//
//
//
//      }
//
//    }
//    /*for (int j = 0; j < data->nodes[i].mesh->primitives_count; j++){
//      printf("Indicies count of Primitive %u: %lu\n",j,data->nodes->);
//      printf("Indices type: %s\n", data->meshes[i].primitives[j].indices->buffer_view->buffer->uri);
//
//
//    }*/
//
//  }
//
//
//
//
//  GLuint vbo = 0;
//  GLuint ebo = 0;
//  /*m->vertexCount = data_size;
//  m->s = s;
//
//  glGenBuffers(1, &vbo);
//  glGenBuffers(1, &ebo);
//
//
//
//  glBindBuffer(GL_ARRAY_BUFFER, vbo);
//  glBufferData(GL_ARRAY_BUFFER, data_size*sizeof(float), data, GL_STATIC_DRAW);
//
//  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
//  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size*sizeof(GLuint), indices, GL_STATIC_DRAW);
//  //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
//
//  glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//  glEnableVertexAttribArray(0);
//
//  glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//
//  */
//  unbind_vao();
//  cgltf_free(data);
//
//  return m;
//}
//
//void draw(struct Model *m) {
//
//  glUseProgram(m->s->shaderProgram);
//  glBindVertexArray(m->vaoID);
//  //glDrawArrays(GL_TRIANGLES, 0, m->vertexCount);
//  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//  unbind_vao(m->vaoID);
//
//}

