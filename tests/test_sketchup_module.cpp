#include <doctest.h>
#include <SketchUpCppAPI/HostApp.hpp>

using namespace SketchUpCppAPI::HostApp;

TEST_SUITE("Sketchup") {

    // --- Simple getters (no arguments) ---

    TEST_CASE("active_model") {
        SketchUpCppAPI::protect([]() {
            std::optional<Sketchup::Model> model = Sketchup::active_model();
#ifdef WIN32
            CHECK(model.has_value());
#endif
        });
    }

    TEST_CASE("app_name") {
        SketchUpCppAPI::protect([]() {
            std::string name = Sketchup::app_name();
            CHECK(name == "SketchUp Pro");
        });
    }

    TEST_CASE("break_edges") {
        SketchUpCppAPI::protect([]() {
            bool res = Sketchup::break_edges();
        });
    }

    TEST_CASE("create_texture_writer") {
        SketchUpCppAPI::protect([]() {
            Sketchup::TextureWriter res = Sketchup::create_texture_writer();
        });
    }

    TEST_CASE("debug_mode") {
        SketchUpCppAPI::protect([]() {
            bool res = Sketchup::debug_mode();
        });
    }

    TEST_CASE("extensions") {
        SketchUpCppAPI::protect([]() {
            Sketchup::ExtensionsManager res = Sketchup::extensions();
        });
    }

    TEST_CASE("fix_shadow_strings") {
        SketchUpCppAPI::protect([]() {
            bool res = Sketchup::fix_shadow_strings();
        });
    }

    TEST_CASE("focus") {
        SketchUpCppAPI::protect([]() {
            Sketchup::focus();
        });
    }

    TEST_CASE("get_locale") {
        SketchUpCppAPI::protect([]() {
            std::string locale = Sketchup::get_locale();
            CHECK(!locale.empty());
        });
    }

    TEST_CASE("get_shortcuts") {
        SketchUpCppAPI::protect([]() {
            std::vector<std::string> res = Sketchup::get_shortcuts();
            CHECK(!res.empty());
            CHECK(!res.front().empty());
        });
    }

    TEST_CASE("is_64bit") {
        SketchUpCppAPI::protect([]() {
            CHECK(Sketchup::is_64bit());
        });
    }

    TEST_CASE("is_online") {
        SketchUpCppAPI::protect([]() {
            bool res = Sketchup::is_online();
        });
    }

    TEST_CASE("is_pro") {
        SketchUpCppAPI::protect([]() {
            CHECK(Sketchup::is_pro());
        });
    }

    TEST_CASE("os_language") {
        SketchUpCppAPI::protect([]() {
            std::string lang = Sketchup::os_language();
            CHECK(!lang.empty());
        });
    }

    TEST_CASE("platform") {
        SketchUpCppAPI::protect([]() {
            const char* res = Sketchup::platform();
#ifdef WIN32
            CHECK(strcmp(res, "platform_win") == 0);
#elif __APPLE__
            CHECK(strcmp(res, "platform_osx") == 0);
#endif
        });
    }

    TEST_CASE("plugins_disabled") {
        SketchUpCppAPI::protect([]() { 
            bool res = Sketchup::plugins_disabled();
        });
    }

    TEST_CASE("temp_dir") {
        SketchUpCppAPI::protect([]() {
            std::string dir = Sketchup::temp_dir();
            CHECK(!dir.empty());
        });
    }

    TEST_CASE("get_template") {
        SketchUpCppAPI::protect([]() {
            std::string res = Sketchup::get_template();
            CHECK(!res.empty());
        });
    }

    TEST_CASE("template_dir") {
        SketchUpCppAPI::protect([]() {
            std::string dir = Sketchup::template_dir();
            CHECK(!dir.empty());
        });
    }

    TEST_CASE("version") {
        SketchUpCppAPI::protect([]() {
            std::string ver = Sketchup::version();
            CHECK(!ver.empty());
        });
    }

    TEST_CASE("version_number") {
        SketchUpCppAPI::protect([]() {
            long ver = Sketchup::version_number();
            long major = (ver / 1000000) + 2000;
            CHECK(major > 2026);
        });
    }

    // --- Getter/setter pairs ---

    TEST_CASE("assign_break_edges") {
        SketchUpCppAPI::protect([]() {
            bool original = Sketchup::break_edges();
            Sketchup::assign_break_edges(!original);
            CHECK(Sketchup::break_edges() == !original);
            Sketchup::assign_break_edges(original);
            CHECK(Sketchup::break_edges() == original);
        });
    }

    TEST_CASE("assign_debug_mode") {
        SketchUpCppAPI::protect([]() {
            bool original = Sketchup::debug_mode();
            Sketchup::assign_debug_mode(!original);
            CHECK(Sketchup::debug_mode() == !original);
            Sketchup::assign_debug_mode(original);
            CHECK(Sketchup::debug_mode() == original);
        });
    }

    TEST_CASE("assign_fix_shadow_strings") {
        SketchUpCppAPI::protect([]() {
            bool original = Sketchup::fix_shadow_strings();
            Sketchup::assign_fix_shadow_strings(!original);
            CHECK(Sketchup::fix_shadow_strings() == !original);
            Sketchup::assign_fix_shadow_strings(original);
            CHECK(Sketchup::fix_shadow_strings() == original);
        });
    }

    TEST_CASE("assign_plugins_disabled") {
        SketchUpCppAPI::protect([]() {
            bool original = Sketchup::plugins_disabled();
            Sketchup::assign_plugins_disabled(original);
        });
    }

    TEST_CASE("assign_status_text") {
        SketchUpCppAPI::protect([]() { Sketchup::assign_status_text("test status"); });
    }

    TEST_CASE("assign_vcb_label") {
        SketchUpCppAPI::protect([]() { Sketchup::assign_vcb_label("Test Label"); });
    }

    TEST_CASE("assign_vcb_value") {
        SketchUpCppAPI::protect([]() { Sketchup::assign_vcb_value("42"); });
    }

    TEST_CASE("assign_template") {
        SketchUpCppAPI::protect([]() { Sketchup::assign_template(Sketchup::get_template()); });
    }

    // --- Formatting methods ---

    TEST_CASE("format_angle") {
        SketchUpCppAPI::protect([]() {
            std::string result = Sketchup::format_angle(1.5708);
            CHECK(!result.empty());
        });
    }

    TEST_CASE("format_area") {
        SketchUpCppAPI::protect([]() {
            std::string result = Sketchup::format_area(100.0);
            CHECK(!result.empty());
        });
    }

    TEST_CASE("format_degrees") {
        SketchUpCppAPI::protect([]() {
            std::string result = Sketchup::format_degrees(90.0);
            CHECK(!result.empty());
        });
    }

    TEST_CASE("format_length") {
        SketchUpCppAPI::protect([]() {
            std::string result = Sketchup::format_length(10.0);
            CHECK(!result.empty());
        });
    }

    TEST_CASE("format_volume") {
        SketchUpCppAPI::protect([]() {
            std::string result = Sketchup::format_volume(1000.0);
            CHECK(!result.empty());
        });
    }

    TEST_CASE("parse_length") {
        SketchUpCppAPI::protect([]() {
            double result = Sketchup::parse_length("10\"");
            CHECK(result > 0.0);
        });
    }

    // --- Query / lookup methods ---

    TEST_CASE("display_name_from_action") {
        SketchUpCppAPI::protect([]() { Sketchup::display_name_from_action("selectSelectionTool:"); });
    }

    TEST_CASE("find_support_file") {
        SketchUpCppAPI::protect([]() { Sketchup::find_support_file("Plugins", ""); });
    }

    TEST_CASE("find_support_files") {
        SketchUpCppAPI::protect([]() { Sketchup::find_support_files("rb", "Plugins"); });
    }

    TEST_CASE("get_datfile_info") {
        SketchUpCppAPI::protect([]() { Sketchup::get_datfile_info("ProductKey", ""); });
    }

    TEST_CASE("get_i18n_datfile_info") {
        SketchUpCppAPI::protect([]() { Sketchup::get_i18n_datfile_info("ProductKey", ""); });
    }

    TEST_CASE("get_resource_path") {
        SketchUpCppAPI::protect([]() { Sketchup::get_resource_path("test.png"); });
    }

    TEST_CASE("is_valid_filename") {
        SketchUpCppAPI::protect([]() {
            CHECK(Sketchup::is_valid_filename("model.skp"));
        });
    }

    // --- Defaults (read/write) ---

    TEST_CASE("write_default and read_default") {
        SketchUpCppAPI::protect([]() {
            bool written = Sketchup::write_default("TestSection_SCA", "TestKey", "TestValue");
            CHECK(written);
        });

        SketchUpCppAPI::protect([]() {
            std::optional<SketchUpCppAPI::Object> value = Sketchup::read_default("TestSection_SCA", "TestKey", "");
            CHECK(value.has_value());
        });
    }

    // --- Status / UI methods ---

    TEST_CASE("set_status_text") {
        SketchUpCppAPI::protect([]() { Sketchup::set_status_text("Test status message"); });
    }

    TEST_CASE("send_action") {
        SketchUpCppAPI::protect([]() { Sketchup::send_action("selectSelectionTool:"); });
    }

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

    TEST_CASE("undo") {
        SketchUpCppAPI::protect([]() { Sketchup::undo(); });
    }

    TEST_CASE("redo") {
        SketchUpCppAPI::protect([]() { Sketchup::redo(); });
    }

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

// --- Sub-namespace tests ---

TEST_SUITE("Sketchup::Licensing") {

    TEST_CASE("get_extension_license") {
        SketchUpCppAPI::protect([]() { Sketchup::Licensing::get_extension_license("test-extension-id"); });
    }

} // TEST_SUITE("Sketchup::Licensing")

TEST_SUITE("Sketchup::RegionalSettings") {

    TEST_CASE("decimal_separator") {
        SketchUpCppAPI::protect([]() {
            std::string sep = Sketchup::RegionalSettings::decimal_separator();
            CHECK(!sep.empty());
        });
    }

    TEST_CASE("list_separator") {
        SketchUpCppAPI::protect([]() {
            std::string sep = Sketchup::RegionalSettings::list_separator();
            CHECK(!sep.empty());
        });
    }

} // TEST_SUITE("Sketchup::RegionalSettings")

TEST_SUITE("Sketchup::Skp") {

    TEST_CASE("read_guid") {
        // Requires a valid .skp file path
        // Sketchup::Skp::read_guid("/path/to/model.skp");
    }

} // TEST_SUITE("Sketchup::Skp")
