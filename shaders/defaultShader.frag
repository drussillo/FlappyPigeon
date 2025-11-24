#version 420 core

in vec4 vColor;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;

void main() {
  // FragColor = texture(texture1, TexCoord) * vColor;
  FragColor = texture(texture1, TexCoord);
  // FragColor = vColor;
}
