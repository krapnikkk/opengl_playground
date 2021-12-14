﻿#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 texCoord;

uniform sampler2D sampler;

void main()
{
//    FragColor = vec4(vertexColor, 1.0f);
    FragColor = texture(sampler, texCoord) * vec4(vertexColor,1.0);
}