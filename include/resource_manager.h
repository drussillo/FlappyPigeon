#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H


#include <glm/gtc/matrix_transform.hpp>

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "mesh.h"
#include "shader.h"


class ResourceManager {
public:
  ResourceManager() = default;

  // construct and add mesh to map
  void loadMesh(const std::string &meshName,
                const std::vector<float> &vertices,
                const std::vector<unsigned int> &attributeSizes,
                const std::vector<unsigned int> &indices={},
                const GLenum primitiveType=GL_TRIANGLES);
  std::shared_ptr<Mesh> getMesh(const std::string &meshName);
  std::shared_ptr<Mesh> loadAndGetMesh(const std::string &meshName,
                                       const std::vector<float> &vertices,
                                       const std::vector<unsigned int> &attributeSizes,
                                       const std::vector<unsigned int> &indices={},
                                       const GLenum primitiveType=GL_TRIANGLES);
  void unloadMesh(const std::string &meshName);

  // construct and add shader to map
  void loadShader(const std::string &shaderName,
                  const std::string &vertexPath="",
                  const std::string &fragmentPath="");
  std::shared_ptr<Shader> getShader(const std::string &shaderName);
  std::shared_ptr<Shader> loadAndGetShader(const std::string &shaderName,
                                           const std::string &vertexPath="",
                                           const std::string &fragmentPath="");
  void unloadShader(const std::string &shaderName);

  // stops tracking all resources by removing them from maps
  void clear();

  bool hasMesh(const std::string &meshName);
  bool hasShader(const std::string &shaderName);

private:
  glm::mat4 projection = glm::ortho(0.0f, 720.0f, 0.0f, 720.0f);
  std::unordered_map<std::string, std::shared_ptr<Mesh>> loadedMeshes;
  std::unordered_map<std::string, std::shared_ptr<Shader>> loadedShaders;
  // std::unordered_map<std::string, std::shared_ptr<Texture>> loadedTextures;
};


#endif
