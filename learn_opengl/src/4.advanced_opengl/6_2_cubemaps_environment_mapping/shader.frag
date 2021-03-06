#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 Position;

uniform vec3 cameraPos;
uniform samplerCube uSampler;

void main()
{
    float ratio = 1.00 / 1.52;//光线/视线从空气进入玻璃折射率
	vec3 I = normalize(Position - cameraPos);
    vec3 R = refract(I, normalize(Normal),ratio);
    FragColor = vec4(texture(uSampler, R).rgb, 1.0);
}