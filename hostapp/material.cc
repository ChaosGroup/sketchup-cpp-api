namespace HostApp
{
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#<=>-instance_method
	 *
	 * @param material2 read https://ruby.sketchup.com/Sketchup/Material.html#<=>-instance_method
	 * @return long long read https://ruby.sketchup.com/Sketchup/Material.html#<=>-instance_method
	 * @min_version SketchUp 6.0
	 */
	inline std::strong_ordering Sketchup::Material::operator<=>(Sketchup::Material material2)
	{
		const long long result = this->_send<long long>("<=>", material2);
		if (result == 0)
		{
			return std::strong_ordering::equal;
		}
		else if (result < 0)
		{
			return std::strong_ordering::less;
		}
		else
		{
			return std::strong_ordering::greater;
		}
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#==-instance_method
	 *
	 * @param material2 read https://ruby.sketchup.com/Sketchup/Material.html#==-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#==-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, bool, operator ==, (Sketchup::Material material2), ==, material2)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#alpha-instance_method
	 *
	 * @return double read https://ruby.sketchup.com/Sketchup/Material.html#alpha-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Material, double, alpha, alpha)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#alpha=-instance_method
	 *
	 * @param alpha read https://ruby.sketchup.com/Sketchup/Material.html#alpha=-instance_method
	 * @return double read https://ruby.sketchup.com/Sketchup/Material.html#alpha=-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, double, set_alpha, (double alpha), alpha=, alpha)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#color-instance_method
	 *
	 * @return Sketchup::Color read https://ruby.sketchup.com/Sketchup/Material.html#color-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Material, Sketchup::Color, color, color)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 *
	 * @param color read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @return RubyUtils::optional<Sketchup::Color> read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, RubyUtils::optional<Sketchup::Color>, set_color, (RubyUtils::optional<Sketchup::Color> color), color=, color)
	
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 *
	 * @param color read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @return RubyUtils::optional<std::string> read https://ruby.sketchup.com/Sketchup/Material.html#color=-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_RESCUED(Sketchup::Material, std::string, set_color, (RubyUtils::optional<std::string> color), color=, color)
	
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#colorize_deltas-instance_method
	 *
	 * @return RubyUtils::Enumerable<RubyUtils::tuple<float, float, float>> read
	 * https://ruby.sketchup.com/Sketchup/Material.html#colorize_deltas-instance_method
	 * @min_version SketchUp 2015
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Material, RubyUtils::Enumerable<RubyUtils::tuple<float DEFINE_WRAPPED_METHOD_COMMA float DEFINE_WRAPPED_METHOD_COMMA float>>, colorize_deltas, colorize_deltas)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#colorize_type-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Material.html#colorize_type-instance_method
	 * @min_version SketchUp 2015
	 */
	inline Sketchup::Material::ColorizeTypes Sketchup::Material::colorize_type() 
	{
		return (Sketchup::Material::ColorizeTypes)this->_send<long long>("colorize_type"); 
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#colorize_type=-instance_method
	 *
	 * @param type read https://ruby.sketchup.com/Sketchup/Material.html#colorize_type=-instance_method
	 * @return long long read https://ruby.sketchup.com/Sketchup/Material.html#colorize_type=-instance_method
	 * @min_version SketchUp 2015
	 */
	inline Sketchup::Material::ColorizeTypes Sketchup::Material::set_colorize_type (Sketchup::Material::ColorizeTypes type)
	{
		return (Sketchup::Material::ColorizeTypes)this->_send<long long>("colorize_type=", (int)type); 
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#display_name-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Material.html#display_name-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Material, std::string, display_name, display_name)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#materialType-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Material.html#materialType-instance_method
	 * @min_version SketchUp 6.0
	 */
	inline Sketchup::Material::MaterialTypes Sketchup::Material::materialType()
	{
		return (Sketchup::Material::MaterialTypes)this->_send<long long>("materialType");
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#name-instance_method
	 *
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Material.html#name-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Material, std::string, name, name)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#name=-instance_method
	 *
	 * @param str read https://ruby.sketchup.com/Sketchup/Material.html#name=-instance_method
	 * @return std::string read https://ruby.sketchup.com/Sketchup/Material.html#name=-instance_method
	 * @min_version SketchUp 8.0 M1
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, std::string, set_name, (std::string str), name=, str)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#owner_type-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Material.html#owner_type-instance_method
	 * @min_version SketchUp 2019.2
	 */
	inline Sketchup::Material::OwnerTypes Sketchup::Material::owner_type()
	{ 
		return (Sketchup::Material::OwnerTypes)this->_send<long long>("owner_type");
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#save_as-instance_method
	 *
	 * @param filename read https://ruby.sketchup.com/Sketchup/Material.html#save_as-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#save_as-instance_method
	 * @min_version SketchUp 2017
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, bool, save_as, (std::string filename), save_as, filename)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture-instance_method
	 *
	 * @return RubyUtils::optional<Sketchup::Texture> read https://ruby.sketchup.com/Sketchup/Material.html#texture-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Material, RubyUtils::optional<Sketchup::Texture>, texture, texture)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 *
	 * @param filename read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @return RubyUtils::Object read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, RubyUtils::Object, set_texture, (std::string filename), texture=, filename)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 *
	 * @param image_rep read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @return RubyUtils::Object read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, RubyUtils::Object, set_texture, (Sketchup::ImageRep image_rep), texture=, image_rep)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 *
	 * @param properties read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @return RubyUtils::Object read https://ruby.sketchup.com/Sketchup/Material.html#texture=-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, RubyUtils::Object, set_texture, (RubyUtils::Enumerable<RubyUtils::tuple<std::string, Sketchup::Length, Sketchup::Length>> properties), texture=, properties)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#use_alpha%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#use_alpha%3F-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Material, bool, does_use_alpha, use_alpha?)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 * @param resolution read https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Material.html#write_thumbnail-instance_method
	 * @min_version SketchUp 8.0 M1
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Material, bool, write_thumbnail, (std::string path, long long resolution), write_thumbnail, path, resolution)

} // namespace HostApp
