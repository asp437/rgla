#version 330 core

in vec3 ourColor;
in vec2 texCoord;

out vec4 FragColor;

uniform float brightness;
uniform sampler2D texture0;
uniform sampler2D texture1;

void main() {
    FragColor = mix(texture(texture0, texCoord), texture(texture1, texCoord), 0.2);
    // FragColor = vec4(ourColor * brightness, 1.0);
}
