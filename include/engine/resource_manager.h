#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H


#include <glm/gtc/matrix_transform.hpp>

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "graphics/mesh.h"
#include "graphics/shader.h"
#include "graphics/texture.h"


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


  // construct and add texture to map
  void loadTexture(const std::string &textureName,
                   const std::string &path,
                   int width,
                   int height,
                   int nrChannels);
  std::shared_ptr<Texture> getTexture(const std::string &textureName);
  // std::shared_ptr<Texture> loadAndGetTexture()
  void unloadTexture(const std::string &textureName);


  // stops tracking all resources by removing them from maps
  void clear();

private:
  std::unordered_map<std::string, std::shared_ptr<Mesh>> loadedMeshes;
  std::unordered_map<std::string, std::shared_ptr<Shader>> loadedShaders;
  std::unordered_map<std::string, std::shared_ptr<Texture>> loadedTextures;

  bool hasMesh(const std::string &meshName);
  bool hasShader(const std::string &shaderName);
  bool hasTexture(const std::string &textureName);
};


namespace res {

std::string relPath(const std::string &path);

}


#endif
