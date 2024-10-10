#pragma once

#include "../ruby/utils.hpp"
#include "macros.hpp"

class Model : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Model">
{
	public:
	class ImportOptions : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ImportOptions">
	{
		public:
		inline ImportOptions(VALUE obj) : IObject(obj)
		{
		}
		inline ImportOptions(const IObject& obj) : IObject(obj)
		{
		}
	};

	class FindEntityByPersistentIdScope : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::FindEntityByPersistentIdScope">
	{
		public:
		inline FindEntityByPersistentIdScope(VALUE obj) : IObject(obj)
		{
		}
		inline FindEntityByPersistentIdScope(const IObject& obj) : IObject(obj)
		{
		}
	};

	enum _VERSION : int
	{
		VERSION_3 = 3,
		VERSION_4,
		VERSION_5,
		VERSION_6,
		VERSION_7,
		VERSION_8,
		VERSION_2013,
		VERSION_2014,
		VERSION_2015,
		VERSION_2016,
		VERSION_2017,
		VERSION_2018,
		VERSION_2019,
		VERSION_2020,
		VERSION_2021
	};

	inline Model(VALUE arg) : IObject(arg)
	{
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#abort_operation-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#abort_operation-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, abort_operation, abort_operation)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#active_entities-instance_method
	 *
	 * @return Sketchup::Entities read https://ruby.sketchup.com/Sketchup/Model.html#active_entities-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Entities, active_entities, active_entities)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#active_layer-instance_method
	 *
	 * @return Sketchup::Layer read https://ruby.sketchup.com/Sketchup/Model.html#active_layer-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Layer, active_layer, active_layer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#active_layer=-instance_method
	 *
	 * @param layer read https://ruby.sketchup.com/Sketchup/Model.html#active_layer=-instance_method
	 * @return Sketchup::Layer read https://ruby.sketchup.com/Sketchup/Model.html#active_layer=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::Layer, set_active_layer, (Sketchup::Layer layer), active_layer =, layer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#active_path-instance_method
	 *
	 * @return RubyUtils::optional<RubyUtils::Enumerable<Sketchup::Drawingelement>> read
	 * https://ruby.sketchup.com/Sketchup/Model.html#active_path-instance_method
	 * @min_version SketchUp 7.0
	 */
	inline RubyUtils::Enumerable<Sketchup::Drawingelement> active_path();

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#active_path=-instance_method
	 *
	 * @param instance_path read https://ruby.sketchup.com/Sketchup/Model.html#active_path=-instance_method
	 * @return Sketchup::Model read https://ruby.sketchup.com/Sketchup/Model.html#active_path=-instance_method
	 * @min_version SketchUp 2020.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::Model, set_active_path, (Sketchup::InstancePath instance_path), active_path =, instance_path)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#active_view-instance_method
	 *
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/Model.html#active_view-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::View, active_view, active_view)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#add_note-instance_method
	 *
	 * @param note read https://ruby.sketchup.com/Sketchup/Model.html#add_note-instance_method
	 * @param x read https://ruby.sketchup.com/Sketchup/Model.html#add_note-instance_method
	 * @param y read https://ruby.sketchup.com/Sketchup/Model.html#add_note-instance_method
	 * @return Sketchup::Text read https://ruby.sketchup.com/Sketchup/Model.html#add_note-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::Text, add_note, (std::string note, double x, double y), add_note, note, x, y)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#add_observer-instance_method
	 *
	 * @param observer read https://ruby.sketchup.com/Sketchup/Model.html#add_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#add_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, add_observer, (Sketchup::ModelObserver observer), add_observer, observer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#attribute_dictionaries-instance_method
	 *
	 * @return Sketchup::AttributeDictionaries read https://ruby.sketchup.com/Sketchup/Model.html#attribute_dictionaries-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::AttributeDictionaries, attribute_dictionaries, attribute_dictionaries)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#attribute_dictionary-instance_method
	 *
	 * @param name read https://ruby.sketchup.com/Sketchup/Model.html#attribute_dictionary-instance_method
	 * @param create read https://ruby.sketchup.com/Sketchup/Model.html#attribute_dictionary-instance_method
	 * @return RubyUtils::optional<Sketchup::AttributeDictionary> read https://ruby.sketchup.com/Sketchup/Model.html#attribute_dictionary-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::AttributeDictionary>, attribute_dictionary, (std::string name, bool create = false), attribute_dictionary, name, create)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#axes-instance_method
	 *
	 * @return Sketchup::Axes read https://ruby.sketchup.com/Sketchup/Model.html#axes-instance_method
	 * @min_version SketchUp 2016
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Axes, axes, axes)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#behavior-instance_method
	 *
	 * @return Sketchup::Behavior read https://ruby.sketchup.com/Sketchup/Model.html#behavior-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Behavior, behavior, behavior)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#bounds-instance_method
	 *
	 * @return Geom::BoundingBox read https://ruby.sketchup.com/Sketchup/Model.html#bounds-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Geom::BoundingBox, bounds, bounds)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#classifications-instance_method
	 *
	 * @return Sketchup::Classifications read https://ruby.sketchup.com/Sketchup/Model.html#classifications-instance_method
	 * @min_version SketchUp 2015
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Classifications, classifications, classifications)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#close-instance_method
	 *
	 * @param ignore_changes read https://ruby.sketchup.com/Sketchup/Model.html#close-instance_method
	 * @return void read https://ruby.sketchup.com/Sketchup/Model.html#close-instance_method
	 * @min_version SketchUp 2015
	 */
	DEFINE_WRAPPED_METHOD(void, close, (bool ignore_changes), close, ignore_changes)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#close_active-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#close_active-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, close_active, close_active)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#commit_operation-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#commit_operation-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, commit_operation, commit_operation)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#definitions-instance_method
	 *
	 * @return Sketchup::DefinitionList read https://ruby.sketchup.com/Sketchup/Model.html#definitions-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::DefinitionList, definitions, definitions)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#description-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#description-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, description, description)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#description=-instance_method
	 *
	 * @param description read https://ruby.sketchup.com/Sketchup/Model.html#description=-instance_method
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#description=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(std::string, set_description, (std::string description), description =, description)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#drawing_element_visible%3F-instance_method
	 *
	 * @param instance_path read https://ruby.sketchup.com/Sketchup/Model.html#drawing_element_visible%3F-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#drawing_element_visible%3F-instance_method
	 * @min_version SketchUp 2020.0
	 */
	DEFINE_WRAPPED_METHOD(bool, is_drawing_element_visible, (Sketchup::InstancePath instance_path), drawing_element_visible?, instance_path)
	DEFINE_WRAPPED_METHOD(bool, is_drawing_element_visible, (RubyUtils::Enumerable<Sketchup::Drawingelement> instance_path), drawing_element_visible?, instance_path)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#edit_transform-instance_method
	 *
	 * @return Geom::Transformation read https://ruby.sketchup.com/Sketchup/Model.html#edit_transform-instance_method
	 * @min_version SketchUp 7.0
	 */
	DEFINE_WRAPPED_METHOD_0(Geom::Transformation, edit_transform, edit_transform)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#entities-instance_method
	 *
	 * @return Sketchup::Entities read https://ruby.sketchup.com/Sketchup/Model.html#entities-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Entities, entities, entities)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 * @param options read https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, export_, (std::string path, Sketchup::ExportOptions options), export, path, options)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 * @param show_summary read https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#export-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(bool, export_, (std::string path, bool show_summary), export, path, show_summary)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_id-instance_method
	 *
	 * @param ids_or_array read https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_id-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Entity, nil> read https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_id-instance_method
	 * @min_version SketchUp 2015
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::Enumerable<RubyUtils::optional<Sketchup::Entity>>, find_entity_by_id, (RubyUtils::Enumerable<long long> ids_or_array), find_entity_by_id, ids_or_array)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_persistent_id-instance_method
	 *
	 * @param ids_or_array read https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_persistent_id-instance_method
	 * @return RubyUtils::optional<Sketchup::Entity> read https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_persistent_id-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::Entity>, find_entity_by_persistent_id, (long long ids_or_array), find_entity_by_persistent_id, ids_or_array)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_persistent_id-instance_method
	 *
	 * @param ids_or_array read https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_persistent_id-instance_method
	 * @param **scope read https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_persistent_id-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Entity, nil> read https://ruby.sketchup.com/Sketchup/Model.html#find_entity_by_persistent_id-instance_method
	 * @min_version SketchUp 2020.2SketchUp 2017
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::Enumerable<RubyUtils::optional<Sketchup::Entity>>, find_entity_by_persistent_id, (RubyUtils::Enumerable<long long> ids_or_array, FindEntityByPersistentIdScope scope), find_entity_by_persistent_id, ids_or_array, scope)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#georeferenced%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#georeferenced%3F-instance_method
	 * @min_version SketchUp 7.1
	 */
	DEFINE_WRAPPED_METHOD_0(bool, is_georeferenced, georeferenced?)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#get_attribute-instance_method
	 *
	 * @param dictname read https://ruby.sketchup.com/Sketchup/Model.html#get_attribute-instance_method
	 * @param key read https://ruby.sketchup.com/Sketchup/Model.html#get_attribute-instance_method
	 * @param defaultvalue read https://ruby.sketchup.com/Sketchup/Model.html#get_attribute-instance_method
	 * @return RubyUtils::optional<RubyUtils::details::IObject> read https://ruby.sketchup.com/Sketchup/Model.html#get_attribute-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<RubyUtils::details::IObject>, get_attribute, (std::string dictname, std::string key, RubyUtils::details::IObject defaultvalue), get_attribute, dictname, key, defaultvalue)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#get_datum-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#get_datum-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, get_datum, get_datum)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#get_product_family-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Model.html#get_product_family-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(long long, get_product_family, get_product_family)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#guid-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#guid-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, guid, guid)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 * @param options read https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(bool, import_, (std::string path, ImportOptions options), import, path, options)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 * @param show_summary read https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#import-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, import_, (std::string path, bool show_summary), import, path, show_summary)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#instance_path_from_pid_path-instance_method
	 *
	 * @param pid_path read https://ruby.sketchup.com/Sketchup/Model.html#instance_path_from_pid_path-instance_method
	 * @return Sketchup::InstancePath read https://ruby.sketchup.com/Sketchup/Model.html#instance_path_from_pid_path-instance_method
	 * @min_version SketchUp 2017
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::InstancePath, instance_path_from_pid_path, (std::string pid_path), instance_path_from_pid_path, pid_path)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#latlong_to_point-instance_method
	 *
	 * @param lnglat_array read https://ruby.sketchup.com/Sketchup/Model.html#latlong_to_point-instance_method
	 * @return Geom::Point3d read https://ruby.sketchup.com/Sketchup/Model.html#latlong_to_point-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Geom::Point3d, latlong_to_point, (RubyUtils::Enumerable<RubyUtils::tuple<double DEFINE_WRAPPED_METHOD_COMMA double>> lnglat_array), latlong_to_point, lnglat_array)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#layers-instance_method
	 *
	 * @return Sketchup::Layers read https://ruby.sketchup.com/Sketchup/Model.html#layers-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Layers, layers, layers)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#line_styles-instance_method
	 *
	 * @return Sketchup::LineStyles read https://ruby.sketchup.com/Sketchup/Model.html#line_styles-instance_method
	 * @min_version SketchUp 2019
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::LineStyles, line_styles, line_styles)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#list_datums-instance_method
	 *
	 * @return RubyUtils::Enumerable<std::string> read https://ruby.sketchup.com/Sketchup/Model.html#list_datums-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::Enumerable<std::string>, list_datums, list_datums)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#materials-instance_method
	 *
	 * @return Sketchup::Materials read https://ruby.sketchup.com/Sketchup/Model.html#materials-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Materials, materials, materials)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#mipmapping=-instance_method
	 *
	 * @param mipmap read https://ruby.sketchup.com/Sketchup/Model.html#mipmapping=-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#mipmapping=-instance_method
	 * @min_version SketchUp 7.0
	 */
	DEFINE_WRAPPED_METHOD(bool, set_mipmapping, (bool mipmap), mipmapping =, mipmap)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#mipmapping%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#mipmapping%3F-instance_method
	 * @min_version SketchUp 7.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, is_mipmapping, mipmapping?)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#modified%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#modified%3F-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, is_modified, modified?)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#name-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#name-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, name, name)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#name=-instance_method
	 *
	 * @param name read https://ruby.sketchup.com/Sketchup/Model.html#name=-instance_method
	 * @return RubyUtils::details::IObject read https://ruby.sketchup.com/Sketchup/Model.html#name=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, set_name, (std::string name), name =, name)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#number_faces-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Model.html#number_faces-instance_method
	 * @min_version SketchUp 7.1
	 */
	DEFINE_WRAPPED_METHOD_0(long long, number_faces, number_faces)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#options-instance_method
	 *
	 * @return Sketchup::OptionsManager read https://ruby.sketchup.com/Sketchup/Model.html#options-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::OptionsManager, options, options)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#overlays-instance_method
	 *
	 * @return Sketchup::OverlaysManager read https://ruby.sketchup.com/Sketchup/Model.html#overlays-instance_method
	 * @min_version SketchUp 2023.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::OverlaysManager, overlays, overlays)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#pages-instance_method
	 *
	 * @return Sketchup::Pages read https://ruby.sketchup.com/Sketchup/Model.html#pages-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Pages, pages, pages)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#path-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#path-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, path, path)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#place_component-instance_method
	 *
	 * @param componentdef read https://ruby.sketchup.com/Sketchup/Model.html#place_component-instance_method
	 * @param repeat read https://ruby.sketchup.com/Sketchup/Model.html#place_component-instance_method
	 * @return RubyUtils::optional<Sketchup::Model> read https://ruby.sketchup.com/Sketchup/Model.html#place_component-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::Model>, place_component, (Sketchup::ComponentDefinition componentdef, bool repeat = false), place_component, componentdef, repeat)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#point_to_latlong-instance_method
	 *
	 * @param point read https://ruby.sketchup.com/Sketchup/Model.html#point_to_latlong-instance_method
	 * @return Geom::Point3d, Geom::LatLong read https://ruby.sketchup.com/Sketchup/Model.html#point_to_latlong-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, point_to_latlong, (Geom::Point3d point), point_to_latlong, point)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#point_to_utm-instance_method
	 *
	 * @param point read https://ruby.sketchup.com/Sketchup/Model.html#point_to_utm-instance_method
	 * @return Geom::UTM read https://ruby.sketchup.com/Sketchup/Model.html#point_to_utm-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Geom::UTM, point_to_utm, (Geom::Point3d point), point_to_utm, point)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#raytest-instance_method
	 *
	 * @param ray read https://ruby.sketchup.com/Sketchup/Model.html#raytest-instance_method
	 * @param wysiwyg_flag read https://ruby.sketchup.com/Sketchup/Model.html#raytest-instance_method
	 * @return RubyUtils::optional<RubyUtils::Enumerable<RubyUtils::tuple<Geom::Point3d, Geom::Vector3d>>> read
	 * https://ruby.sketchup.com/Sketchup/Model.html#raytest-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<RubyUtils::Enumerable<RubyUtils::tuple<Geom::Point3d DEFINE_WRAPPED_METHOD_COMMA Geom::Vector3d>>>, raytest, (RubyUtils::Enumerable<RubyUtils::tuple<Geom::Point3d, Geom::Vector3d>> ray, bool wysiwyg_flag), raytest, ray, wysiwyg_flag)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#remove_observer-instance_method
	 *
	 * @param observer read https://ruby.sketchup.com/Sketchup/Model.html#remove_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#remove_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, remove_observer, (Sketchup::ModelObserver observer), remove_observer, observer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#rendering_options-instance_method
	 *
	 * @return Sketchup::RenderingOptions read https://ruby.sketchup.com/Sketchup/Model.html#rendering_options-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::RenderingOptions, rendering_options, rendering_options)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 * @min_version SketchUp 2014
	 */
	DEFINE_WRAPPED_METHOD_0(bool, save, save)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, save, (std::string path), save, path)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 * @param version read https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#save-instance_method
	 * @min_version SketchUp 2014
	 */
	DEFINE_WRAPPED_METHOD(bool, save, (std::string path, _VERSION version), save, path, (int)version)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#save_copy-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Model.html#save_copy-instance_method
	 * @param version read https://ruby.sketchup.com/Sketchup/Model.html#save_copy-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#save_copy-instance_method
	 * @min_version SketchUp 2014
	 */
	DEFINE_WRAPPED_METHOD(bool, save_copy, (std::string path, _VERSION version), save_copy, path, (int)version)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#save_thumbnail-instance_method
	 *
	 * @param filename read https://ruby.sketchup.com/Sketchup/Model.html#save_thumbnail-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#save_thumbnail-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, save_thumbnail, (std::string filename), save_thumbnail, filename)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#select_tool-instance_method
	 *
	 * @param tool read https://ruby.sketchup.com/Sketchup/Model.html#select_tool-instance_method
	 * @return Sketchup::Model read https://ruby.sketchup.com/Sketchup/Model.html#select_tool-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::Model, select_tool, (RubyUtils::details::IObject tool), select_tool, tool)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#selection-instance_method
	 *
	 * @return Sketchup::Selection read https://ruby.sketchup.com/Sketchup/Model.html#selection-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Selection, selection, selection)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#set_attribute-instance_method
	 *
	 * @param attrdictname read https://ruby.sketchup.com/Sketchup/Model.html#set_attribute-instance_method
	 * @param key read https://ruby.sketchup.com/Sketchup/Model.html#set_attribute-instance_method
	 * @param value read https://ruby.sketchup.com/Sketchup/Model.html#set_attribute-instance_method
	 * @return RubyUtils::details::IObject read https://ruby.sketchup.com/Sketchup/Model.html#set_attribute-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, set_attribute, (std::string attrdictname, std::string key, RubyUtils::details::IObject value), set_attribute, attrdictname, key, value)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#set_datum-instance_method
	 *
	 * @param datum read https://ruby.sketchup.com/Sketchup/Model.html#set_datum-instance_method
	 * @return void read https://ruby.sketchup.com/Sketchup/Model.html#set_datum-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(void, set_datum, (std::string datum), set_datum, datum)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#shadow_info-instance_method
	 *
	 * @return Sketchup::ShadowInfo read https://ruby.sketchup.com/Sketchup/Model.html#shadow_info-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::ShadowInfo, shadow_info, shadow_info)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#start_operation-instance_method
	 *
	 * @param op_name read https://ruby.sketchup.com/Sketchup/Model.html#start_operation-instance_method
	 * @param disable_ui read https://ruby.sketchup.com/Sketchup/Model.html#start_operation-instance_method
	 * @param next_transparent read https://ruby.sketchup.com/Sketchup/Model.html#start_operation-instance_method
	 * @param transparent read https://ruby.sketchup.com/Sketchup/Model.html#start_operation-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#start_operation-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, start_operation, (std::string op_name, bool disable_ui = false, bool next_transparent = false, bool transparent = false), start_operation, op_name, disable_ui, next_transparent, transparent, transparent)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#styles-instance_method
	 *
	 * @return Sketchup::Styles read https://ruby.sketchup.com/Sketchup/Model.html#styles-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Styles, styles, styles)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#tags-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#tags-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, tags, tags)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#tags=-instance_method
	 *
	 * @param tags read https://ruby.sketchup.com/Sketchup/Model.html#tags=-instance_method
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#tags=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(std::string, set_tags, (std::string tags), tags =, tags)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#title-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Model.html#title-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(std::string, title, title)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#tools-instance_method
	 *
	 * @return Sketchup::Tools read https://ruby.sketchup.com/Sketchup/Model.html#tools-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Tools, tools, tools)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#utm_to_point-instance_method
	 *
	 * @param utm read https://ruby.sketchup.com/Sketchup/Model.html#utm_to_point-instance_method
	 * @return Geom::Point3d read https://ruby.sketchup.com/Sketchup/Model.html#utm_to_point-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Geom::Point3d, utm_to_point, (Geom::UTM utm), utm_to_point, utm)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Model.html#valid%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Model.html#valid%3F-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, is_valid, valid?)
};
