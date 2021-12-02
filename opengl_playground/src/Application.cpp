#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Shader.h"

float vertices[] = {
-0.5f, -0.5f, 0.0f,1.0f,0,0,
 0.5f, -0.5f, 0.0f,0,1.0f,0,
 0.0f,  0.5f, 0.0f,0,0,1.0f,
 /*0.5f, -0.5f, 0.0f,
 0.0f,  0.5f, 0.0f,*/
 0.8f,  0.8f, 0.0f,0.3f,0.5f,0.7f
};

unsigned int indices[] = {
	0,1,2,
	2,1,3
};

const char* vertexShaderSource =
"#version 330 core \n "
"layout(location = 0) in vec3 aPos; \n"
"layout(location = 1) in vec3 aColor; \n"
"out vec4 vertexColor;\n"
"void main() { gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"vertexColor = vec4(aColor.x,aColor.y,aColor.z,1.0);\n"
"} \n";

const char* fragmentShaderSource =
"#version 330 core                                         \n"
//"uniform vec4 vertexColor;\n"
"in vec4 vertexColor;\n"
"out vec4 FragColor; \n"
"\n"
"void main() { FragColor = vertexColor; } \n";

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	Shader* shader = new Shader("vertex.txt", "fragment.txt");
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "opengl", NULL, NULL);

	if (window == NULL)
	{
		printf("open window failed!");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	int success;
	char infoLog[1024];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		printf(infoLog);
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	

	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);

		// VAO
		//glDrawArrays(GL_TRIANGLES, 0, 6);

		//VBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);

		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(shaderProgram,"vertexColor");
		glUniform4f(vertexColorLocation,0,greenValue,0,1.0f);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	return 0;
}
