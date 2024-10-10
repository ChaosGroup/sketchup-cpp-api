#include <hostapp/sketchup.hpp>
#include <iostream>

using namespace HostApp;

// Consumer implements the following
class MyEntitiesObserverImplementation final : public HostApp::Sketchup::EntitiesObserver
{
	int something = 67;

	public:
	MyEntitiesObserverImplementation() : EntitiesObserver(EntitiesObserver::ON_ACTIVE_SECTION_PLANE_CHANGED)
	{
	}
	void onActiveSectionPlaneChanged(Sketchup::Entities entities) override
	{
		std::cout << something << std::endl;
		something++;
	}
	int getter() const
	{
		return something;
	}
};

// pseudo function for testing
void add_observer(HostApp::Sketchup::EntitiesObserver& observer) {}

// compile-time error checkers
template <typename T>
concept can_be_instantiated = requires {
	{ T() };
};

template <typename T>
concept can_create_shared_ptr_of = requires {
	{ std::shared_ptr<T>(new T()) };
};

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_entities_observer_example(void)
{
	{
		if constexpr (can_be_instantiated<HostApp::Sketchup::EntitiesObserver>)
		{
			rb_raise(rb_eStandardError, "You should never be able to create observers on the stack.");
		}
		MyEntitiesObserverImplementation i_compile_but_i_will_never_link_your_cpp_function_to_ruby_so_i_will_always_be_empty_nil;
		if constexpr (can_create_shared_ptr_of<HostApp::Sketchup::EntitiesObserver>)
		{
			rb_raise(rb_eStandardError, "You should never be able to create shared_ptr yourself for observers.");
		}
	}
	[[maybe_unused]] VALUE observer1, observer2, observer3;
	int test_value = 42;
	// Easily wrap c++ objects in ruby, but get a safe handle on the implementation;
	{
		std::shared_ptr<HostApp::Sketchup::EntitiesObserver> impl = HostApp::make_ruby<HostApp::Sketchup::EntitiesObserver>();
		impl->set_onActiveSectionPlaneChanged([&test_value](Sketchup::Entities) {
			static int member_variable = 5;
			std::cout << test_value << " " << member_variable << std::endl;
			test_value++;
			member_variable++;
		});
		add_observer(*impl);
		observer1 = impl->to_ruby();
		rb_funcall(observer1, rb_intern("onActiveSectionPlaneChanged"), 1, Qnil);
		if (test_value != 43)
		{
			rb_raise(rb_eStandardError, "The custom callback of EntitiesObserver has not been called properly.");
		}
	}

	// Easily wrap c++ objects in ruby, but get a safe handle on the implementation;
	std::shared_ptr<MyEntitiesObserverImplementation> impl;
	{
		impl = HostApp::make_ruby<MyEntitiesObserverImplementation>();
		add_observer(*impl);
		observer2 = impl->to_ruby();
		rb_funcall(observer2, rb_intern("onActiveSectionPlaneChanged"), 1, Qnil);
		if (test_value != 43 || impl->getter() != 68)
		{
			rb_raise(rb_eStandardError, "The custom callback of MyEntitiesObserver has not been called properly.");
		}
	}

	// Support for legacy code
	/*{
		std::shared_ptr<HostApp::Sketchup::EntitiesObserver> impl = HostApp::get_ruby<HostApp::Sketchup::EntitiesObserver>(
			RubyUtils::details::IObject(R"(
				class MyEntitiesObserver
					def onElementAdded(entities, entity)
						puts "onElementAdded: #{entity}"
					end
					def nonObserverMethod()
						puts "Hello World!"
					end
				end
				MyEntitiesObserver.new
			)")
		);
		impl->set_onActiveSectionPlaneChanged([&test_value](Sketchup::Entities) {
			static int member_variable = 52;
			std::cout << test_value << " " << member_variable << std::endl;
			test_value++;
			member_variable++;
		});
		add_observer(*impl);
		observer3 = impl->to_ruby();
		rb_funcall(observer3, rb_intern("onActiveSectionPlaneChanged"), 1, Qnil);
		rb_funcall(observer3, rb_intern("onElementAdded"), 2, Qnil, Qtrue);
		rb_funcall(observer3, rb_intern("nonObserverMethod"), 0);
	}*/

	// Verify the object is still alive in Ruby
	{
		rb_funcall(observer1, rb_intern("onActiveSectionPlaneChanged"), 1, Qnil);
		if (test_value != 44 || impl->getter() != 68)
		{
			rb_raise(rb_eStandardError, "The custom callback of MyEntitiesObserver has not been called properly.");
		}
		rb_funcall(observer2, rb_intern("onActiveSectionPlaneChanged"), 1, Qnil);
		if (test_value != 44 || impl->getter() != 69)
		{
			rb_raise(rb_eStandardError, "The custom callback of MyEntitiesObserver has not been called properly.");
		}
	}
}
