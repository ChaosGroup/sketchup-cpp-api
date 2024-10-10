namespace HostApp
{
	inline Sketchup::Sketchup() : IObject("Sketchup")
	{
	}

	inline std::optional<Sketchup::Model> Sketchup::active_model()
	{
		VALUE active_model = this->send("active_model");
		return RTEST(active_model) ? std::make_optional(Sketchup::Model(active_model)) : std::nullopt;
	}

	// https://ruby.sketchup.com/Sketchup.html#version_number-class_method
	inline unsigned int Sketchup::version_number()
	{ // unsinged int would work until 2041 :D
		static const unsigned int version_number = this->_send<unsigned int>("version_number");
		return version_number;
	}

	// No Ruby equivalent
	inline unsigned int Sketchup::major_version()
	{
		// SU2016+: XXYZZZZZZZ   ?  rem  YZZZZZZZ    : rem YYYZZZ for SU6-SU2015
		static const unsigned int major_version = version_number() / ((version_number() >= 1600000000u) ? 100000000u : 1000000u);
		return major_version;
	}
} // namespace HostApp
