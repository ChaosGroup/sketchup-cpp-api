#pragma once

#include <memory>

namespace SketchUpCppAPI::HostApp::detail
{

	template<typename T>
	void free_observer(void* p) {
		auto* sp = static_cast<std::shared_ptr<T>*>(p);
		if (auto ptr = sp->get()) {
			ptr->self = Qnil;
		}
		delete sp;
	}

	template<typename T>
	VALUE& observer_klass_for() {
		static VALUE klass = Qnil;
		return klass;
	}

	template<typename T, typename RegisterFn>
	void init_observer(std::shared_ptr<T>& observer, RegisterFn register_fn) {
		VALUE& klass = observer_klass_for<T>();
		if (klass == Qnil) {
			klass = rb_class_new(rb_eval_string(T::ruby_class_name));
			rb_gc_register_address(&klass);
			register_fn(klass);
		}
		auto* sp = new std::shared_ptr<T>(observer);
		observer->self = Data_Wrap_Struct(klass, nullptr, free_observer<T>, sp);
	}

}
