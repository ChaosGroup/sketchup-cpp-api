#include <SketchUpCppAPI/SketchUpCppAPI.hpp>
#include <iostream>

using namespace SketchUpCppAPI::HostApp;

static std::shared_ptr<struct MyAppObserver> g_observer;

struct MyAppObserver : Sketchup::AppObserver
{
public:
	void onNewModel(Sketchup::Model model) override
	{
		std::cout << "New model created!" << std::endl;
	}

	void onOpenModel(Sketchup::Model model) override
	{
		std::cout << "Model opened!" << std::endl;
	}

	bool expectsStartupModelNotifications() override
	{
		return true;
	}
};

extern "C"
void Init_app_observer()
{
	g_observer = std::make_shared<MyAppObserver>();
	Sketchup::add_observer(g_observer);

	std::cout << "App observer registered." << std::endl;
}
