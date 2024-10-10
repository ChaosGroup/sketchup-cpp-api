#pragma once

class ExportOptionSet : public cpp_utils::DummyClass
{
	public:
	using show_summary = RubyUtils::Key<"show_summary", bool>;

	struct Max3DS : public cpp_utils::DummyClass
	{
		/**
		 * @brief values: "model", "inch", "foot", "yard", "mile", "mm", "cm", "m", or "km"
		 *
		 */
		using units = RubyUtils::Key<"units", std::string>;

		/**
		 * @brief values: "full_hierarchy", "by_layer", "by_material", or "single_object"
		 *
		 */
		using geometry = RubyUtils::Key<"geometry", std::string>;

		using doublesided_faces = RubyUtils::Key<"doublesided_faces", bool>;

		/**
		 * @brief values:  "not_two_sided", "two_sided_as_material", "two_sided_as_geometry"
		 *
		 */
		using faces = RubyUtils::Key<"faces", std::string>;

		using edges = RubyUtils::Key<"edges", bool>;

		using texture_maps = RubyUtils::Key<"texture_maps", bool>;

		using preserve_texture_coords = RubyUtils::Key<"preserve_texture_coords", bool>;

		using cameras = RubyUtils::Key<"cameras", bool>;

		using selectionset_only = RubyUtils::Key<"selectionset_only", bool>;
	};

	struct Collada : public cpp_utils::DummyClass
	{
		using triangulated_faces = RubyUtils::Key<"triangulated_faces", bool>;

		using doublesided_faces = RubyUtils::Key<"doublesided_faces", bool>;

		using edges = RubyUtils::Key<"edges", bool>;

		using author_attribution = RubyUtils::Key<"author_attribution", bool>;

		using hidden_geometry = RubyUtils::Key<"hidden_geometry", bool>;

		using preserve_instancing = RubyUtils::Key<"preserve_instancing", bool>;

		using texture_maps = RubyUtils::Key<"texture_maps", bool>;

		using selectionset_only = RubyUtils::Key<"selectionset_only", bool>;

		using camera_lookat = RubyUtils::Key<"camera_lookat", bool>;
	};

	struct Autocad3D : public cpp_utils::DummyClass
	{
		/**
		 * @brief values: "acad_12", "acad_13", "acad_14", "acad_2000", "acad_2004", "acad_2007", "acad_2010", "acad_2013"
		 *
		 */
		using acad_version = RubyUtils::Key<"acad_version", std::string>;

		using faces_flag = RubyUtils::Key<"faces_flag", bool>;

		using construction_geometry = RubyUtils::Key<"construction_geometry", bool>;

		using dimensions = RubyUtils::Key<"dimensions", bool>;

		using text = RubyUtils::Key<"text", bool>;

		using edges = RubyUtils::Key<"edges", bool>;
	};

	struct FilmboxAutodesk : public cpp_utils::DummyClass
	{
		/**
		 * @brief values: "model", "inch", "foot", "yard", "mile", "mm", "cm", "m" or "km"
		 *
		 */
		using units = RubyUtils::Key<"units", std::string>;

		using triangulated_faces = RubyUtils::Key<"triangulated_faces", bool>;

		using doublesided_faces = RubyUtils::Key<"doublesided_faces", bool>;

		using texture_maps = RubyUtils::Key<"texture_maps", bool>;

		using seperate_disconnected_faces = RubyUtils::Key<"seperate_disconnected_faces", bool>;

		using swap_yz = RubyUtils::Key<"swap_yz", bool>;

		using selectionset_only = RubyUtils::Key<"selectionset_only", bool>;
	};

	struct IndustryFoundationClasses : public cpp_utils::DummyClass
	{
		using hidden_geometry = RubyUtils::Key<"hidden_geometry", bool>;

		using doublesided_faces = RubyUtils::Key<"doublesided_faces", bool>;

		using ifc_mapped_items = RubyUtils::Key<"ifc_mapped_items", bool>;

		/**
		 * @brief values: "IfcNonDefined", "IfcBeam", "IfcBuilding", "IfcBuildingElementProxy", "IfcBuildingStorey", "IfcColumn", "IfcCurtainWall", "IfcDoor",
		 * "IfcFooting", "IfcFurnishingElement", "IfcMember", "IfcPile", "IfcPlate", "IfcProject", "IfcRailing", "IfcRamp", "IfcRampFlight", "IfcRoof",
		 * "IfcSite", "IfcSlab", "IfcSpace", "IfcStair", "IfcStairFlight", "IfcWall", "IfcWallStandardCase", "IfcWindow"
		 *
		 */
		using ifc_types = RubyUtils::Key<"ifc_types", RubyUtils::Enumerable<std::string>>;
	};

