#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vColor;
out vec2 texCoord;

uniform mat4 transform;

void main() {
    gl_Position = transform * vec4(vPos, 1.0);
    vColor = aColor;
    texCoord = aTexCoord;
}
