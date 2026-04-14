#include <SketchUpCppAPI/SketchUpCppAPI.hpp>

using namespace SketchUpCppAPI::HostApp;

extern "C"
void Init_hello_sketchup()
{
	auto version = Sketchup::version();
	auto app = Sketchup::app_name();

	std::string message = app + " " + version;

	UI::messagebox(message, 0L);
}
