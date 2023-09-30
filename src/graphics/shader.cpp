#include "bitox/graphics/shader.hpp"

#include <GL/glew.h>

#include <fstream>
#include <iostream>

bitox::graphics::shader::shader(const std::string& vertex_code, const std::string& fragment_code)
{
	program_id = compile_program_(vertex_code, fragment_code);
}

unsigned int bitox::graphics::shader::compile_program_(const std::string& vertex_code, const std::string& fragment_code)
{
	GLuint vertex, fragment, program;
	std::string info_log;
	info_log.resize(1024, '\0');
	int success;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	auto v = vertex_code.c_str();
	glShaderSource(vertex, 1, &v, nullptr);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, info_log.size(), nullptr, info_log.data());
		std::cerr << "Failed to compile vertex shader:\n" << info_log << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	auto f = fragment_code.c_str();
	glShaderSource(fragment, 1, &f, nullptr);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, info_log.size(), nullptr, info_log.data());
		std::cerr << "Failed to compile fragment shader:\n" << info_log << std::endl;
	}

	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, info_log.size(), nullptr, info_log.data());
		std::cerr << "Failed to link program shader:\n" << info_log << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

void bitox::graphics::shader::use()
{
	glUseProgram(program_id);
}