#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
uniform sampler2D uSampler;

void main()
{
	vec4 texColor = texture(uSampler, TexCoords);
    FragColor = texColor;
}