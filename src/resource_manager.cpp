#include "resource_manager.h"

#include <iostream>

#include "mesh.h"
#include "shader.h"


void ResourceManager::loadMesh(const std::string &meshName,
                               const std::vector<float> &vertices,
                               const std::vector<unsigned int> &attributeSizes,
                               const std::vector<unsigned int> &indices,
                               const GLenum primitiveType) {
  if(!hasMesh(meshName)) {
    loadedMeshes[meshName] = std::make_shared<Mesh>(vertices, attributeSizes, indices, primitiveType);
  } else {
    std::cerr << "Warning: attempted to load mesh resource twice. Mesh name: '" << meshName << "'" << std::endl;
  }
}

std::shared_ptr<Mesh> ResourceManager::getMesh(const std::string &meshName) {
  if(hasMesh(meshName)) {
    return loadedMeshes[meshName];
  } else {
    std::cerr << "Warning: attempted to get pointer to unloaded mesh. Mesh name: '" << meshName << "'" << std::endl;
    return nullptr;
  }
}

std::shared_ptr<Mesh> ResourceManager::loadAndGetMesh(const std::string &meshName,
                                                      const std::vector<float> &vertices,
                                                      const std::vector<unsigned int> &attributeSizes,
                                                      const std::vector<unsigned int> &indices,
                                                      const GLenum primitiveType) {
  loadMesh(meshName, vertices, attributeSizes, indices, primitiveType);
  return getMesh(meshName);
}

void ResourceManager::unloadMesh(const std::string &meshName) {
  if(hasMesh(meshName)) {
    loadedMeshes.erase(meshName);
  } else {
    std::cerr << "Warning: attempted to unload unloaded mesh. Mesh name: '" << meshName << "'" << std::endl;
  }
}


void ResourceManager::loadShader(const std::string &shaderName,
                const std::string &vertexPath,
                const std::string &fragmentPath) {
  if(!hasShader(shaderName)) {
    loadedShaders[shaderName] = std::make_shared<Shader>(vertexPath, fragmentPath);
  } else {
    std::cerr << "Warning: attempted to load shader resource twice. Shader name: '" << shaderName << "'" << std::endl;
  }
}

std::shared_ptr<Shader> ResourceManager::getShader(const std::string &shaderName) {
  if(hasShader(shaderName)) {
    return loadedShaders[shaderName];
  } else {
    std::cerr << "Warning: attempted to get pointer to unloaded shader. Shader name: '" << shaderName << "'" << std::endl;
    return nullptr;
  }
}

std::shared_ptr<Shader> ResourceManager::loadAndGetShader(const std::string &shaderName,
                                                          const std::string &vertexPath,
                                                          const std::string &fragmentPath) {
  loadShader(shaderName, vertexPath, fragmentPath);
  return getShader(shaderName);
}

void ResourceManager::unloadShader(const std::string &shaderName) {
  if(hasShader(shaderName)) {
    loadedShaders.erase(shaderName);
  } else {
    std::cerr << "Warning: attempted to unload unloaded shader. Shader name: '" << shaderName << "'" << std::endl;
  }
}


void ResourceManager::clear() {
  loadedMeshes.clear();
  loadedShaders.clear();
}

bool ResourceManager::hasMesh(const std::string &meshName) {
  return loadedMeshes.find(meshName) != loadedMeshes.end();
}

bool ResourceManager::hasShader(const std::string &shaderName) {
  return loadedShaders.find(shaderName) != loadedShaders.end();
}

