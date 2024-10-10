#pragma once

#include "./sketchup.hpp"

class DefinitionList : public TypeOf<Sketchup::Entity>, public RubyUtils::Enumerable<Sketchup::ComponentDefinition>, public RubyUtils::details::NamedRubyWrapper<"Sketchup::DefinitionList"> {
public:
	DefinitionList(VALUE obj) : RubyUtils::Enumerable<Sketchup::ComponentDefinition>(obj) {}  
	DefinitionList(const DefinitionList& obj) : RubyUtils::Enumerable<Sketchup::ComponentDefinition>(static_cast<const RubyUtils::Enumerable<Sketchup::ComponentDefinition>&>(obj)) {}

	inline operator Sketchup::Entity() { return value; }

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#[]-instance_method
	* 
	* @param index read https://ruby.sketchup.com/Sketchup/DefinitionList.html#[]-instance_method
	* @return RubyUtils::optional<Sketchup::ComponentDefinition> read https://ruby.sketchup.com/Sketchup/DefinitionList.html#[]-instance_method
	* @min_version 
	*/
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::ComponentDefinition>, operator[], (long long index), [], index)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#[]-instance_method
	* 
	* @param name_or_guid read https://ruby.sketchup.com/Sketchup/DefinitionList.html#[]-instance_method
	* @return RubyUtils::optional<Sketchup::ComponentDefinition> read https://ruby.sketchup.com/Sketchup/DefinitionList.html#[]-instance_method
	* @min_version 
	*/
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::ComponentDefinition>, operator[], (std::string name_or_guid), [], name_or_guid)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#add-instance_method
	* 
	* @param def_name read https://ruby.sketchup.com/Sketchup/DefinitionList.html#add-instance_method
	* @return Sketchup::ComponentDefinition read https://ruby.sketchup.com/Sketchup/DefinitionList.html#add-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::ComponentDefinition, add, (std::string def_name), add, def_name)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#add_observer-instance_method
	* 
	* @param observer read https://ruby.sketchup.com/Sketchup/DefinitionList.html#add_observer-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/DefinitionList.html#add_observer-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(bool, add_observer, (HostApp::Sketchup::DefinitionsObserver observer), add_observer, observer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#count-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/DefinitionList.html#count-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD_0(long long, count, count)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#each-instance_method
	* 
	* @return void read https://ruby.sketchup.com/Sketchup/DefinitionList.html#each-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::DefinitionList&, each, (std::function<void(Sketchup::ComponentDefinition)> lambda), each, lambda)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#import-instance_method
	* 
	* @param path read https://ruby.sketchup.com/Sketchup/DefinitionList.html#import-instance_method
	* @param options read https://ruby.sketchup.com/Sketchup/DefinitionList.html#import-instance_method
	* @return Sketchup::ComponentDefinition read https://ruby.sketchup.com/Sketchup/DefinitionList.html#import-instance_method
	* @min_version SketchUp 2021.1
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::ComponentDefinition, import, (std::string path, Hash options), import, path, options)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#length-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/DefinitionList.html#length-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD_0(long long, length, length)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#load-instance_method
	* 
	* @param path read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load-instance_method
	* @return Sketchup::ComponentDefinition read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load-instance_method
	* @min_version 
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::ComponentDefinition, load, (std::string path), load, path)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#load-instance_method
	* 
	* @param path read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load-instance_method
	* @param allow_newer: read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load-instance_method
	* @return Sketchup::ComponentDefinition read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load-instance_method
	* @min_version SketchUp 2021.0SketchUp 6.0Known Bugs:In SketchUp versions prior to SketchUp 2019 the application would crash if you tried to open a newer model instead of raising the expected RuntimeError.Prior to SketchUp 2023.0 this method silently failed to load a component if the model already contained a different component associated with the same path. Instead the existing component was returned. Making arbitrary changes to the existing component would allow the new one to be loaded.
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::ComponentDefinition, load, (std::string path,  bool allow_newer), load, path, allow_newer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#load_from_url-instance_method
	* 
	* @param url read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load_from_url-instance_method
	* @return Sketchup::ComponentDefinition read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load_from_url-instance_method
	* @min_version 
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::ComponentDefinition, load_from_url, (std::string url), load_from_url, url)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#load_from_url-instance_method
	* 
	* @param url read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load_from_url-instance_method
	* @param load_handler read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load_from_url-instance_method
	* @return Sketchup::ComponentDefinition read https://ruby.sketchup.com/Sketchup/DefinitionList.html#load_from_url-instance_method
	* @min_version SketchUp 7.0Known Bugs:Calling this method from an UI::HtmlDialog's action callback on macOS will cause the SketchUp application to become unresponsive or crash. To work around this, defer the call from the action callback with a non-repeating zero-delay timer; UI.start_timer(0, false) { method_calling_load_from_url }
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::ComponentDefinition, load_from_url, (std::string url, RubyUtils::details::IObject load_handler), load_from_url, url, load_handler)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#purge_unused-instance_method
	* 
	* @return Sketchup::DefinitionList read https://ruby.sketchup.com/Sketchup/DefinitionList.html#purge_unused-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD_0(Sketchup::DefinitionList, purge_unused, purge_unused)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#remove-instance_method
	* 
	* @param definition read https://ruby.sketchup.com/Sketchup/DefinitionList.html#remove-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/DefinitionList.html#remove-instance_method
	* @min_version SketchUp 2018Known Bugs:Prior to SketchUp 2023.0 this could crash SketchUp if you erased an definition used by the active edit path.
	*/
	DEFINE_WRAPPED_METHOD(bool, remove, (Sketchup::ComponentDefinition definition), remove, definition)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#remove_observer-instance_method
	* 
	* @param observer read https://ruby.sketchup.com/Sketchup/DefinitionList.html#remove_observer-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/DefinitionList.html#remove_observer-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(bool, remove_observer, (HostApp::Sketchup::DefinitionsObserver observer), remove_observer, observer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#size-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/DefinitionList.html#size-instance_method
	* @min_version SketchUp 2014
	*/
	DEFINE_WRAPPED_METHOD_0(long long, size, size)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/DefinitionList.html#unique_name-instance_method
	* 
	* @param base_name read https://ruby.sketchup.com/Sketchup/DefinitionList.html#unique_name-instance_method
	* @return std::string read https://ruby.sketchup.com/Sketchup/DefinitionList.html#unique_name-instance_method
	* @min_version 
	*/
	DEFINE_WRAPPED_METHOD(std::string, unique_name, (std::string base_name), unique_name, base_name)
};
