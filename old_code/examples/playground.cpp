#include <hostapp/sketchup.hpp>

using namespace HostApp;

VALUE play(VALUE self)
{
	auto model = Sketchup().active_model();
	if (model)
		return rb_str_new_cstr(model.value().name().c_str());
	else
		return Qnil;
}

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_playground() {
	
	VALUE playground = rb_define_class("Playground", rb_cObject);
	
	rb_define_singleton_method(playground, "play", play, 0);
		
}
