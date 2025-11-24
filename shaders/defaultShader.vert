#version 420 core

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTexCoord;

layout(std140, binding = 0) uniform Matrices {
  mat4 uProjection;
};

uniform mat4 uTransform;

out vec4 vColor;
out vec2 TexCoord;

void main() {
  // gl_Position = uTransform * vec4(aPos, 1.0, 1.0);
  gl_Position = uProjection * uTransform * vec4(aPos, 0.0, 1.0);
  vColor = aColor;
  TexCoord = aTexCoord;
}
