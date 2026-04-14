#include <doctest.h>
#include <SketchUpCppAPI/SketchUpCppAPI.hpp>

using namespace SketchUpCppAPI::HostApp;
using SketchUpCppAPI::from_ruby;
using SketchUpCppAPI::to_ruby;

// Provides `Sketchup::Model model` to the test body.
// Skips if no active model. Wraps in protect().
#define MODEL_TEST_CASE(name, ...) \
    TEST_CASE(name) { \
        SketchUpCppAPI::protect([]() { \
            std::optional<Sketchup::Model> _opt_model_ = Sketchup::active_model(); \
            if (!_opt_model_) return; \
            Sketchup::Model model = *_opt_model_; \
            __VA_ARGS__ \
        }); \
    }

TEST_SUITE("Sketchup::Model") {

    // --- Identity ---

    MODEL_TEST_CASE("guid",
        std::string guid = from_ruby<std::string>(rb_funcall(model.self, rb_intern("guid"), 0));
        CHECK(!guid.empty());
        CHECK(guid.size() == 36);
    )

    MODEL_TEST_CASE("name",
        std::string name = from_ruby<std::string>(rb_funcall(model.self, rb_intern("name"), 0));
    )

    MODEL_TEST_CASE("title",
        std::string title = from_ruby<std::string>(rb_funcall(model.self, rb_intern("title"), 0));
    )

    MODEL_TEST_CASE("path",
        std::string path = from_ruby<std::string>(rb_funcall(model.self, rb_intern("path"), 0));
    )

    MODEL_TEST_CASE("description",
        std::string desc = from_ruby<std::string>(rb_funcall(model.self, rb_intern("description"), 0));
    )

    // --- State queries ---

    MODEL_TEST_CASE("valid?",
        CHECK(from_ruby<bool>(rb_funcall(model.self, rb_intern("valid?"), 0)));
    )

    MODEL_TEST_CASE("modified?",
        bool modified = from_ruby<bool>(rb_funcall(model.self, rb_intern("modified?"), 0));
    )

    MODEL_TEST_CASE("georeferenced?",
        bool geo = from_ruby<bool>(rb_funcall(model.self, rb_intern("georeferenced?"), 0));
    )

    MODEL_TEST_CASE("mipmapping?",
        bool mip = from_ruby<bool>(rb_funcall(model.self, rb_intern("mipmapping?"), 0));
    )

    MODEL_TEST_CASE("number_faces",
        long count = from_ruby<long>(rb_funcall(model.self, rb_intern("number_faces"), 0));
        CHECK(count >= 0);
    )

    MODEL_TEST_CASE("get_product_family",
        long family = from_ruby<long>(rb_funcall(model.self, rb_intern("get_product_family"), 0));
    )

    // --- Collections ---

    MODEL_TEST_CASE("entities",
        Sketchup::Entities entities(rb_funcall(model.self, rb_intern("entities"), 0));
        CHECK(entities.self != Qnil);
    )

    MODEL_TEST_CASE("active_entities",
        Sketchup::Entities entities(rb_funcall(model.self, rb_intern("active_entities"), 0));
        CHECK(entities.self != Qnil);
    )

    MODEL_TEST_CASE("definitions",
        Sketchup::DefinitionList defs(rb_funcall(model.self, rb_intern("definitions"), 0));
        CHECK(defs.self != Qnil);
    )

    MODEL_TEST_CASE("materials",
        Sketchup::Materials mats(rb_funcall(model.self, rb_intern("materials"), 0));
        CHECK(mats.self != Qnil);
    )

    MODEL_TEST_CASE("layers",
        Sketchup::Layers layers(rb_funcall(model.self, rb_intern("layers"), 0));
        CHECK(layers.self != Qnil);
    )

    MODEL_TEST_CASE("pages",
        Sketchup::Pages pages(rb_funcall(model.self, rb_intern("pages"), 0));
        CHECK(pages.self != Qnil);
    )

    MODEL_TEST_CASE("selection",
        Sketchup::Selection sel(rb_funcall(model.self, rb_intern("selection"), 0));
        CHECK(sel.self != Qnil);
    )

    MODEL_TEST_CASE("styles",
        Sketchup::Styles styles(rb_funcall(model.self, rb_intern("styles"), 0));
        CHECK(styles.self != Qnil);
    )

    MODEL_TEST_CASE("tools",
        Sketchup::Tools tools(rb_funcall(model.self, rb_intern("tools"), 0));
        CHECK(tools.self != Qnil);
    )

    // --- View / rendering ---

    MODEL_TEST_CASE("active_view",
        Sketchup::View view(rb_funcall(model.self, rb_intern("active_view"), 0));
        CHECK(view.self != Qnil);
    )

    MODEL_TEST_CASE("rendering_options",
        Sketchup::RenderingOptions ro(rb_funcall(model.self, rb_intern("rendering_options"), 0));
        CHECK(ro.self != Qnil);
    )

    MODEL_TEST_CASE("shadow_info",
        Sketchup::ShadowInfo si(rb_funcall(model.self, rb_intern("shadow_info"), 0));
        CHECK(si.self != Qnil);
    )

    MODEL_TEST_CASE("axes",
        Sketchup::Axes axes(rb_funcall(model.self, rb_intern("axes"), 0));
        CHECK(axes.self != Qnil);
    )

    // --- Options ---

    MODEL_TEST_CASE("options",
        Sketchup::OptionsManager opts(rb_funcall(model.self, rb_intern("options"), 0));
        CHECK(opts.self != Qnil);
    )

    // --- Attributes ---

    MODEL_TEST_CASE("set_attribute / get_attribute",
        rb_funcall(model.self, rb_intern("start_operation"), 4,
            rb_str_new_cstr("Test Attr"), Qtrue, Qfalse, Qtrue);
        rb_funcall(model.self, rb_intern("set_attribute"), 3,
            rb_str_new_cstr("TestDict_SCA"), rb_str_new_cstr("TestKey"), rb_str_new_cstr("TestValue"));
        std::string val = from_ruby<std::string>(
            rb_funcall(model.self, rb_intern("get_attribute"), 2,
                rb_str_new_cstr("TestDict_SCA"), rb_str_new_cstr("TestKey")));
        CHECK(val == "TestValue");
        rb_funcall(model.self, rb_intern("abort_operation"), 0);
    )

    // --- Operations ---

    MODEL_TEST_CASE("start_operation / abort_operation",
        rb_funcall(model.self, rb_intern("start_operation"), 4,
            rb_str_new_cstr("Test Op"), Qtrue, Qfalse, Qtrue);
        rb_funcall(model.self, rb_intern("abort_operation"), 0);
    )

    MODEL_TEST_CASE("start_operation / commit_operation",
        rb_funcall(model.self, rb_intern("start_operation"), 4,
            rb_str_new_cstr("Test Op"), Qtrue, Qfalse, Qtrue);
        rb_funcall(model.self, rb_intern("commit_operation"), 0);
    )

    // --- Observer add/remove ---

    TEST_CASE("ModelObserver add/remove and transaction callback") {
        struct TestModelObserver : Sketchup::ModelObserver {
        public:
            int transaction_start_count = 0;
            void onTransactionStart(Sketchup::Model model) override {
                transaction_start_count++;
            }
        };

        std::shared_ptr<TestModelObserver> obs = std::make_shared<TestModelObserver>();
        SketchUpCppAPI::protect([&]() {
            std::optional<Sketchup::Model> model = Sketchup::active_model();
            if (!model) return;

            bool added = model->add_observer(obs);
            CHECK(added);
            CHECK(obs->self != Qnil);

            // Trigger onTransactionStart
            rb_funcall(model->self, rb_intern("start_operation"), 4,
                rb_str_new_cstr("Observer Test"), Qtrue, Qfalse, Qtrue);
            rb_funcall(model->self, rb_intern("abort_operation"), 0);

            CHECK(obs->transaction_start_count == 1);

            bool removed = model->remove_observer(obs);
            CHECK(removed);

            // After removal, callback should not fire
            rb_funcall(model->self, rb_intern("start_operation"), 4,
                rb_str_new_cstr("Observer Test 2"), Qtrue, Qfalse, Qtrue);
            rb_funcall(model->self, rb_intern("abort_operation"), 0);

            CHECK(obs->transaction_start_count == 1);
        });
    }

    TEST_CASE("ModelObserver selective registration") {
        struct SelectiveObserver : Sketchup::ModelObserver {
        public:
            void onTransactionStart(Sketchup::Model model) override {}
        };

        std::shared_ptr<SelectiveObserver> obs = std::make_shared<SelectiveObserver>();
        SketchUpCppAPI::protect([&]() {
            std::optional<Sketchup::Model> model = Sketchup::active_model();
            if (!model) return;

            model->add_observer(obs);

            // Should respond to the overridden method
            CHECK(RTEST(rb_funcall(obs->self, rb_intern("respond_to?"), 1,
                ID2SYM(rb_intern("onTransactionStart")))));

            // Should NOT respond to methods that were not overridden
            CHECK_FALSE(RTEST(rb_funcall(obs->self, rb_intern("respond_to?"), 1,
                ID2SYM(rb_intern("onTransactionCommit")))));
            CHECK_FALSE(RTEST(rb_funcall(obs->self, rb_intern("respond_to?"), 1,
                ID2SYM(rb_intern("onDeleteModel")))));

            model->remove_observer(obs);
        });
    }

} // TEST_SUITE("Sketchup::Model")
