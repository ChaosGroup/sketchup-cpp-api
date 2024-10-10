#pragma once

#include "macros.hpp"

class EntityObserver : public Makable<char>, public RubyUtils::details::NamedRubyWrapper<"Sketchup::EntityObserver">
{
	public:
	/**
	 * @brief Defines aliases for the bitmask codes of each of the available methods
	 *
	 */
	enum : bitmask_t
	{
		ON_CHANGE_ENTITY = 1<<0,
		ON_ERASE_ENTITY = 1<<1
	};

	/**
	 * @brief Destroy the Entities Observer object
	 *
	 */
	virtual ~EntityObserver() = default;
		
	INIT_HANDLER_FOR_EVENT(EntityObserver, onChangeEntity, void, (Sketchup::Entity entity), (VALUE self, VALUE entity), (entity))	
	INIT_HANDLER_FOR_EVENT(EntityObserver, onEraseEntity, void, (Sketchup::Entity entity), (VALUE self, VALUE entity), (entity))
	
	protected:
	EntityObserver(bitmask_t bitmask = 0) : Makable<bitmask_t>(bitmask)
	{ }
	
	private:
	inline void bind (VALUE self) final
	{
		this->value = self;
		ADD_HANDLER_FOR(EntityObserver, onChangeEntity, ON_CHANGE_ENTITY)
		ADD_HANDLER_FOR(EntityObserver, onEraseEntity, ON_ERASE_ENTITY)
	}

	template <typename T, typename... Args> friend std::shared_ptr<T> make_ruby(Args&&... args); // allowing to access bind(self) and EntityObserver()
};
