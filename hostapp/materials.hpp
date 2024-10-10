#pragma once

#include "../ruby/utils.hpp"
#include "macros.hpp"

class Materials : public RubyUtils::Enumerable<Sketchup::Material>, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Materials">
{
	public:
	inline Materials(VALUE arg) : RubyUtils::Enumerable<Sketchup::Material>(arg)
	{
	}
	inline Materials(const RubyUtils::details::IObject& arg) : RubyUtils::Enumerable<Sketchup::Material>(arg.to_ruby())
	{
	}
	inline Materials(const RubyUtils::Enumerable<Sketchup::Material>& arg) : RubyUtils::Enumerable<Sketchup::Material>(arg)
	{
	}

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* 
	* @param index read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @return RubyUtils::optional<Sketchup::Material> read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @min_version 
	*/
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::Material>, operator[], (long long index), [], index)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* 
	* @param name read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @return RubyUtils::optional<Sketchup::Material> read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::Material>, operator[], (std::string name), [], name)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#add-instance_method
	* 
	* @param name read https://ruby.sketchup.com/Sketchup/Materials.html#add-instance_method
	* @return Sketchup::Material read https://ruby.sketchup.com/Sketchup/Materials.html#add-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::Material, add, (std::string name), add, name)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#add_observer-instance_method
	* 
	* @param observer read https://ruby.sketchup.com/Sketchup/Materials.html#add_observer-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#add_observer-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(bool, add_observer, (Sketchup::MaterialsObserver observer), add_observer, observer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#count-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/Materials.html#count-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD_0(long long, count, count)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#current-instance_method
	* 
	* @return RubyUtils::optional<Sketchup::Materials> read https://ruby.sketchup.com/Sketchup/Materials.html#current-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD_0(RubyUtils::optional<Sketchup::Material>, current, current)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#current=-instance_method
	* 
	* @param material read https://ruby.sketchup.com/Sketchup/Materials.html#current=-instance_method
	* @return Sketchup::Material read https://ruby.sketchup.com/Sketchup/Materials.html#current=-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::Material>, set_current, (RubyUtils::optional<Sketchup::Material> material), current=, material)
	
	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#each-instance_method
	* 
	* @return void read https://ruby.sketchup.com/Sketchup/Materials.html#each-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(Sketchup::Materials&, each, (std::function<void(Sketchup::Material)> lambda), each, lambda)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#length-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/Materials.html#length-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD_0(long long, length, length)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#load-instance_method
	* 
	* @param filename read https://ruby.sketchup.com/Sketchup/Materials.html#load-instance_method
	* @return Sketchup::Material read https://ruby.sketchup.com/Sketchup/Materials.html#load-instance_method
	* @min_version SketchUp 2017
	*/
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<Sketchup::Material>, load, (std::string filename), load, filename)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#purge_unused-instance_method
	* 
	* @return Sketchup::Materials read https://ruby.sketchup.com/Sketchup/Materials.html#purge_unused-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD_0(Sketchup::Materials, purge_unused, purge_unused)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* 
	* @param material read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @min_version SketchUp 8.0 M1
	*/
	DEFINE_WRAPPED_METHOD(bool, remove, (Sketchup::Material material), remove, material)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* 
	* @param material read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @min_version SketchUp 8.0 M1
	*/
	DEFINE_WRAPPED_METHOD(RubyUtils::optional<bool>, remove, (std::string material), remove, material)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#remove_observer-instance_method
	* 
	* @param observer read https://ruby.sketchup.com/Sketchup/Materials.html#remove_observer-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#remove_observer-instance_method
	* @min_version SketchUp 6.0
	*/
	DEFINE_WRAPPED_METHOD(bool, remove_observer, (Sketchup::MaterialsObserver observer), remove_observer, observer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#size-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/Materials.html#size-instance_method
	* @min_version SketchUp 2014
	*/
	DEFINE_WRAPPED_METHOD_0(long long, size, size)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#unique_name-instance_method
	* 
	* @param name read https://ruby.sketchup.com/Sketchup/Materials.html#unique_name-instance_method
	* @return std::string read https://ruby.sketchup.com/Sketchup/Materials.html#unique_name-instance_method
	* @min_version 
	*/
	DEFINE_WRAPPED_METHOD(std::string, unique_name, (std::string name), unique_name, name)


};
