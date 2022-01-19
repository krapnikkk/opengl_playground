#version 330 core
out vec4 FragColor;

in vec3 TexCoords;
uniform samplerCube uSampler;

void main()
{
	vec4 texColor = texture(uSampler, TexCoords);
    FragColor = texColor;
}