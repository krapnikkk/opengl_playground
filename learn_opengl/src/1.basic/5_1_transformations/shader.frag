#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 texCoord;

uniform sampler2D sampler1;
uniform sampler2D sampler2;

void main()
{
//    FragColor = vec4(vertexColor, 1.0f);
//    FragColor = texture(sampler2, texCoord);
    FragColor = mix(texture(sampler1, texCoord),texture(sampler2, texCoord),0.2);
}