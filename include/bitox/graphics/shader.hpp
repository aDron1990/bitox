#pragma once

#include <string>
#include <glm/glm.hpp>

namespace bitox::graphics
{
	class shader
	{
	private:

		unsigned int program_id;

		unsigned int compile_program_(const std::string& vertex_code, const std::string& fragment_code);

	public:

		shader(const std::string& vertex_code, const std::string& fragment_code);

		void use();

		void set_matrix4(const std::string& name, const glm::mat4& matrix);

	};
}