#pragma once

#include "macros.hpp"

class ModelObserver : public Makable<int>, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ModelObserver">
{
	public:
	/**
	 * @brief Defines aliases for the bitmask codes of each of the available methods
	 *
	 */
	enum : bitmask_t
	{
		ON_ACTIVE_PATH_CHANGED = 1<<0,
		ON_AFTER_COMPONENT_SAVE_AS = 1<<1,
		ON_BEFORE_COMPONENT_SAVE_AS = 1<<2,
		ON_DELETE_MODEL = 1<<3,
		ON_ERASE_ALL = 1<<4,
		ON_EXPLODE = 1<<5,
		ON_PLACE_COMPONENT = 1<<6,
		ON_POST_SAVE_MODEL = 1<<7,
		ON_PRE_SAVE_MODEL = 1<<8,
		ON_SAVE_MODEL = 1<<9,
		ON_TRANSACTION_ABORT = 1<<10,
		ON_TRANSACTION_COMMIT = 1<<11,
		ON_TRANSACTION_EMPTY = 1<<12,
		ON_TRANSACTION_REDO = 1<<13,
		ON_TRANSACTION_START = 1<<14,
		ON_TRANSACTION_UNDO = 1<<15,
		ON_PID_CHANGED = 1<<16,
	};

	/**
	 * @brief Destroy the Entities Observer object
	 *
	 */
	virtual ~ModelObserver() = default;
		
	INIT_HANDLER_FOR_EVENT(ModelObserver, onActivePathChanged, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onAfterComponentSaveAs, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onBeforeComponentSaveAs, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onDeleteModel, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onEraseAll, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onExplode, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onPlaceComponent, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onPostSaveModel, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onPreSaveModel, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onSaveModel, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onTransactionAbort, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onTransactionCommit, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onTransactionEmpty, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onTransactionRedo, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onTransactionStart, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onTransactionUndo, void, (Sketchup::Model model), (VALUE self, VALUE model), (model))
	INIT_HANDLER_FOR_EVENT(ModelObserver, onPidChanged, void, (Sketchup::Model model, int old_pid, int new_pid), (VALUE self, VALUE model, VALUE old_pid, VALUE new_pid), (model, RubyUtils::details::IObject::ruby_to_cpp<int>(old_pid), RubyUtils::details::IObject::ruby_to_cpp<int>(new_pid)))

	protected:
	ModelObserver(bitmask_t bitmask = 0) : Makable<bitmask_t>(bitmask)
	{ }
	
	private:
	inline void bind (VALUE self) final
	{
		this->value = self;
		ADD_HANDLER_FOR(ModelObserver, onActivePathChanged, ON_ACTIVE_PATH_CHANGED)
		ADD_HANDLER_FOR(ModelObserver, onAfterComponentSaveAs, ON_AFTER_COMPONENT_SAVE_AS)
		ADD_HANDLER_FOR(ModelObserver, onBeforeComponentSaveAs, ON_BEFORE_COMPONENT_SAVE_AS)
		ADD_HANDLER_FOR(ModelObserver, onDeleteModel, ON_DELETE_MODEL)
		ADD_HANDLER_FOR(ModelObserver, onEraseAll, ON_ERASE_ALL)
		ADD_HANDLER_FOR(ModelObserver, onExplode, ON_EXPLODE)
		ADD_HANDLER_FOR(ModelObserver, onPlaceComponent, ON_PLACE_COMPONENT)
		ADD_HANDLER_FOR(ModelObserver, onPostSaveModel, ON_POST_SAVE_MODEL)
		ADD_HANDLER_FOR(ModelObserver, onPreSaveModel, ON_PRE_SAVE_MODEL)
		ADD_HANDLER_FOR(ModelObserver, onSaveModel, ON_SAVE_MODEL)
		ADD_HANDLER_FOR(ModelObserver, onTransactionAbort, ON_TRANSACTION_ABORT)
		ADD_HANDLER_FOR(ModelObserver, onTransactionCommit, ON_TRANSACTION_COMMIT)
		ADD_HANDLER_FOR(ModelObserver, onTransactionEmpty, ON_TRANSACTION_EMPTY)
		ADD_HANDLER_FOR(ModelObserver, onTransactionRedo, ON_TRANSACTION_REDO)
		ADD_HANDLER_FOR(ModelObserver, onTransactionStart, ON_TRANSACTION_START)
		ADD_HANDLER_FOR(ModelObserver, onTransactionUndo, ON_TRANSACTION_UNDO)
		ADD_HANDLER_FOR(ModelObserver, onPidChanged, ON_PID_CHANGED)
	}

	template <typename T, typename... Args> friend std::shared_ptr<T> make_ruby(Args&&... args); // allowing to access bind(self) and ModelObserver()
};
