#pragma once

#include <string>

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

	};
}