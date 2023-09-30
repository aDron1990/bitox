#include "bitox/graphics/ogl_render_system.hpp"
#include "bitox/engine/state.hpp"
#include "bitox/game/transform.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 transform;"
"void main()\n"
"{\n"
"   gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;"

"void main()"
"{"
"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
"}\0";

bitox::graphics::ogl_render_system::ogl_render_system()
	: system{ "ogl_renderer", {"transform"}}
{
	glfwMakeContextCurrent(get_window()->window_handle_.get());
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to init GLEW" << std::endl;
	}

	glm::ivec2 viewport_size{ 0 };
	glfwGetWindowSize(get_window()->window_handle_.get(), &viewport_size.x, &viewport_size.y);
	glViewport(0, 0, viewport_size.x, viewport_size.y);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	program = std::make_unique<shader>(vertexShaderSource, fragmentShaderSource);
}

void bitox::graphics::ogl_render_system::before_update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 0, 0, 1);
}

void bitox::graphics::ogl_render_system::on_component_update(ecs::component* component)
{
	program->use();
	auto transform = (game::transform*)get_ecs()->get_component(component->get_entity(), "transform");
	auto mat = glm::mat4{ 1.0f };

	mat = glm::translate(mat, transform->position);
	mat = glm::scale(mat, transform->scale);
	mat = glm::rotate(mat, transform->rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	mat = glm::rotate(mat, transform->rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	mat = glm::rotate(mat, transform->rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	program->set_matrix4("transform", mat);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
