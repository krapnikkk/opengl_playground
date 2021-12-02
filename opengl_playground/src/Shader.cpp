#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


Shader::Shader(const char* vertexPath,const char* fragmentPath)
{
	ifstream vertexFile(vertexPath);
	ifstream fragmentFile(vertexPath);
	stringstream vertexSStream;
	stringstream fragmentSStream;

	vertexFile.open(vertexPath);
	fragmentFile.open(fragmentPath);
	vertexFile.exceptions(ifstream::failbit || ifstream::badbit);
	fragmentFile.exceptions(ifstream::failbit || ifstream::badbit);
	try
	{
		if (!vertexFile.is_open()||!fragmentFile.is_open())
		{
			throw exception("open file error");
		}
		vertexSStream << vertexFile.rdbuf();
		fragmentSStream << fragmentFile.rdbuf();

		vertexString = vertexSStream.str();
		fragmentString = fragmentSStream.str();

		vertexSource = vertexString.c_str();
		fragmentSource = fragmentString.c_str();
		printf(vertexSource);

	}
	catch (const std::exception& ex)
	{
		printf(ex.what());
	}
	
}

//
//Shader::~Shader()		
//{
//}
