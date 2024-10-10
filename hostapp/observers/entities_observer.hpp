#pragma once

#include "macros.hpp"

class EntitiesObserver : public Makable<char>, public RubyUtils::details::NamedRubyWrapper<"Sketchup::EntitiesObserver">
{
	public:
	/**
	 * @brief Defines aliases for the bitmask codes of each of the available methods
	 *
	 */
	enum : bitmask_t
	{
		ON_ACTIVE_SECTION_PLANE_CHANGED = 1 << 0,
		ON_ERASE_ENTITIES = 1 << 1,
		ON_ELEMENT_ADDED = 1 << 2,
		ON_ELEMENT_MODIFIED = 1 << 3,
		ON_ELEMENT_REMOVED = 1 << 4
	};

	/**
	 * @brief Destroy the Entities Observer object
	 *
	 */
	virtual ~EntitiesObserver() = default;

	INIT_HANDLER_FOR_EVENT(EntitiesObserver, onActiveSectionPlaneChanged, void, (Sketchup::Entities entities), (VALUE self, VALUE entities), (entities))
	INIT_HANDLER_FOR_EVENT(EntitiesObserver, onEraseEntities, void, (Sketchup::Entities entities), (VALUE self, VALUE entities), (entities))
	INIT_HANDLER_FOR_EVENT(EntitiesObserver, onElementAdded, void, (Sketchup::Entities entities, Sketchup::Entity entity), (VALUE self, VALUE entities, VALUE entity), (entities, entity))
	INIT_HANDLER_FOR_EVENT(EntitiesObserver, onElementModified, void, (Sketchup::Entities entities, Sketchup::Entity entity), (VALUE self, VALUE entities, VALUE entity), (entities, entity))
	INIT_HANDLER_FOR_EVENT(EntitiesObserver, onElementRemoved, void, (Sketchup::Entities entities, unsigned long entity_id), (VALUE self, VALUE entities, VALUE entity_id), (entities, RubyUtils::details::IObject::ruby_to_cpp<unsigned long>(entity_id)))
	
	protected:
	EntitiesObserver(bitmask_t bitmask = 0) : Makable<bitmask_t>(bitmask)
	{ }
	
	private:
	inline void bind (VALUE self) final
	{
		this->value = self;
		ADD_HANDLER_FOR(EntitiesObserver, onActiveSectionPlaneChanged, ON_ACTIVE_SECTION_PLANE_CHANGED)
		ADD_HANDLER_FOR(EntitiesObserver, onEraseEntities, ON_ERASE_ENTITIES)
		ADD_HANDLER_FOR(EntitiesObserver, onElementAdded, ON_ELEMENT_ADDED)
		ADD_HANDLER_FOR(EntitiesObserver, onElementModified, ON_ELEMENT_MODIFIED)
		ADD_HANDLER_FOR(EntitiesObserver, onElementRemoved, ON_ELEMENT_REMOVED)
	}

	template <typename T, typename... Args> friend std::shared_ptr<T> make_ruby(Args&&... args); // allowing to access bind(self) and EntitiesObserver()
};