	struct GoogleEarth : public cpp_utils::DummyClass
	{
		using author_attribution = RubyUtils::Key<"author_attribution", bool>;

		using hidden_geometry = RubyUtils::Key<"hidden_geometry", bool>;
	};

	struct OBJ : public cpp_utils::DummyClass
	{
		/**
		 * @brief values: "model", "inch", "foot", "yard", "mile", "mm", "cm", "m", or "km"
		 *
		 */
		using units = RubyUtils::Key<"units", std::string>;

		using triangulated_faces = RubyUtils::Key<"triangulated_faces", bool>;

		using doublesided_faces = RubyUtils::Key<"doublesided_faces", bool>;

		using edges = RubyUtils::Key<"edges", bool>;

		using texture_maps = RubyUtils::Key<"texture_maps", bool>;

		using swap_yz = RubyUtils::Key<"swap_yz", bool>;

		using selectionset_only = RubyUtils::Key<"selectionset_only", bool>;
	};

	struct SoftimageXSI3DImage : public cpp_utils::DummyClass
	{
		/**
		 * @brief "model", "inch", "foot", "yard", "mile", "mm", "cm", "m", or "km"
		 *
		 */
		using units = RubyUtils::Key<"units", std::string>;

		using triangulated_faces = RubyUtils::Key<"triangulated_faces", bool>;

		using doublesided_faces = RubyUtils::Key<"doublesided_faces", bool>;

		using edges = RubyUtils::Key<"edges", bool>;

		using texture_maps = RubyUtils::Key<"texture_maps", bool>;

		using swap_yz = RubyUtils::Key<"swap_yz", bool>;

		using selectionset_only = RubyUtils::Key<"selectionset_only", bool>;
	};

	struct VirtualRealityModelingLanguage : public cpp_utils::DummyClass
	{
		using doublesided_faces = RubyUtils::Key<"doublesided_faces", bool>;

		using cameras = RubyUtils::Key<"cameras", bool>;

		using use_vrml_orientation = RubyUtils::Key<"use_vrml_orientation", bool>;

		using edges = RubyUtils::Key<"edges", bool>;

		using texture_maps = RubyUtils::Key<"texture_maps", bool>;

		using allow_mirrored_components = RubyUtils::Key<"allow_mirrored_components", bool>;

		using material_override = RubyUtils::Key<"material_override", bool>;
	};

	struct PDF : public cpp_utils::DummyClass
	{
		struct Windows : public cpp_utils::DummyClass
		{
			using output_profile_lines = RubyUtils::Key<"output_profile_lines", bool>;

			using output_section_lines = RubyUtils::Key<"output_section_lines", bool>;

			using edge_extensions = RubyUtils::Key<"edge_extensions", bool>;

			using match_screen_profiles = RubyUtils::Key<"match_screen_profiles", bool>;

			using match_screen_section = RubyUtils::Key<"match_screen_section", bool>;

			using match_screen_extensions = RubyUtils::Key<"match_screen_extensions", bool>;

			using full_scale = RubyUtils::Key<"full_scale", bool>;

			using map_fonts = RubyUtils::Key<"map_fonts", bool>;

			using drawing_units = RubyUtils::Key<"drawing_units", int>;

			using extension_units = RubyUtils::Key<"extension_units", int>;

			using height_units = RubyUtils::Key<"height_units", int>;

			using model_units = RubyUtils::Key<"model_units", int>;

			using width_units = RubyUtils::Key<"width_units", int>;

			using extension_length = RubyUtils::Key<"extension_length", double>;

			using line_width = RubyUtils::Key<"line_width", double>;

			using line_width_section = RubyUtils::Key<"line_width_section", double>;

			using length_in_drawing = RubyUtils::Key<"length_in_drawing", double>;

			using length_in_model = RubyUtils::Key<"length_in_model", double>;

			using window_height = RubyUtils::Key<"window_height", double>;
		};
		struct Mac : public cpp_utils::DummyClass
		{
			using line_weight = RubyUtils::Key<"line_weight", double>;

			using imageWidth = RubyUtils::Key<"imageWidth", int>;

			using imageHeight = RubyUtils::Key<"imageHeight", int>;
		};
	};

	struct STereoLithography : public cpp_utils::DummyClass
	{
		/**
		 * @brief values: "model", "inch", "feet", "mm", "cm", "m"
		 *
		 */
		using units = RubyUtils::Key<"units", std::string>;

