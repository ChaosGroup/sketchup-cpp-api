namespace HostApp
{

	inline Sketchup::Entities::Entities(VALUE obj) : RubyUtils::Enumerable<Sketchup::Entity>(obj)
	{
	}
	inline Sketchup::Entities::Entities(const Entities& obj) : RubyUtils::Enumerable<Sketchup::Entity>((RubyUtils::details::IObject)obj)
	{
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#[]-instance_method
	 *
	 * @param entity_index read https://ruby.sketchup.com/Sketchup/Entities.html#[]-instance_method
	 * @return RubyUtils::optional<Sketchup::Entity> read https://ruby.sketchup.com/Sketchup/Entities.html#[]-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::optional<Sketchup::Entity>, operator[], (long long entity_index), [], entity_index)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#active_section_plane-instance_method
	 *
	 * @return RubyUtils::optional<Sketchup::SectionPlane> read https://ruby.sketchup.com/Sketchup/Entities.html#active_section_plane-instance_method
	 * @min_version SketchUp 2014
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, RubyUtils::optional<Sketchup::SectionPlane>, active_section_plane, active_section_plane)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#active_section_plane=-instance_method
	 *
	 * @param sec_plane read https://ruby.sketchup.com/Sketchup/Entities.html#active_section_plane=-instance_method
	 * @return RubyUtils::optional<Sketchup::SectionPlane> read https://ruby.sketchup.com/Sketchup/Entities.html#active_section_plane=-instance_method
	 * @min_version SketchUp 2014
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::optional<Sketchup::SectionPlane>, set_active_section_plane, (RubyUtils::optional<Sketchup::SectionPlane> sec_plane), active_section_plane=, sec_plane)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 *
	 * @param string read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param alignment read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param font read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param is_bold read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param is_italic read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param letter_height read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param tolerance read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param z read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param is_filled read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @param extrusion read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entities.html#add_3d_text-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, bool, add_3d_text, (std::string string, long long alignment, std::string font, bool is_bold, bool is_italic, Length letter_height, double tolerance, Length z, bool is_filled, Length extrusion), add_3d_text, string, alignment, font, is_bold, is_italic, letter_height, tolerance, z, is_filled, extrusion)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 *
	 * @param center read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param xaxis read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param normal read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param radius read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param start_angle read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param end_angle read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_arc, (Geom::Point3d center, Geom::Vector3d xaxis, Geom::Vector3d normal, double radius, double start_angle, double end_angle), add_arc, center, xaxis, normal, radius, start_angle, end_angle)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 *
	 * @param center read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param xaxis read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param normal read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param radius read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param start_angle read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param end_angle read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @param num_segments read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_arc-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_arc, (Geom::Point3d center, Geom::Vector3d xaxis, Geom::Vector3d normal, double radius, double start_angle, double end_angle, long long num_segments), add_arc, center, xaxis, normal, radius, start_angle, end_angle, num_segments)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_circle-instance_method
	 *
	 * @param center read https://ruby.sketchup.com/Sketchup/Entities.html#add_circle-instance_method
	 * @param normal read https://ruby.sketchup.com/Sketchup/Entities.html#add_circle-instance_method
	 * @param radius read https://ruby.sketchup.com/Sketchup/Entities.html#add_circle-instance_method
	 * @param numsegs read https://ruby.sketchup.com/Sketchup/Entities.html#add_circle-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_circle-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_circle, (Geom::Point3d center, Geom::Vector3d normal, double radius, long long numsegs), add_circle, center, normal, radius, numsegs)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 *
	 * @param point read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @param vector read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @param stipple read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @return Sketchup::ConstructionLine read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::ConstructionLine, add_cline, (Geom::Point3d point, Geom::Vector3d vector, std::string stipple), add_cline, point, vector, stipple)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 *
	 * @param start_point read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @param end_point read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @param stipple read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @return Sketchup::ConstructionLine read https://ruby.sketchup.com/Sketchup/Entities.html#add_cline-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::ConstructionLine, add_cline, (Geom::Point3d start_point, Geom::Point3d end_point, std::string stipple), add_cline, start_point, end_point, stipple)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_cpoint-instance_method
	 *
	 * @param point read https://ruby.sketchup.com/Sketchup/Entities.html#add_cpoint-instance_method
	 * @return Sketchup::ConstructionPoint read https://ruby.sketchup.com/Sketchup/Entities.html#add_cpoint-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::ConstructionPoint, add_cpoint, (Geom::Point3d point), add_cpoint, point)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_curve-instance_method
	 *
	 * @params read https://ruby.sketchup.com/Sketchup/Entities.html#add_curve-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_curve-instance_method
	 * @min_version SketchUp 6.0
	 */
	template<typename... Ts, typename U>
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_curve, (Ts... points), add_curve, points...)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_curve-instance_method
	 *
	 * @param points read https://ruby.sketchup.com/Sketchup/Entities.html#add_curve-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_curve-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_curve, (RubyUtils::Enumerable<Geom::Point3d> points), add_curve, points)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 *
	 * @param start_array read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @param end_array read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @param offset_vector read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @return Sketchup::DimensionLinear read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @min_version SketchUp 2014
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::DimensionLinear, add_dimension_linear, (RubyUtils::Enumerable<RubyUtils::any_of<Sketchup::Entity, Geom::Point3d>> start_array, RubyUtils::Enumerable<RubyUtils::any_of<Sketchup::Entity, Geom::Point3d>> end_array, Geom::Vector3d offset_vector), add_dimension_linear, start_array, end_array, offset_vector)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 *
	 * @param start_instance_path read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @param end_instance_path read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @param offset_vector read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @return Sketchup::DimensionLinear read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::DimensionLinear, add_dimension_linear, (RubyUtils::Enumerable<RubyUtils::any_of<Sketchup::InstancePath, Geom::Point3d>> start_instance_path, RubyUtils::Enumerable<RubyUtils::any_of<Sketchup::InstancePath, Geom::Point3d>> end_instance_path, Geom::Vector3d offset_vector), add_dimension_linear, start_instance_path, end_instance_path, offset_vector)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 *
	 * @param start_pt_or_entity read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @param end_pt_or_entity read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @param offset_vector read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @return Sketchup::DimensionLinear read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_linear-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::DimensionLinear, add_dimension_linear, (RubyUtils::any_of<Geom::Point3d, Sketchup::Entity> start_pt_or_entity, RubyUtils::any_of<Geom::Point3d, Sketchup::Entity> end_pt_or_entity, Geom::Vector3d offset_vector), add_dimension_linear, start_pt_or_entity, end_pt_or_entity, offset_vector)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_radial-instance_method
	 *
	 * @param arc_curve read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_radial-instance_method
	 * @param leader_break_pt read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_radial-instance_method
	 * @return Sketchup::DimensionRadial read https://ruby.sketchup.com/Sketchup/Entities.html#add_dimension_radial-instance_method
	 * @min_version SketchUp 2014
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::DimensionRadial, add_dimension_radial, (Sketchup::ArcCurve arc_curve, Geom::Point3d leader_break_pt), add_dimension_radial, arc_curve, leader_break_pt)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_edges-instance_method
	 *
	 * @param *points read https://ruby.sketchup.com/Sketchup/Entities.html#add_edges-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_edges-instance_method
	 * @min_version SketchUp 6.0
	 */
	template<typename... Ts, typename Us>
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_edges, (Ts... points), add_edges, points...)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_edges-instance_method
	 *
	 * @param points read https://ruby.sketchup.com/Sketchup/Entities.html#add_edges-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_edges-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_edges, (RubyUtils::Enumerable<Geom::Point3d> points), add_edges, points)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_face-instance_method
	 *
	 * @param *entities read https://ruby.sketchup.com/Sketchup/Entities.html#add_face-instance_method
	 * @return RubyUtils::optional<Sketchup::Face> read https://ruby.sketchup.com/Sketchup/Entities.html#add_face-instance_method
	 * @min_version SketchUp 6.0
	 */
	template<typename... Ts, typename U>
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::optional<Sketchup::Face>, add_face, (Ts... entities), add_face, entities...)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_face-instance_method
	 *
	 * @param entities read https://ruby.sketchup.com/Sketchup/Entities.html#add_face-instance_method
	 * @return RubyUtils::optional<Sketchup::Face> read https://ruby.sketchup.com/Sketchup/Entities.html#add_face-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::optional<Sketchup::Face>, add_face, (RubyUtils::Enumerable<RubyUtils::any_of<RubyUtils::Enumerable<Sketchup::Edge>, RubyUtils::Enumerable<Geom::Point3d>, Sketchup::Curv>> entities), add_face, entities)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_faces_from_mesh-instance_method
	 *
	 * @param polygon_mesh read https://ruby.sketchup.com/Sketchup/Entities.html#add_faces_from_mesh-instance_method
	 * @param smooth_flags read https://ruby.sketchup.com/Sketchup/Entities.html#add_faces_from_mesh-instance_method
	 * @param f_material read https://ruby.sketchup.com/Sketchup/Entities.html#add_faces_from_mesh-instance_method
	 * @param b_material read https://ruby.sketchup.com/Sketchup/Entities.html#add_faces_from_mesh-instance_method
	 * @return long long read https://ruby.sketchup.com/Sketchup/Entities.html#add_faces_from_mesh-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, long long, add_faces_from_mesh, (Geom::PolygonMesh polygon_mesh, long long smooth_flags, RubyUtils::any_of<Sketchup::Material, std::string> f_material, RubyUtils::any_of<Sketchup::Material, std::string> b_material), add_faces_from_mesh, polygon_mesh, smooth_flags, f_material, b_material)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_group-instance_method
	 *
	 * @param *entities read https://ruby.sketchup.com/Sketchup/Entities.html#add_group-instance_method
	 * @return Sketchup::Group read https://ruby.sketchup.com/Sketchup/Entities.html#add_group-instance_method
	 * @min_version SketchUp 6.0
	 */
	template<typename... Ts, typename U>
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::Group, add_group, (Ts... entities), add_group, entities...)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_group-instance_method
	 *
	 * @param entities read https://ruby.sketchup.com/Sketchup/Entities.html#add_group-instance_method
	 * @return Sketchup::Group read https://ruby.sketchup.com/Sketchup/Entities.html#add_group-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::Group, add_group, (RubyUtils::Enumerable<Sketchup::Entity> entities), add_group, entities)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_image-instance_method
	 *
	 * @param path read https://ruby.sketchup.com/Sketchup/Entities.html#add_image-instance_method
	 * @param point read https://ruby.sketchup.com/Sketchup/Entities.html#add_image-instance_method
	 * @param width read https://ruby.sketchup.com/Sketchup/Entities.html#add_image-instance_method
	 * @param height read https://ruby.sketchup.com/Sketchup/Entities.html#add_image-instance_method
	 * @return RubyUtils::optional<Sketchup::Image> read https://ruby.sketchup.com/Sketchup/Entities.html#add_image-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::optional<Sketchup::Image>, add_image, (std::string path, Geom::Point3d point, double width, double height), add_image, path, point, width, height)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_instance-instance_method
	 *
	 * @param definition read https://ruby.sketchup.com/Sketchup/Entities.html#add_instance-instance_method
	 * @param transform read https://ruby.sketchup.com/Sketchup/Entities.html#add_instance-instance_method
	 * @return Sketchup::ComponentInstance read https://ruby.sketchup.com/Sketchup/Entities.html#add_instance-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::ComponentInstance, add_instance, (Sketchup::ComponentDefinition definition, Geom::Transformation transform), add_instance, definition, transform)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_line-instance_method
	 *
	 * @param point1 read https://ruby.sketchup.com/Sketchup/Entities.html#add_line-instance_method
	 * @param point2 read https://ruby.sketchup.com/Sketchup/Entities.html#add_line-instance_method
	 * @return Sketchup::Edge read https://ruby.sketchup.com/Sketchup/Entities.html#add_line-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::Edge, add_line, (Geom::Point3d point1, Geom::Point3d point2), add_line, point1, point2)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_ngon-instance_method
	 *
	 * @param center read https://ruby.sketchup.com/Sketchup/Entities.html#add_ngon-instance_method
	 * @param normal read https://ruby.sketchup.com/Sketchup/Entities.html#add_ngon-instance_method
	 * @param radius read https://ruby.sketchup.com/Sketchup/Entities.html#add_ngon-instance_method
	 * @param numsides read https://ruby.sketchup.com/Sketchup/Entities.html#add_ngon-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Edge> read https://ruby.sketchup.com/Sketchup/Entities.html#add_ngon-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Edge>, add_ngon, (Geom::Point3d center, Geom::Vector3d normal, double radius, long long numsides), add_ngon, center, normal, radius, numsides)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_observer-instance_method
	 *
	 * @param observer read https://ruby.sketchup.com/Sketchup/Entities.html#add_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entities.html#add_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, bool, add_observer, (Sketchup::EntitiesObserver observer), add_observer, observer)

	/**
	* @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_section_plane-instance_method
	*
	* @param plane read https://ruby.sketchup.com/Sketchup/Entities.html#add_section_plane-instance_method
	* @return RubyUtils::optional<Sketchup::SectionPlane> read https://ruby.sketchup.com/Sketchup/Entities.html#add_section_plane-instance_method
	* @min_version SketchUp 2014
	*/
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::optional<Sketchup::SectionPlane>, add_section_plane, (Geom::Point3d pt, Geom::Vector3d vec), add_section_plane, pt, vec)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#add_text-instance_method
	 *
	 * @param text read https://ruby.sketchup.com/Sketchup/Entities.html#add_text-instance_method
	 * @param instance_array_and_pt read https://ruby.sketchup.com/Sketchup/Entities.html#add_text-instance_method
	 * @param vector read https://ruby.sketchup.com/Sketchup/Entities.html#add_text-instance_method
	 * @return Sketchup::Text read https://ruby.sketchup.com/Sketchup/Entities.html#add_text-instance_method
	 * @min_version SketchUp 2019SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::Text, add_text, (std::string text, RubyUtils::tuple<Sketchup::InstancePath DEFINE_WRAPPED_METHOD_COMMA Geom::Point3d> instance_array_and_pt, Geom::Vector3d vector), add_text, text, instance_array_and_pt, vector)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#at-instance_method
	 *
	 * @param entity_index read https://ruby.sketchup.com/Sketchup/Entities.html#at-instance_method
	 * @return RubyUtils::optional<Sketchup::Entity> read https://ruby.sketchup.com/Sketchup/Entities.html#at-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::optional<Sketchup::Entity>, at, (long long entity_index), at, entity_index)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#build-instance_method
	 *
	 * @return void read https://ruby.sketchup.com/Sketchup/Entities.html#build-instance_method
	 * @min_version SketchUp 2022.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, void, build, build)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#clear!-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entities.html#clear!-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, bool, clear, clear!)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#count-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Entities.html#count-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, long long, count, count)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#each-instance_method
	 *
	 * @return void read https://ruby.sketchup.com/Sketchup/Entities.html#each-instance_method
	 * @min_version SketchUp 6.0
	 */
	inline Sketchup::Entities& Sketchup::Entities::each(std::function<void(Sketchup::Entity)> lambda) {
		RubyUtils::Enumerable<Sketchup::Entity>::each(lambda);
		return *this;
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#erase_entities-instance_method
	 *
	 * @param *entities read https://ruby.sketchup.com/Sketchup/Entities.html#erase_entities-instance_method
	 * @return void read https://ruby.sketchup.com/Sketchup/Entities.html#erase_entities-instance_method
	 * @min_version SketchUp 6.0Known Bugs:Prior to SketchUp 2023.0 this could crash SketchUp if you erased an instance used by the active edit path.SketchUp
	 * 2023.0 and SketchUp 2023.0.1 could incorrectly raise an `ArgumentError` when there was an open editing path.
	 */
	template<typename... Ts, typename U>
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, void, erase_entities, (Ts... entities), erase_entities, entities...)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#erase_entities-instance_method
	 *
	 * @param entities read https://ruby.sketchup.com/Sketchup/Entities.html#erase_entities-instance_method
	 * @return void read https://ruby.sketchup.com/Sketchup/Entities.html#erase_entities-instance_method
	 * @min_version
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, void, erase_entities, (RubyUtils::Enumerable<Sketchup::Entity> entities), erase_entities, entities)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#fill_from_mesh-instance_method
	 *
	 * @param polygon_mesh read https://ruby.sketchup.com/Sketchup/Entities.html#fill_from_mesh-instance_method
	 * @param weld_vertices read https://ruby.sketchup.com/Sketchup/Entities.html#fill_from_mesh-instance_method
	 * @param smooth_flags read https://ruby.sketchup.com/Sketchup/Entities.html#fill_from_mesh-instance_method
	 * @param f_material read https://ruby.sketchup.com/Sketchup/Entities.html#fill_from_mesh-instance_method
	 * @param b_material read https://ruby.sketchup.com/Sketchup/Entities.html#fill_from_mesh-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entities.html#fill_from_mesh-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, bool, fill_from_mesh, (Geom::PolygonMesh polygon_mesh, bool weld_vertices, long long smooth_flags, RubyUtils::any_of<Sketchup::Material, std::string> f_material, RubyUtils::any_of<Sketchup::Material, std::string> b_material), fill_from_mesh, polygon_mesh, weld_vertices, smooth_flags, f_material, b_material)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 *
	 * @param recurse read https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 * @param transform1 read https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 * @param entities1 read https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 * @param transform2 read https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 * @param hidden read https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 * @param entities2 read https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 * @return void read https://ruby.sketchup.com/Sketchup/Entities.html#intersect_with-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, void, intersect_with, (bool recurse, Geom::Transformation transform1, Sketchup::Entities entities1, Geom::Transformation transform2, bool hidden, RubyUtils::any_of<Sketchup::Entity, RubyUtils::Enumerable<Sketchup::Entity>> entities2), intersect_with, recurse, transform1, entities1, transform2, hidden, entities2)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#length-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Entities.html#length-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, long long, length, length)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#model-instance_method
	 *
	 * @return Sketchup::Model read https://ruby.sketchup.com/Sketchup/Entities.html#model-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, Sketchup::Model, model, model)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#parent-instance_method
	 *
	 * @return RubyUtils::any_of<Sketchup::ComponentDefinition, Sketchup::Model> read https://ruby.sketchup.com/Sketchup/Entities.html#parent-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, RubyUtils::any_of<Sketchup::ComponentDefinition DEFINE_WRAPPED_METHOD_COMMA Sketchup::Model>, parent, parent)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#remove_observer-instance_method
	 *
	 * @param observer read https://ruby.sketchup.com/Sketchup/Entities.html#remove_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entities.html#remove_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, bool, remove_observer, (Sketchup::EntitiesObserver observer), remove_observer, observer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#size-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/Entities.html#size-instance_method
	 * @min_version SketchUp 2014
	 */
	IMPLEMENT_WRAPPED_METHOD_0(Sketchup::Entities, long long, size, size)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#transform_by_vectors-instance_method
	 *
	 * @param sub_entities read https://ruby.sketchup.com/Sketchup/Entities.html#transform_by_vectors-instance_method
	 * @param vectors read https://ruby.sketchup.com/Sketchup/Entities.html#transform_by_vectors-instance_method
	 * @return Sketchup::Entities read https://ruby.sketchup.com/Sketchup/Entities.html#transform_by_vectors-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, Sketchup::Entities, transform_by_vectors, (RubyUtils::Enumerable<Sketchup::Entity> sub_entities, RubyUtils::Enumerable<Geom::Vector3d> vectors), transform_by_vectors, sub_entities, vectors)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#transform_entities-instance_method
	 *
	 * @param transform read https://ruby.sketchup.com/Sketchup/Entities.html#transform_entities-instance_method
	 * @param entities read https://ruby.sketchup.com/Sketchup/Entities.html#transform_entities-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/Entities.html#transform_entities-instance_method
	 * @min_version SketchUp 6.0
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, bool, transform_entities, (Geom::Transformation transform, RubyUtils::Enumerable<Sketchup::Entity> entities), transform_entities, transform, entities)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/Entities.html#weld-instance_method
	 *
	 * @param edges read https://ruby.sketchup.com/Sketchup/Entities.html#weld-instance_method
	 * @return RubyUtils::Enumerable<Sketchup::Curve> read https://ruby.sketchup.com/Sketchup/Entities.html#weld-instance_method
	 * @min_version SketchUp 2020.1
	 */
	IMPLEMENT_WRAPPED_METHOD(Sketchup::Entities, RubyUtils::Enumerable<Sketchup::Curve>, weld, (RubyUtils::Enumerable<Sketchup::Edge> edges), weld, edges)

} // namespace HostApp
