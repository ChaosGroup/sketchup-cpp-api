#pragma once

#include "macros.hpp"

class MaterialsObserver : public Makable<char>
{
	public:
	/**
	 * @brief Defines aliases for the bitmask codes of each of the available methods
	 *
	 */
	enum : bitmask_t
	{
		ON_MATERIAL_ADD = 1 << 0,
		ON_MATERIAL_CHANGE = 1 << 1,
		ON_MATERIAL_REF_CHANGE = 1 << 2,
		ON_MATERIAL_REMOVE = 1 << 3,
		ON_MATERIAL_SET_CURRENT = 1 << 4,
		ON_MATERIAL_UNDO_REDO = 1 << 5,
	};

	/**
	 * @brief Destroy the Entities Observer object
	 *
	 */
	virtual ~MaterialsObserver() = default;

	INIT_HANDLER_FOR_EVENT(MaterialsObserver, onMaterialAdd, void, (Sketchup::Materials materials, Sketchup::Material material), (VALUE self, VALUE materials, VALUE material), (materials, material))
	INIT_HANDLER_FOR_EVENT(MaterialsObserver, onMaterialChange, void, (Sketchup::Materials materials, Sketchup::Material material), (VALUE self, VALUE materials, VALUE material), (materials, material))
	INIT_HANDLER_FOR_EVENT(MaterialsObserver, onMaterialRefChange, void, (Sketchup::Materials materials, Sketchup::Material material), (VALUE self, VALUE materials, VALUE material), (materials, material))
	INIT_HANDLER_FOR_EVENT(MaterialsObserver, onMaterialRemove, void, (Sketchup::Materials materials, Sketchup::Material material), (VALUE self, VALUE materials, VALUE material), (materials, material))
	INIT_HANDLER_FOR_EVENT(MaterialsObserver, onMaterialSetCurrent, void, (Sketchup::Materials materials, Sketchup::Material material), (VALUE self, VALUE materials, VALUE material), (materials, material))
	INIT_HANDLER_FOR_EVENT(MaterialsObserver, onMaterialUndoRedo, void, (Sketchup::Materials materials, Sketchup::Material material), (VALUE self, VALUE materials, VALUE material), (materials, material))
	
	protected:
	MaterialsObserver(bitmask_t bitmask = 0) : Makable<bitmask_t>(bitmask)
	{ }
	
	private:
	inline void bind (VALUE self) final
	{
		this->value = self;
		ADD_HANDLER_FOR(MaterialsObserver, onMaterialAdd, ON_MATERIAL_ADD)
		ADD_HANDLER_FOR(MaterialsObserver, onMaterialChange, ON_MATERIAL_CHANGE)
		ADD_HANDLER_FOR(MaterialsObserver, onMaterialRefChange, ON_MATERIAL_REF_CHANGE)
		ADD_HANDLER_FOR(MaterialsObserver, onMaterialRemove, ON_MATERIAL_REMOVE)
		ADD_HANDLER_FOR(MaterialsObserver, onMaterialSetCurrent, ON_MATERIAL_SET_CURRENT)
		ADD_HANDLER_FOR(MaterialsObserver, onMaterialUndoRedo, ON_MATERIAL_UNDO_REDO)
	}

	template <typename T, typename... Args> friend std::shared_ptr<T> make_ruby(Args&&... args); // allowing to access bind(self) and MaterialsObserver()
};
