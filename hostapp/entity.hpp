#pragma once

#include "../ruby/utils.hpp"
#include "macros.hpp"
#include <string>

class Entity : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Entity">
{
	public:
	inline Entity(VALUE obj) : IObject(obj)
	{
	}
	inline Entity(const Entity& obj) : IObject(obj)
	{
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#add_observer-instance_method
	 *
	 * @param observer read https://ruby.sketchup.com/Sketchup/Entity.html#add_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entity.html#add_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, add_observer, (Sketchup::EntityObserver observer), add_observer, observer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#attribute_dictionaries-instance_method
	 *
	 * @return RubyUtils::optional<Sketchup::AttributeDictionaries> read
	 * https://ruby.sketchup.com/Sketchup/Entity.html#attribute_dictionaries-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::optional<Sketchup::AttributeDictionaries>, attribute_dictionaries, attribute_dictionaries)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#attribute_dictionary-instance_method
	 *
	 * @param name read https://ruby.sketchup.com/Sketchup/Entity.html#attribute_dictionary-instance_method
	 * @param create read https://ruby.sketchup.com/Sketchup/Entity.html#attribute_dictionary-instance_method
	 * @return RubyUtils::optional<Sketchup::AttributeDictionary> read https://ruby.sketchup.com/Sketchup/Entity.html#attribute_dictionary-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::AttributeDictionary>, attribute_dictionary, (std::string name, bool create = false), attribute_dictionary, name, create)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#delete_attribute-instance_method
	 *
	 * @param dictionary_name read https://ruby.sketchup.com/Sketchup/Entity.html#delete_attribute-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entity.html#delete_attribute-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(bool, delete_attribute, (std::string dictionary_name), delete_attribute, dictionary_name)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#delete_attribute-instance_method
	 *
	 * @param dictionary_name read https://ruby.sketchup.com/Sketchup/Entity.html#delete_attribute-instance_method
	 * @param key read https://ruby.sketchup.com/Sketchup/Entity.html#delete_attribute-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entity.html#delete_attribute-instance_method
	 * @min_version SketchUp 6.0Known Bugs:Prior to SketchUp 2019.0 the return values was always true.
	 */
	DEFINE_WRAPPED_METHOD(bool, delete_attribute, (std::string dictionary_name, std::string key), delete_attribute, dictionary_name, key)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#deleted%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entity.html#deleted%3F-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, is_deleted, deleted?)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#entityID-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Entity.html#entityID-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(long long, entityID, entityID)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#get_attribute-instance_method
	 *
	 * @param dict_name read https://ruby.sketchup.com/Sketchup/Entity.html#get_attribute-instance_method
	 * @param key read https://ruby.sketchup.com/Sketchup/Entity.html#get_attribute-instance_method
	 * @param default_value read https://ruby.sketchup.com/Sketchup/Entity.html#get_attribute-instance_method
	 * @return RubyUtils::details::IObject read https://ruby.sketchup.com/Sketchup/Entity.html#get_attribute-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, get_attribute, (std::string dict_name, std::string key, RubyUtils::details::IObject default_value), get_attribute, dict_name, key, default_value)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#inspect-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Entity.html#inspect-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, inspect, inspect)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#model-instance_method
	 *
	 * @return Sketchup::Model read https://ruby.sketchup.com/Sketchup/Entity.html#model-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Model, model, model)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#parent-instance_method
	 *
	 * @return RubyUtils::any_of<Sketchup::ComponentDefinition, Sketchup::Model> read https://ruby.sketchup.com/Sketchup/Entity.html#parent-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::any_of<Sketchup::ComponentDefinition DEFINE_WRAPPED_METHOD_COMMA Sketchup::Model>, parent, parent)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#persistent_id-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Entity.html#persistent_id-instance_method
	 * @min_version SketchUp 2017
	 */
	DEFINE_WRAPPED_METHOD_0(long long, persistent_id, persistent_id)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#remove_observer-instance_method
	 *
	 * @param observer read https://ruby.sketchup.com/Sketchup/Entity.html#remove_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entity.html#remove_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, remove_observer, (Sketchup::EntityObserver observer), remove_observer, observer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#set_attribute-instance_method
	 *
	 * @param dict_name read https://ruby.sketchup.com/Sketchup/Entity.html#set_attribute-instance_method
	 * @param key read https://ruby.sketchup.com/Sketchup/Entity.html#set_attribute-instance_method
	 * @param value read https://ruby.sketchup.com/Sketchup/Entity.html#set_attribute-instance_method TODO: (Boolean, Integer, Float, Length, nil, String,
	 * Time, Array, Geom::Point3d, Geom::Vector3d)
	 * @return RubyUtils::details::IObject read https://ruby.sketchup.com/Sketchup/Entity.html#set_attribute-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, set_attribute, (std::string dict_name, std::string key, RubyUtils::details::IObject value), set_attribute, dict_name, key, value)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#to_s-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Entity.html#to_s-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, to_s, to_s)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#typename-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Entity.html#typename-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, type_name, typename)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entity.html#valid%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entity.html#valid%3F-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD_0(bool, is_valid, valid?)
};
