#version 330 core

in vec4 vColor;
in vec2 texCoord;

out vec4 FragColor;

uniform float brightness;
uniform float opaque;
uniform sampler2D tex;

void main() {
    FragColor = texture(tex, texCoord) * vColor * vec4(vec3(brightness), opaque);
}
