#pragma once

// https://ruby.sketchup.com/Sketchup/Material.html
class Material;

// https://ruby.sketchup.com/Sketchup/Materials.html
class Materials;

// hhttps://ruby.sketchup.com/file.exporter_options.html
class ExportOptionSet;
class ExportOptions;

// https://ruby.sketchup.com/Sketchup/Model.html
class Model;

// https://ruby.sketchup.com/Sketchup/Entity.html
class Entity;

// https://ruby.sketchup.com/Sketchup/DefinitionList.html
class DefinitionList;

// https://ruby.sketchup.com/Sketchup/Entities.html
class Entities;

// https://ruby.sketchup.com/Sketchup/EntitiesObserver.html
class EntitiesObserver;

// https://ruby.sketchup.com/Sketchup/ModelObserver.html
class ModelObserver;

// https://ruby.sketchup.com/Sketchup/EntityObserver.html
class EntityObserver;

// https://ruby.sketchup.com/Sketchup/DefinitionsObserver.html
class DefinitionsObserver;

// https://ruby.sketchup.com/Sketchup/MaterialsObserver.html
class MaterialsObserver;

#include "material.hpp"

#include "materials.hpp"

#include "export_options.hpp"

#include "model.hpp"

#include "entity.hpp"

#include "definition_list.hpp"

#include "entities.hpp"

#include "observers/makable_interface.hpp"

#include "observers/entities_observer.hpp"

#include "observers/model_observer.hpp"

#include "observers/entity_observer.hpp"

#include "observers/definitions_observer.hpp"

#include "observers/materials_observer.hpp"
