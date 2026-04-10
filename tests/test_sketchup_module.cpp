#include <doctest.h>
#include <SketchUpCppAPI/SketchUpCppAPI.hpp>

#define PROTECTED_TEST_CASE(name, ...) \
    TEST_CASE(name) { SketchUpCppAPI::protect([]() __VA_ARGS__); }

using namespace SketchUpCppAPI::HostApp;

TEST_SUITE("Sketchup") {

    // --- Simple getters (no arguments) ---

    PROTECTED_TEST_CASE("active_model", {
        std::optional<Sketchup::Model> model = Sketchup::active_model();
#ifdef WIN32
        CHECK(model.has_value());
#endif
    })

    PROTECTED_TEST_CASE("app_name", {
        std::string name = Sketchup::app_name();
        CHECK(name == "SketchUp Pro");
    })

    PROTECTED_TEST_CASE("break_edges", {
        bool res = Sketchup::break_edges();
    })

    PROTECTED_TEST_CASE("create_texture_writer", {
        Sketchup::TextureWriter res = Sketchup::create_texture_writer();
    })

    PROTECTED_TEST_CASE("debug_mode", {
        bool res = Sketchup::debug_mode();
    })

    PROTECTED_TEST_CASE("extensions", {
        Sketchup::ExtensionsManager res = Sketchup::extensions();
    })

    PROTECTED_TEST_CASE("fix_shadow_strings", {
        bool res = Sketchup::fix_shadow_strings();
    })

    PROTECTED_TEST_CASE("focus", {
        Sketchup::focus();
    })

    PROTECTED_TEST_CASE("get_locale", {
        std::string locale = Sketchup::get_locale();
        CHECK(!locale.empty());
    })

    PROTECTED_TEST_CASE("get_shortcuts", {
        std::vector<std::string> res = Sketchup::get_shortcuts();
        CHECK(!res.empty());
        if (!res.empty())
            CHECK(!res.front().empty());
    })

    PROTECTED_TEST_CASE("is_64bit", {
        CHECK(Sketchup::is_64bit());
    })

    PROTECTED_TEST_CASE("is_online", {
        bool res = Sketchup::is_online();
    })

    PROTECTED_TEST_CASE("is_pro", {
        CHECK(Sketchup::is_pro());
    })

    PROTECTED_TEST_CASE("os_language", {
        std::string lang = Sketchup::os_language();
        CHECK(!lang.empty());
    })

    PROTECTED_TEST_CASE("platform", {
        const char* res = Sketchup::platform();
#ifdef WIN32
        CHECK(strcmp(res, "platform_win") == 0);
#elif __APPLE__
        CHECK(strcmp(res, "platform_osx") == 0);
#endif
    })

    PROTECTED_TEST_CASE("plugins_disabled", {
        bool res = Sketchup::plugins_disabled();
    })

    PROTECTED_TEST_CASE("temp_dir", {
        std::string dir = Sketchup::temp_dir();
        CHECK(!dir.empty());
    })

    PROTECTED_TEST_CASE("get_template", {
        std::string res = Sketchup::get_template();
        CHECK(!res.empty());
    })

    PROTECTED_TEST_CASE("template_dir", {
        std::string dir = Sketchup::template_dir();
        CHECK(!dir.empty());
    })

    PROTECTED_TEST_CASE("version", {
        std::string ver = Sketchup::version();
        CHECK(!ver.empty());
    })

    PROTECTED_TEST_CASE("version_number", {
        long ver = Sketchup::version_number();
        long major = (ver / 100000000) + 2000;
        CHECK(major >= 2021);
        CHECK(major <= 2026);
    })

    // --- Getter/setter pairs ---

    PROTECTED_TEST_CASE("assign_break_edges", {
        bool original = Sketchup::break_edges();
        Sketchup::assign_break_edges(!original);
        CHECK(Sketchup::break_edges() == !original);
        Sketchup::assign_break_edges(original);
        CHECK(Sketchup::break_edges() == original);
    })

    PROTECTED_TEST_CASE("assign_debug_mode", {
        bool original = Sketchup::debug_mode();
        Sketchup::assign_debug_mode(!original);
        CHECK(Sketchup::debug_mode() == !original);
        Sketchup::assign_debug_mode(original);
        CHECK(Sketchup::debug_mode() == original);
    })

    PROTECTED_TEST_CASE("assign_fix_shadow_strings", {
        bool original = Sketchup::fix_shadow_strings();
        Sketchup::assign_fix_shadow_strings(!original);
        CHECK(Sketchup::fix_shadow_strings() == !original);
        Sketchup::assign_fix_shadow_strings(original);
        CHECK(Sketchup::fix_shadow_strings() == original);
    })

    PROTECTED_TEST_CASE("assign_plugins_disabled", {
        bool original = Sketchup::plugins_disabled();
        Sketchup::assign_plugins_disabled(original);
    })

    PROTECTED_TEST_CASE("assign_status_text", {
        Sketchup::assign_status_text("test status");
    })

    PROTECTED_TEST_CASE("assign_vcb_label", {
        Sketchup::assign_vcb_label("Test Label");
    })

    PROTECTED_TEST_CASE("assign_vcb_value", {
        Sketchup::assign_vcb_value("42");
    })

    PROTECTED_TEST_CASE("assign_template", {
        Sketchup::assign_template(Sketchup::get_template());
    })

    // --- Formatting methods ---

    PROTECTED_TEST_CASE("format_angle", {
        std::string result = Sketchup::format_angle(1.5708);
        CHECK(!result.empty());
    })

    PROTECTED_TEST_CASE("format_area", {
        std::string result = Sketchup::format_area(100.0);
        CHECK(!result.empty());
    })

    PROTECTED_TEST_CASE("format_degrees", {
        std::string result = Sketchup::format_degrees(90.0);
        CHECK(!result.empty());
    })

    PROTECTED_TEST_CASE("format_length", {
        std::string result = Sketchup::format_length(10.0);
        CHECK(!result.empty());
    })

    PROTECTED_TEST_CASE("format_volume", {
        std::string result = Sketchup::format_volume(1000.0);
        CHECK(!result.empty());
    })

    PROTECTED_TEST_CASE("parse_length", {
        double result = Sketchup::parse_length("10\"");
        CHECK(result > 0.0);
    })

    // --- Query / lookup methods ---

    PROTECTED_TEST_CASE("display_name_from_action", {
        std::string name = Sketchup::display_name_from_action("selectSelectionTool:");
        CHECK(!name.empty());
    })

    PROTECTED_TEST_CASE("find_support_file", {
        std::string path = Sketchup::find_support_file("Plugins", "");
        CHECK(!path.empty());
    })

    PROTECTED_TEST_CASE("find_support_files", {
        std::vector<std::string> files = Sketchup::find_support_files("rb", "Plugins");
        CHECK(!files.empty());
    })

    PROTECTED_TEST_CASE("get_datfile_info", {
        std::string value = Sketchup::get_datfile_info("ProductKey", "");
    })

    PROTECTED_TEST_CASE("get_i18n_datfile_info", {
        std::string value = Sketchup::get_i18n_datfile_info("ProductKey", "");
    })

    PROTECTED_TEST_CASE("get_resource_path", {
        std::string path = Sketchup::get_resource_path("test.png");
    })

    PROTECTED_TEST_CASE("is_valid_filename", {
        CHECK(Sketchup::is_valid_filename("model.skp"));
    })

    // --- Defaults (read/write) ---

    PROTECTED_TEST_CASE("write_default", {
        bool written = Sketchup::write_default("TestSection_SCA", "TestKey", "TestValue");
        CHECK(written);
    })

    PROTECTED_TEST_CASE("read_default", {
        std::optional<SketchUpCppAPI::Object> value = Sketchup::read_default("TestSection_SCA", "TestKey", "");
        CHECK(value.has_value());
    })

    // --- Status / UI methods ---

    PROTECTED_TEST_CASE("set_status_text", {
        Sketchup::set_status_text("Test status message");
    })

    PROTECTED_TEST_CASE("send_action", {
        bool result = Sketchup::send_action("selectSelectionTool:");
        CHECK(result);
    })

    // --- Observer methods ---

    TEST_CASE("add_observer") {
        // Requires an AppObserver instance
        // Sketchup::add_observer(some_observer);
    }

    TEST_CASE("remove_observer") {
        // Requires an AppObserver instance
        // Sketchup::remove_observer(some_observer);
    }

    // --- Registration methods ---

    TEST_CASE("register_extension") {
        // Requires a SketchupExtension instance
        // Sketchup::register_extension(ext, true);
    }

    TEST_CASE("register_importer") {
        // Requires an Importer instance
        // Sketchup::register_importer(importer);
    }

    // --- File operations ---

    TEST_CASE("save_thumbnail") {
        // Requires a saved .skp file
        // Sketchup::save_thumbnail("model.skp", Sketchup::temp_dir() + "/thumb.png");
    }

    TEST_CASE("send_to_layout") {
        // Requires LayOut installed
        // Sketchup::send_to_layout("model.layout");
    }

    TEST_CASE("load") {
        // Loads a Ruby file; skip to avoid side effects
        // Sketchup::load("nonexistent.rb");
    }

    TEST_CASE("require") {
        // Loads a Ruby file; skip to avoid side effects
        // Sketchup::require("nonexistent");
    }

    TEST_CASE("install_from_archive") {
        // Installs an extension; skip to avoid side effects
        // Sketchup::install_from_archive("test.rbz", false);
    }

    // --- Destructive / state-changing methods ---

    PROTECTED_TEST_CASE("undo", {
        Sketchup::undo();
    })

    PROTECTED_TEST_CASE("redo", {
        Sketchup::redo();
    })

    TEST_CASE("resize_viewport") {
        // Resizing affects the UI
        // Sketchup::resize_viewport(800, 600);
    }

    TEST_CASE("file_new") {
        // Creates a new model; skip to avoid losing current state
        // Sketchup::file_new();
    }

    TEST_CASE("open_file") {
        // Opens a file; skip to avoid side effects
        // Sketchup::open_file("test.skp");
    }

    TEST_CASE("quit") {
        // Would terminate SketchUp
        // Sketchup::quit();
    }

} // TEST_SUITE("Sketchup")
