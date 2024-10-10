#pragma once

#include "../ruby/utils.hpp"
#include "macros.hpp"
#include <string>
#include <compare>

class Material : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Material">
{
	public:
	enum ColorizeTypes
	{
		COLORIZE_SHIFT,
		COLORIZE_TINT
	};

	enum MaterialTypes
	{
		MATERIAL_SOLID = 0, // solid
		MATERIAL_TEXTURED = 1, // textured
		MATERIAL_COLORIZED_TEXTURED = 2 // colorized textured
	};

	enum OwnerTypes
	{
		OWNER_MANAGER,
		OWNER_IMAGE,
		OWNER_LAYER
	};

	inline Material(VALUE arg) : IObject(arg)
	{
	}

	inline Material(IObject arg) : IObject(arg)
	{
	}

	inline Material(RubyUtils::Object arg) : IObject(arg.to_ruby())
	{
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#<=>-instance_method
	 *
	 * @param material2 read https://ruby.sketchup.com/Sketchup/Material.html#<=>-instance_method
	 * @return long long read https://ruby.sketchup.com/Sketchup/Material.html#<=>-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(std::strong_ordering, operator <=>, (Sketchup::Material material2), <=>, material2)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#==-instance_method
	 *
	 * @param material2 read https://ruby.sketchup.com/Sketchup/Material.html#==-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#==-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, operator ==, (Sketchup::Material material2), ==, material2)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#alpha-instance_method
	 *
	 * @return double read https://ruby.sketchup.com/Sketchup/Material.html#alpha-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(double, alpha, alpha)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#alpha=-instance_method
	 *
	 * @param alpha read https://ruby.sketchup.com/Sketchup/Material.html#alpha=-instance_method
	 * @return double read https://ruby.sketchup.com/Sketchup/Material.html#alpha=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(double, set_alpha, (double alpha), alpha=, alpha)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#color-instance_method
	 *
	 * @return Sketchup::Color read https://ruby.sketchup.com/Sketchup/Material.html#color-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Color, color, color)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 *
	 * @param color read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @return RubyUtils::optional<Sketchup::Color> read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::Color>, set_color, (RubyUtils::optional<Sketchup::Color> color), color=, color)
	
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 *
	 * @param color read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @return RubyUtils::optional<std::string> read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<std::string>, set_color, (RubyUtils::optional<std::string> color), color=, color)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#colorize_deltas-instance_method
	 *
	 * @return RubyUtils::Enumerable<RubyUtils::tuple<float, float, float>> read
	 * https://ruby.sketchup.com/Sketchup/Material.html#colorize_deltas-instance_method
	 * @min_version SketchUp 2015
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::Enumerable<RubyUtils::tuple<float DEFINE_WRAPPED_METHOD_COMMA float DEFINE_WRAPPED_METHOD_COMMA float>>, colorize_deltas, colorize_deltas)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#colorize_type-instance_method
	 *
	 * @return ColorizeTypes read https://ruby.sketchup.com/Sketchup/Material.html#colorize_type-instance_method
	 * @min_version SketchUp 2015
	 */
	DEFINE_WRAPPED_METHOD_0(ColorizeTypes, colorize_type, colorize_type)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#colorize_type=-instance_method
	 *
	 * @param type read https://ruby.sketchup.com/Sketchup/Material.html#colorize_type=-instance_method
	 * @return ColorizeTypes read https://ruby.sketchup.com/Sketchup/Material.html#colorize_type=-instance_method
	 * @min_version SketchUp 2015
	 */
	DEFINE_WRAPPED_METHOD(ColorizeTypes, set_colorize_type, (ColorizeTypes type), colorize_type=, type)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#display_name-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Material.html#display_name-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, display_name, display_name)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#materialType-instance_method
	 *
	 * @return MaterialTypes read https://ruby.sketchup.com/Sketchup/Material.html#materialType-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(MaterialTypes, materialType, materialType)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#name-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Material.html#name-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, name, name)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#name=-instance_method
	 *
	 * @param str read https://ruby.sketchup.com/Sketchup/Material.html#name=-instance_method
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Material.html#name=-instance_method
	 * @min_version SketchUp 8.0 M1
	 */
	DEFINE_WRAPPED_METHOD(std::string, set_name, (std::string str), name=, str)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#owner_type-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Material.html#owner_type-instance_method
	 * @min_version SketchUp 2019.2
	 */
	DEFINE_WRAPPED_METHOD_0(OwnerTypes, owner_type, owner_type)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#save_as-instance_method
	 *
	 * @param filename read https://ruby.sketchup.com/Sketchup/Material.html#save_as-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#save_as-instance_method
	 * @min_version SketchUp 2017
	 */
	DEFINE_WRAPPED_METHOD(bool, save_as, (std::string filename), save_as, filename)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture-instance_method
	 *
	 * @return RubyUtils::optional<Sketchup::Texture> read https://ruby.sketchup.com/Sketchup/Material.html#texture-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::optional<Sketchup::Texture>, texture, texture)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 *
	 * @param filename read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @return RubyUtils::Object read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::Object, set_texture, (std::string filename), texture=, filename)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 *
	 * @param image_rep read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @return RubyUtils::Object read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::Object, set_texture, (Sketchup::ImageRep image_rep), texture=, image_rep)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 *
	 * @param properties read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @return RubyUtils::Object read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::Object, set_texture, (RubyUtils::Enumerable<RubyUtils::tuple<std::string, Sketchup::Length, Sketchup::Length>> properties), texture=, properties)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#use_alpha%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#use_alpha%3F-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, does_use_alpha, use_alpha?)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 * @param resolution read https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 * @min_version SketchUp 8.0 M1
	 */
	DEFINE_WRAPPED_METHOD(bool, write_thumbnail, (std::string path, long long resolution), write_thumbnail, path, resolution)
};
