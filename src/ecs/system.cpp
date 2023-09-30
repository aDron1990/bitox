#include "bitox/ecs/system.hpp"

bitox::ecs::system::system(const std::string& target_component_name, const std::initializer_list<std::string>& other_required_components_names)
	: target_component_name_{ target_component_name }, other_required_components_names_{ other_required_components_names } {}
