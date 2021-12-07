#version 330 core
layout (location = 0) in vec3 aPos;   // λ�ñ���������λ��ֵΪ 0 
//layout (location = 1) in vec3 aColor; // ��ɫ����������λ��ֵΪ 1
//layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aNormal;


// out vec4 vertexColor; // ��Ƭ����ɫ�����һ����ɫ
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
    // vertexColor = vec4(aColor.x,aColor.y,aColor.z,1.0); // ��ourColor����Ϊ���ǴӶ�����������õ���������ɫ
//	texCoord = aTexCoord;
}