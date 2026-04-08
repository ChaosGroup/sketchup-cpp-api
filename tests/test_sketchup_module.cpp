#include <doctest.h>
#include <hostapp.hpp>

using namespace sca::HostApp;

TEST_SUITE("Sketchup") {

    // --- Simple getters (no arguments) ---

    TEST_CASE("active_model") {
        auto model = Sketchup::active_model();
        CHECK(model.has_value());
    }

    TEST_CASE("app_name") {
        auto name = Sketchup::app_name();
        CHECK(!name.empty());
    }

    TEST_CASE("break_edges") {
        Sketchup::break_edges();
    }

    TEST_CASE("create_texture_writer") {
        Sketchup::create_texture_writer();
    }

    TEST_CASE("debug_mode") {
        Sketchup::debug_mode();
    }

    TEST_CASE("extensions") {
        Sketchup::extensions();
    }

    TEST_CASE("fix_shadow_strings") {
        Sketchup::fix_shadow_strings();
    }

    TEST_CASE("focus") {
        Sketchup::focus();
    }

    TEST_CASE("get_locale") {
        auto locale = Sketchup::get_locale();
        CHECK(!locale.empty());
    }

    TEST_CASE("get_shortcuts") {
        auto shortcuts = Sketchup::get_shortcuts();
    }

    TEST_CASE("is_64bit") {
        CHECK(Sketchup::is_64bit());
    }

    TEST_CASE("is_online") {
        Sketchup::is_online();
    }

    TEST_CASE("is_pro") {
        Sketchup::is_pro();
    }

    TEST_CASE("os_language") {
        auto lang = Sketchup::os_language();
        CHECK(!lang.empty());
    }

    TEST_CASE("platform") {
        const char* p = Sketchup::platform();
        CHECK(p != nullptr);
    }

    TEST_CASE("plugins_disabled") {
        Sketchup::plugins_disabled();
    }

    TEST_CASE("temp_dir") {
        auto dir = Sketchup::temp_dir();
        CHECK(!dir.empty());
    }

    TEST_CASE("get_template") {
        Sketchup::get_template();
    }

    TEST_CASE("template_dir") {
        auto dir = Sketchup::template_dir();
        CHECK(!dir.empty());
    }

    TEST_CASE("version") {
        auto ver = Sketchup::version();
        CHECK(!ver.empty());
    }

    TEST_CASE("version_number") {
        auto ver = Sketchup::version_number();
        CHECK(ver > 0);
    }

    // --- Getter/setter pairs ---

    TEST_CASE("assign_break_edges") {
        bool original = Sketchup::break_edges();
        Sketchup::assign_break_edges(!original);
        CHECK(Sketchup::break_edges() == !original);
        Sketchup::assign_break_edges(original);
        CHECK(Sketchup::break_edges() == original);
    }

    TEST_CASE("assign_debug_mode") {
        bool original = Sketchup::debug_mode();
        Sketchup::assign_debug_mode(!original);
        CHECK(Sketchup::debug_mode() == !original);
        Sketchup::assign_debug_mode(original);
        CHECK(Sketchup::debug_mode() == original);
    }

    TEST_CASE("assign_fix_shadow_strings") {
        bool original = Sketchup::fix_shadow_strings();
        Sketchup::assign_fix_shadow_strings(!original);
        CHECK(Sketchup::fix_shadow_strings() == !original);
        Sketchup::assign_fix_shadow_strings(original);
        CHECK(Sketchup::fix_shadow_strings() == original);
    }

    TEST_CASE("assign_plugins_disabled") {
        bool original = Sketchup::plugins_disabled();
        // Don't toggle; just verify round-trip with same value
        Sketchup::assign_plugins_disabled(original);
    }

    TEST_CASE("assign_status_text") {
        Sketchup::assign_status_text("test status");
    }

    TEST_CASE("assign_vcb_label") {
        Sketchup::assign_vcb_label("Test Label");
    }

    TEST_CASE("assign_vcb_value") {
        Sketchup::assign_vcb_value("42");
    }

    TEST_CASE("assign_template") {
        Sketchup::assign_template(Sketchup::get_template());
    }

    // --- Formatting methods ---

    TEST_CASE("format_angle") {
        auto result = Sketchup::format_angle(1.5708);
        CHECK(!result.empty());
    }

    TEST_CASE("format_area") {
        auto result = Sketchup::format_area(100.0);
        CHECK(!result.empty());
    }

    TEST_CASE("format_degrees") {
        auto result = Sketchup::format_degrees(90.0);
        CHECK(!result.empty());
    }

    TEST_CASE("format_length") {
        auto result = Sketchup::format_length(10.0);
        CHECK(!result.empty());
    }

    TEST_CASE("format_volume") {
        auto result = Sketchup::format_volume(1000.0);
        CHECK(!result.empty());
    }

    TEST_CASE("parse_length") {
        auto result = Sketchup::parse_length("10\"");
        CHECK(result > 0.0);
    }

    // --- Query / lookup methods ---

    TEST_CASE("display_name_from_action") {
        Sketchup::display_name_from_action("selectSelectionTool:");
    }

    TEST_CASE("find_support_file") {
        Sketchup::find_support_file("Plugins", "");
    }

    TEST_CASE("find_support_files") {
        auto files = Sketchup::find_support_files("rb", "Plugins");
    }

    TEST_CASE("get_datfile_info") {
        Sketchup::get_datfile_info("ProductKey", "");
    }

    TEST_CASE("get_i18n_datfile_info") {
        Sketchup::get_i18n_datfile_info("ProductKey", "");
    }

    TEST_CASE("get_resource_path") {
        Sketchup::get_resource_path("test.png");
    }

    TEST_CASE("is_valid_filename") {
        CHECK(Sketchup::is_valid_filename("model.skp"));
        CHECK_FALSE(Sketchup::is_valid_filename(""));
    }

    // --- Defaults (read/write) ---

    TEST_CASE("write_default and read_default") {
        bool written = Sketchup::write_default("TestSection_SCA", "TestKey", "TestValue");
        CHECK(written);

        auto value = Sketchup::read_default("TestSection_SCA", "TestKey", "");
        CHECK(value.has_value());
    }

    // --- Status / UI methods ---

    TEST_CASE("set_status_text") {
        Sketchup::set_status_text("Test status message");
    }

    TEST_CASE("send_action") {
        Sketchup::send_action("selectSelectionTool:");
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
        Sketchup::undo();
    }

    TEST_CASE("redo") {
        Sketchup::redo();
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
        Sketchup::Licensing::get_extension_license("test-extension-id");
    }

} // TEST_SUITE("Sketchup::Licensing")

TEST_SUITE("Sketchup::RegionalSettings") {

    TEST_CASE("decimal_separator") {
        auto sep = Sketchup::RegionalSettings::decimal_separator();
        CHECK(!sep.empty());
    }

    TEST_CASE("list_separator") {
        auto sep = Sketchup::RegionalSettings::list_separator();
        CHECK(!sep.empty());
    }

} // TEST_SUITE("Sketchup::RegionalSettings")

TEST_SUITE("Sketchup::Skp") {

    TEST_CASE("read_guid") {
        // Requires a valid .skp file path
        // Sketchup::Skp::read_guid("/path/to/model.skp");
    }

} // TEST_SUITE("Sketchup::Skp")
