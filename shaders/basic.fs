#version 330 core

in vec3 vColor;
in vec2 texCoord;

out vec4 FragColor;

uniform float brightness;
uniform float opaque;
uniform sampler2D tex;

void main() {
    FragColor = texture(tex, texCoord) * vec4(vColor, 1.0) * vec4(vec3(brightness), opaque);
}
