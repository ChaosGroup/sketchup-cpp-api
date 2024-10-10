#pragma once

#include "macros.hpp"

class DefinitionsObserver : public Makable<char>, public RubyUtils::details::NamedRubyWrapper<"Sketchup::DefinitionsObserver">
{
	public:
	/**
	 * @brief Defines aliases for the bitmask codes of each of the available methods
	 *
	 */
	enum : bitmask_t
	{
		ON_COMPONENT_ADDED = 1<<0,
		ON_COMPONENT_PROPERTIES_CHANGED = 1<<1,
		ON_COMPONENT_REMOVED = 1<<2,
		ON_COMPONENT_TYPE_CHANGED = 1<<3
	};

	/**
	 * @brief Destroy the Entities Observer object
	 *
	 */
	virtual ~DefinitionsObserver() = default;
		
	INIT_HANDLER_FOR_EVENT(DefinitionsObserver, onComponentAdded, void, (Sketchup::DefinitionList definitions, Sketchup::ComponentDefinition definition), (VALUE self, VALUE definitions, VALUE definition), (definitions, definition))	
	INIT_HANDLER_FOR_EVENT(DefinitionsObserver, onComponentPropertiesChanged, void, (Sketchup::DefinitionList definitions, Sketchup::ComponentDefinition definition), (VALUE self, VALUE definitions, VALUE definition), (definitions, definition))	
	INIT_HANDLER_FOR_EVENT(DefinitionsObserver, onComponentRemoved, void, (Sketchup::DefinitionList definitions, Sketchup::ComponentDefinition definition), (VALUE self, VALUE definitions, VALUE definition), (definitions, definition))	
	INIT_HANDLER_FOR_EVENT(DefinitionsObserver, onComponentTypeChanged, void, (Sketchup::DefinitionList definitions, Sketchup::ComponentDefinition definition), (VALUE self, VALUE definitions, VALUE definition), (definitions, definition))	
	
	protected:
	DefinitionsObserver(bitmask_t bitmask = 0) : Makable<bitmask_t>(bitmask)
	{ }
	
	private:
	inline void bind (VALUE self) final
	{
		this->value = self;
		ADD_HANDLER_FOR(DefinitionsObserver, onComponentAdded, ON_COMPONENT_ADDED)
		ADD_HANDLER_FOR(DefinitionsObserver, onComponentPropertiesChanged, ON_COMPONENT_PROPERTIES_CHANGED)
		ADD_HANDLER_FOR(DefinitionsObserver, onComponentRemoved, ON_COMPONENT_REMOVED)
		ADD_HANDLER_FOR(DefinitionsObserver, onComponentTypeChanged, ON_COMPONENT_TYPE_CHANGED)
	}

	template <typename T, typename... Args> friend std::shared_ptr<T> make_ruby(Args&&... args); // allowing to access bind(self) and EntityObserver()
};
