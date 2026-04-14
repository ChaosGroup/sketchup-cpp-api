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
