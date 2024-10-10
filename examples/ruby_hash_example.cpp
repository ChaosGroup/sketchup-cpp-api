#include <hostapp/sketchup.hpp>
#include <iostream>

using namespace std::literals;
using namespace HostApp;
using namespace RubyUtils;

// used to test for valid syntax without compile-time errors
template<cpp_utils::details::string_literal unlisted_key, typename hash_t>
concept is_getting_unlisted_key_allowed = requires(hash_t my_hash) 
{
    my_hash.template get<unlisted_key>();
};

static VALUE run(VALUE);

extern "C"

#ifdef _WIN32
__declspec(dllexport)
#endif

void Init_ruby_hash_example()
{
	VALUE klass = rb_define_class("RubyHashExample", rb_cObject);
	rb_define_singleton_method(klass, "run", RUBY_METHOD_FUNC(run), 0);
}

static VALUE run(VALUE self)
{
    {
        // Create new empty Ruby hash
        RubyUtils::Hash<Key<"key1", int>, Key<"key2", std::string_view>, Key<"key3", Sketchup::Model>> my_hash;
        // Get the key value
        {
            if (my_hash.get<"key1">().has_value())
                rb_raise(rb_eStandardError, "Empty hash has set value for the keys");
        }
        // Set the key value
        {
            const int value = 5;
            my_hash.set<"key1">(value);
            const auto key1 = my_hash.get<"key1">();
            if (!key1.has_value() || key1.value() != value)
                rb_raise(rb_eStandardError, "Hash with set value for a key doesn't give it back properly.");
        }
        // Set the key value with default convertible types
        {
            {
                const char* text = "Testing with const char*";
                my_hash.set<"key2">(text);
                if (my_hash.get<"key2">() != text)
                {
                    rb_raise(rb_eStandardError, "Hash can't set a const char* value properly to std::string_view key.");
                }
            }
            {
                std::string text = "Testing with std::string";
                my_hash.set<"key2">(text);
                if (my_hash.get<"key2">() != text)
                {
                    rb_raise(rb_eStandardError, "Hash can't set a std::string value properly to std::string_view key.");
                }
            }
            {
                std::string_view text = "Testing with std::string_view";
                my_hash.set<"key2">(text);
                if (my_hash.get<"key2">() != text)
                {
                    rb_raise(rb_eStandardError, "Hash can't set a std::string_view value properly to std::string_view key.");
                }
            }
        }
    }
    // Unlisted keys should not be allowed
    {
        if constexpr (is_getting_unlisted_key_allowed<"key4", RubyUtils::Hash<Key<"key1", int>, Key<"key2", std::string>, Key<"key3", Sketchup::Model>>>)
            rb_raise(rb_eStandardError, "Library is broken. Unlisted key was allowed as key for a Ruby Hash wrapper.");
    }
    // Init empty Ruby hash with values
    {
        // Create new empty Ruby hash
        RubyUtils::Hash<Key<"key1", int>, Key<"key2", std::string_view>, Key<"key3", Sketchup::Model>> my_hash (
            std::pair{"key1"sv, 5},
            std::pair{"key2"sv, "Test"},
            std::pair{"key4"sv, "Won't be saved"}
        );
        // Confirm key1
        {
            const auto key = my_hash.get<"key1">();
            if (!key.has_value() || key.value() != 5)
                rb_raise(rb_eStandardError, "Initialized key (key1) is either not set or set incorrectly.");
        }
        // Confirm key2
        {
            const auto key = my_hash.get<"key2">();
            if (!key.has_value() || key.value() != "Test")
                rb_raise(rb_eStandardError, "Initialized key (key2) is either not set or set incorrectly.");
        }
        // Confirm key4
        {
            const VALUE key = rb_hash_aref(my_hash.to_ruby(), rb_intern_const("key4"));
            // const auto key = my_hash.get<"key4">(); // compile-time error
            if (key != Qnil)
                rb_raise(rb_eStandardError, "Invalid key has been set.");
        }
    }
    // Init empty Ruby hash with Ruby object
    {
        // Create new empty Ruby hash
        RubyUtils::Hash<Key<"key1", int>, Key<"key2", std::string_view>, Key<"key3", Sketchup::Model>> my_hash (
            rb_eval_string("{:key1 => 5, :key2 => \"Test\", :key4 => \"Won't be saved\"}")
        );
        // Confirm key1
        {
            const auto key = my_hash.get<"key1">();
            if (!key.has_value() || key.value() != 5)
                rb_raise(rb_eStandardError, "Initialized key (key1) is either not set or set incorrectly.");
        }
        // Confirm key2
        {
            const auto key = my_hash.get<"key2">();
            if (!key.has_value() || key.value() != "Test")
                rb_raise(rb_eStandardError, "Initialized key (key2) is either not set or set incorrectly.");
        }
        // Confirm key4
        {
            const VALUE key = rb_hash_aref(my_hash.to_ruby(), rb_intern_const("key4"));
            // const auto key = my_hash.get<"key4">(); // compile-time error
            if (key != Qnil)
                rb_raise(rb_eStandardError, "Invalid key has been set.");
        }
    }
    std::cout << "Success" << std::endl;
    return Qnil;
}
