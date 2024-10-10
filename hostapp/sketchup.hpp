#pragma once

#include <optional>
#include <string>
#include <type_traits>
#include <vector>
#include <functional>
#include <stdarg.h>
#include <memory>
#include <stdexcept>

#include "../cpp/utils.hpp"
#include "../ruby/utils.hpp"

namespace HostApp
{
	using ind_t = unsigned int;

	#include "factory.hpp"
	#include "geom.hpp"

	class Sketchup : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup">
	{
		public:
		inline Sketchup();

		#include "dummy_objects.hpp"
		#include "implemented_objects.hpp"

		// https://ruby.sketchup.com/Sketchup.html#active_model-class_method
		inline std::optional<Sketchup::Model> active_model();

		// https://ruby.sketchup.com/Sketchup.html#version_number-class_method
		inline unsigned int version_number();

		// No Ruby equivalent
		inline unsigned int major_version();
	};

} // namespace HostApp

#include "sketchup.cc"
#include "material.cc"
#include "materials.cc"
#include "model.cc"
#include "entity.cc"
#include "definition_list.cc"
#include "entities.cc"
