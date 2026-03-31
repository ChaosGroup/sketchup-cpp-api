#include <hostapp/sketchup.hpp>
#include <iostream>

using namespace HostApp;

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_any_of_example()
{
	RubyUtils::any_of<int, Sketchup::Model, Sketchup::ComponentDefinition> test;
	test = 5;
	std::cout << "Getting the conainted int: " << test.get<int>() << std::endl;
	if (test.get<int>() != 5) rb_raise(rb_eStandardError, "Get doesn't retieve the correct value.");
	test = rb_eval_string("Sketchup.active_model");
	std::cout << "Getting the conainted Sketchup::Model assigned from VALUE: " << test.get<Sketchup::Model>().to_ruby() << std::endl;
	if (test.get<Sketchup::Model>().to_ruby() == Qnil) rb_raise(rb_eStandardError, "Get doesn't retieve the correct value.");
	
	Sketchup::ComponentDefinition cd = Sketchup::ComponentDefinition(rb_eval_string(R"(Sketchup.active_model.definitions.first)"));
	test = cd;
	std::cout << "Getting the conainted ComponentDefinition from model: " << test.get<Sketchup::ComponentDefinition>().to_ruby()
				<< std::endl;
	if (test.get<Sketchup::ComponentDefinition>().to_ruby() == Qnil) rb_raise(rb_eStandardError, "Get doesn't retieve the correct value.");
	
	std::cout << "Verify the any_of obj does not contain int: (nullptr expected here) " << test.get_if<int>() << std::endl;
	if (test.get_if<int>() != nullptr) rb_raise(rb_eStandardError, "Get doesn't retieve the correct value.");
	
	std::cout << "Verify the any_of obj does not contain int: (false expected here) " << std::boolalpha << test.holds_alternative<int>() << std::endl;
	if (test.holds_alternative<int>()) rb_raise(rb_eStandardError, "Any_of doesn't contain the correct type.");
	
	std::cout << "Verify the any_of obj does not contain Model: (nullptr expected here) " << test.get_if<Sketchup::Model>() << std::endl;
	if (test.get_if<Sketchup::Model>() != nullptr) rb_raise(rb_eStandardError, "Get doesn't retieve the correct value.");
	
	std::cout << "Verify the any_of obj does not contain Model: (false expected here) " << std::boolalpha << test.holds_alternative<Sketchup::Model>()
				<< std::endl;
	if (test.holds_alternative<Sketchup::Model>()) rb_raise(rb_eStandardError, "Any_of doesn't contain the correct type.");
	
	std::cout << "Verify the any_of obj does contain ComponentDefinition: (pointer expected here) " << test.get_if<Sketchup::ComponentDefinition>()
				<< std::endl;
	if (test.get_if<Sketchup::ComponentDefinition>() == nullptr) rb_raise(rb_eStandardError, "Get doesn't retieve the correct value.");
	
	std::cout << "Verify the any_of obj does contain ComponentDefinition: (true expected here) " << std::boolalpha
				<< test.holds_alternative<Sketchup::ComponentDefinition>() << std::endl;
	if (!test.holds_alternative<Sketchup::ComponentDefinition>()) rb_raise(rb_eStandardError, "Any_of doesn't contain the correct type.");
	
	std::cout << "Verify inability to assign objects of unlisted type to the any_of obj (runtime Ruby error expected)" << std::endl;
	std::function<VALUE()> f = [&]() -> VALUE {
		test = rb_eval_string(R"(
			module Sketchup
				class RandomUnlistedClass
				end
			end
			Sketchup::RandomUnlistedClass.new
		)");
		return Qfalse;
	};
	
	/*
	Compile-time error: Sketchup::DefinitionList can't be RubyUtils::any_of<int, Sketchup::Model, Sketchup::ComponentDefinition>
	std::cout << "Verify inability to assign objects of unlisted type to the any_of obj (runtime runtime Ruby error expected)" << std::endl;
	test = Sketchup::DefinitionList(rb_eval_string(R"(
			module Sketchup
				class RandomUnlistedClass
				end
			end
			Sketchup::RandomUnlistedClass.new
	)"));
	*/
}
