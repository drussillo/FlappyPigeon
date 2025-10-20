#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() {

  /*****************************************************************/
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return -1;
  }

  // Set OpenGL version and profile (3.3 core)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  /*****************************************************************/
  

  int res_w = 1920;
  int res_h = 1080;
  bool fullscreen = true;

  GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

  // Create a window
  GLFWwindow* window = glfwCreateWindow(res_w, res_h, "FlappyPigeon", monitor, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Load OpenGL function pointers using GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cerr << "Failed to initialize GLAD\n";
      return -1;
  }

  glViewport(0, 0, res_w, res_h);
  /*****************************************************************/
  /* shader program */

  const char *vertexShaderSource = ""
    "#version 330 core \n"
    "layout(location = 0) in vec3 aPos;"
    "layout(location = 1) in vec4 aColor;"

    "out vec4 vColor;"

    "void main() {"
      "gl_Position = vec4(aPos, 1.0);"
      "vColor = aColor;"
    "}";
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);
  int success;
  char log[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(vertexShader, 512, nullptr, log);
    std::cerr << "Vertex shader compilation failed.\n" << log << std::endl;
    exit(1);
  }

  const char *fragmentShaderSource = ""
    "#version 330 core \n"
    "in vec4 vColor;"

    "out vec4 FragColor;"

    "void main() {"
      "FragColor = vColor;"
    "}";
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(fragmentShader, 512, nullptr, log);
    std::cerr << "Fragmen shader compilation failed.\n" << log << std::endl;
    exit(1);
  }

  // linking
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(!success) {
    glGetProgramInfoLog(shaderProgram, 512, nullptr, log);
    std::cerr << "Program linking failed.\n" << log << std::endl;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  /*****************************************************************/

  float triangle[] = {
    0.0f, 0.5f, 0.0f, 0.7f, 0.7f, 0.5f, 1.0f,  // top
    -0.5f, -0.5f, 0.0f, 0.0f, 0.3f, 0.0f, 1.0f,  // left
    0.5f, -0.5f, 0.0f, 0.7f, 1.0f, 0.7f, 1.0f  // right
  };

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_DYNAMIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glBindVertexArray(0);

  bool up = true;

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    /*****************************************/

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    
    if(triangle[1] >= 0.8f) 
      up = false;
    if(triangle[1] <= -0.2f)
      up = true;

    if(up) {
      triangle[1] += 0.025f;
      triangle[7] += 0.01f;
      triangle[14] -= 0.01f;
    } else {
      triangle[1] -= 0.025f;
      triangle[7] -= 0.01f;
      triangle[14] += 0.01f;
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_DYNAMIC_DRAW);

    glBindVertexArray(0);

    /*****************************************/
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Clean up
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
