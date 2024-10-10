namespace HostApp
{
	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* 
	* @param index read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @return RubyUtils::optional<Sketchup::Material> read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @min_version 
	*/
	IMPLEMENT_WRAPPED_METHOD_RESCUED(Sketchup::Materials, Sketchup::Material, operator[], (long long index), [], index)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* 
	* @param name read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @return RubyUtils::optional<Sketchup::Material> read https://ruby.sketchup.com/Sketchup/Materials.html#[]-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Materials, RubyUtils::optional<Sketchup::Material>, operator[], (std::string name), [], name)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#add-instance_method
	* 
	* @param name read https://ruby.sketchup.com/Sketchup/Materials.html#add-instance_method
	* @return Sketchup::Material read https://ruby.sketchup.com/Sketchup/Materials.html#add-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Materials, Sketchup::Material, add, (std::string name), add, name)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#add_observer-instance_method
	* 
	* @param observer read https://ruby.sketchup.com/Sketchup/Materials.html#add_observer-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#add_observer-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Materials, bool, add_observer, (Sketchup::MaterialsObserver observer), add_observer, observer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#count-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/Materials.html#count-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Materials, long long, count, count)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#current-instance_method
	* 
	* @return RubyUtils::optional<Sketchup::Materials> read https://ruby.sketchup.com/Sketchup/Materials.html#current-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Materials, RubyUtils::optional<Sketchup::Material>, current, current)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#current=-instance_method
	* 
	* @param material read https://ruby.sketchup.com/Sketchup/Materials.html#current=-instance_method
	* @return Sketchup::Material read https://ruby.sketchup.com/Sketchup/Materials.html#current=-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Materials, RubyUtils::optional<Sketchup::Material>, set_current, (RubyUtils::optional<Sketchup::Material> material), current=, material)
	
	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#each-instance_method
	* 
	* @return void read https://ruby.sketchup.com/Sketchup/Materials.html#each-instance_method
	* @min_version SketchUp 6.0
	*/
	inline Sketchup::Materials& Sketchup::Materials::each(std::function<void(Sketchup::Material)> lambda) {
		RubyUtils::Enumerable<Sketchup::Material>::each(lambda);
		return *this;
	}

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#length-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/Materials.html#length-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Materials, long long, length, length)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#load-instance_method
	* 
	* @param filename read https://ruby.sketchup.com/Sketchup/Materials.html#load-instance_method
	* @return Sketchup::Material read https://ruby.sketchup.com/Sketchup/Materials.html#load-instance_method
	* @min_version SketchUp 2017
	*/
	IMPLEMENT_WRAPPED_METHOD_RESCUED(Sketchup::Materials, Sketchup::Material, load, (std::string filename), load, filename)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#purge_unused-instance_method
	* 
	* @return Sketchup::Materials read https://ruby.sketchup.com/Sketchup/Materials.html#purge_unused-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Materials, Sketchup::Materials, purge_unused, purge_unused)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* 
	* @param material read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @min_version SketchUp 8.0 M1
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Materials, bool, remove, (Sketchup::Material material), remove, material)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* 
	* @param material read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#remove-instance_method
	* @min_version SketchUp 8.0 M1
	*/
	IMPLEMENT_WRAPPED_METHOD_RESCUED(Sketchup::Materials, bool, remove, (std::string material), remove, material)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#remove_observer-instance_method
	* 
	* @param observer read https://ruby.sketchup.com/Sketchup/Materials.html#remove_observer-instance_method
	* @return bool read https://ruby.sketchup.com/Sketchup/Materials.html#remove_observer-instance_method
	* @min_version SketchUp 6.0
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Materials, bool, remove_observer, (Sketchup::MaterialsObserver observer), remove_observer, observer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#size-instance_method
	* 
	* @return long long read https://ruby.sketchup.com/Sketchup/Materials.html#size-instance_method
	* @min_version SketchUp 2014
	*/
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Materials, long long, size, size)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Materials.html#unique_name-instance_method
	* 
	* @param name read https://ruby.sketchup.com/Sketchup/Materials.html#unique_name-instance_method
	* @return std::string read https://ruby.sketchup.com/Sketchup/Materials.html#unique_name-instance_method
	* @min_version 
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Materials, std::string, unique_name, (std::string name), unique_name, name)
};
