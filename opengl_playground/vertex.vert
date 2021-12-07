#version 330 core
layout (location = 0) in vec3 aPos;   // 位置变量的属性位置值为 0 
//layout (location = 1) in vec3 aColor; // 颜色变量的属性位置值为 1
//layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aNormal;


// out vec4 vertexColor; // 向片段着色器输出一个颜色
out vec2 texCoord;
out vec3 fragPos;
out vec3 normal;

// uniform mat4 transform;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;
void main()
{
	gl_Position = projMat * viewMat * modelMat * vec4(aPos.x,aPos.y,aPos.z, 1.0);
	fragPos = (modelMat * vec4(aPos.x,aPos.y,aPos.z, 1.0)).xyz; 
	normal = mat3(modelMat) * aNormal;
    // gl_Position = transform * vec4(aPos.x,aPos.y,aPos.z, 1.0);
    // vertexColor = vec4(aColor.x,aColor.y,aColor.z,1.0); // 将ourColor设置为我们从顶点数据那里得到的输入颜色
//	texCoord = aTexCoord;
}