		/**
		 * @brief values: "ascii", "binary"
		 *
		 */
		using format = RubyUtils::Key<"format", std::string>;

		using selectionset_only = RubyUtils::Key<"selectionset_only", bool>;

		using swap_yz = RubyUtils::Key<"swap_yz", bool>;
	};
};

// As a lot of keys are duplicated in different contexts, here is a list of all option keys without duplicates
class ExportOptions : public RubyUtils::Hash<
						  Sketchup::ExportOptionSet::Autocad3D::acad_version,
						  Sketchup::ExportOptionSet::Autocad3D::construction_geometry,
						  Sketchup::ExportOptionSet::Autocad3D::dimensions,
						  Sketchup::ExportOptionSet::Autocad3D::faces_flag,
						  Sketchup::ExportOptionSet::Autocad3D::text,
						  Sketchup::ExportOptionSet::Collada::author_attribution,
						  Sketchup::ExportOptionSet::Collada::camera_lookat,
						  Sketchup::ExportOptionSet::Collada::hidden_geometry,
						  Sketchup::ExportOptionSet::Collada::preserve_instancing,
						  Sketchup::ExportOptionSet::Collada::triangulated_faces,
						  Sketchup::ExportOptionSet::FilmboxAutodesk::seperate_disconnected_faces,
						  Sketchup::ExportOptionSet::FilmboxAutodesk::swap_yz,
						  Sketchup::ExportOptionSet::IndustryFoundationClasses::ifc_mapped_items,
						  Sketchup::ExportOptionSet::IndustryFoundationClasses::ifc_types,
						  Sketchup::ExportOptionSet::Max3DS::cameras,
						  Sketchup::ExportOptionSet::Max3DS::doublesided_faces,
						  Sketchup::ExportOptionSet::Max3DS::edges,
						  Sketchup::ExportOptionSet::Max3DS::faces,
						  Sketchup::ExportOptionSet::Max3DS::geometry,
						  Sketchup::ExportOptionSet::Max3DS::preserve_texture_coords,
						  Sketchup::ExportOptionSet::Max3DS::selectionset_only,
						  Sketchup::ExportOptionSet::Max3DS::texture_maps,
						  Sketchup::ExportOptionSet::Max3DS::units,
						  Sketchup::ExportOptionSet::PDF::Mac::imageHeight,
						  Sketchup::ExportOptionSet::PDF::Mac::imageWidth,
						  Sketchup::ExportOptionSet::PDF::Mac::line_weight,
						  Sketchup::ExportOptionSet::PDF::Windows::drawing_units,
						  Sketchup::ExportOptionSet::PDF::Windows::edge_extensions,
						  Sketchup::ExportOptionSet::PDF::Windows::extension_length,
						  Sketchup::ExportOptionSet::PDF::Windows::extension_units,
						  Sketchup::ExportOptionSet::PDF::Windows::full_scale,
						  Sketchup::ExportOptionSet::PDF::Windows::height_units,
						  Sketchup::ExportOptionSet::PDF::Windows::length_in_drawing,
						  Sketchup::ExportOptionSet::PDF::Windows::length_in_model,
						  Sketchup::ExportOptionSet::PDF::Windows::line_width,
						  Sketchup::ExportOptionSet::PDF::Windows::line_width_section,
						  Sketchup::ExportOptionSet::PDF::Windows::map_fonts,
						  Sketchup::ExportOptionSet::PDF::Windows::match_screen_extensions,
						  Sketchup::ExportOptionSet::PDF::Windows::match_screen_profiles,
						  Sketchup::ExportOptionSet::PDF::Windows::match_screen_section,
						  Sketchup::ExportOptionSet::PDF::Windows::model_units,
						  Sketchup::ExportOptionSet::PDF::Windows::output_profile_lines,
						  Sketchup::ExportOptionSet::PDF::Windows::output_section_lines,
						  Sketchup::ExportOptionSet::PDF::Windows::width_units,
						  Sketchup::ExportOptionSet::PDF::Windows::window_height,
						  Sketchup::ExportOptionSet::STereoLithography::format,
						  Sketchup::ExportOptionSet::VirtualRealityModelingLanguage::allow_mirrored_components,
						  Sketchup::ExportOptionSet::VirtualRealityModelingLanguage::material_override,
						  Sketchup::ExportOptionSet::VirtualRealityModelingLanguage::use_vrml_orientation,
						  Sketchup::ExportOptionSet::show_summary>
{
};
