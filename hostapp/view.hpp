#pragma once

#include "../ruby/utils.hpp"
#include "macros.hpp"

class View : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::View">
{
public:
	 static constexpr int TextAlignLeft = 0;
	 static constexpr int TextAlignRight = 2;
	 static constexpr int TextAlignCenter = 1;
	 static constexpr int TextVerticalAlignBoundsTop = 0;
	 static constexpr int TextVerticalAlignBaseline = 1;
	 static constexpr int TextVerticalAlignCapHeight = 2;
	 static constexpr int TextVerticalAlignCenter = 3;

	 using DrawOptions = RubyUtils::Hash<
	 	 DrawOptionSet::normals,
	 	 DrawOptionSet::texture,
	 	 DrawOptionSet::uvs
	 >;

	 using Draw2dOptions = RubyUtils::Hash<
	 	 Draw2dOptionSet::texture,
	 	 Draw2dOptionSet::uvs
	 >;

	 using DrawTextOptions = RubyUtils::Hash<
	 	 DrawTextOptionSet::font,
	 	 DrawTextOptionSet::size,
	 	 DrawTextOptionSet::pixel_size,
	 	 DrawTextOptionSet::point_size,
	 	 DrawTextOptionSet::bold,
	 	 DrawTextOptionSet::italic,
	 	 DrawTextOptionSet::color,
	 	 DrawTextOptionSet::align,
	 	 DrawTextOptionSet::vertical_align
	 >;

	 using WriteImage1Options = RubyUtils::Hash<
	 	 WriteImageOptionSet::filename,
	 	 WriteImageOptionSet::width,
	 	 WriteImageOptionSet::height,
	 	 WriteImageOptionSet::scale_factor,
	 	 WriteImageOptionSet::antialias,
	 	 WriteImageOptionSet::compression,
	 	 WriteImageOptionSet::transparent
	 >;

	 using WriteImage2Options = RubyUtils::Hash<
	 	 WriteImageOptionSet::filename,
	 	 WriteImageOptionSet::source,
	 	 WriteImageOptionSet::compression
	 >;

	inline View(VALUE arg) : IObject(arg)
	{
	}

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#add_observer-instance_method
	 *
	 * @param observer read https://ruby.sketchup.com/Sketchup/View.html#add_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/View.html#add_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, add_observer, (RubyUtils::details::IObject observer), add_observer, observer)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#animation=-instance_method
	 *
	 * @param animation read https://ruby.sketchup.com/Sketchup/View.html#animation=-instance_method
	 * @return RubyUtils::details::IObject read https://ruby.sketchup.com/Sketchup/View.html#animation=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, set_animation, (RubyUtils::details::IObject animation), animation=, animation)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#average_refresh_time-instance_method
	 *
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#average_refresh_time-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(double, average_refresh_time, average_refresh_time)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#camera-instance_method
	 *
	 * @return Sketchup::Camera read https://ruby.sketchup.com/Sketchup/View.html#camera-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Camera, camera, camera)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#camera=-instance_method
	 *
	 * @param camera read https://ruby.sketchup.com/Sketchup/View.html#camera=-instance_method
	 * @return RubyUtils::details::IObject read https://ruby.sketchup.com/Sketchup/View.html#camera=-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, set_camera, (Sketchup::Camera camera), camera=, camera)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#camera=-instance_method
	 *
	 * @param camera_and_transition read https://ruby.sketchup.com/Sketchup/View.html#camera=-instance_method
	 * @return RubyUtils::details::IObject read https://ruby.sketchup.com/Sketchup/View.html#camera=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::details::IObject, set_camera, (RubyUtils::tuple<Sketchup::Camera, double> camera_and_transition), camera=, camera_and_transition)

#if SKETCHUP_VERSION >= 2025
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#center-instance_method
	 *
	 * @return RubyUtils::tuple<float DEFINE_WRAPPED_METHOD_COMMA float> read https://ruby.sketchup.com/Sketchup/View.html#center-instance_method
	 * @min_version SketchUp 2025.0
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::tuple<float DEFINE_WRAPPED_METHOD_COMMA float>, center, center)
#else
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#center-instance_method
	 *
	 * @return RubyUtils::tuple<int DEFINE_WRAPPED_METHOD_COMMA int> read https://ruby.sketchup.com/Sketchup/View.html#center-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::tuple<int DEFINE_WRAPPED_METHOD_COMMA int>, center, center)
#endif

#if SKETCHUP_VERSION >= 2025
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#corner-instance_method
	 *
	 * @param index read https://ruby.sketchup.com/Sketchup/View.html#corner-instance_method
	 * @return RubyUtils::tuple<float DEFINE_WRAPPED_METHOD_COMMA float> read https://ruby.sketchup.com/Sketchup/View.html#corner-instance_method
	 * @min_version SketchUp 2025.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::tuple<float DEFINE_WRAPPED_METHOD_COMMA float>, corner, (long long index), corner, index)
#else
	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#corner-instance_method
	 *
	 * @param index read https://ruby.sketchup.com/Sketchup/View.html#corner-instance_method
	 * @return RubyUtils::tuple<int DEFINE_WRAPPED_METHOD_COMMA int> read https://ruby.sketchup.com/Sketchup/View.html#corner-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::tuple<int DEFINE_WRAPPED_METHOD_COMMA int>, corner, (long long index), corner, index)
#endif

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#device_height-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/View.html#device_height-instance_method
	 * @min_version SketchUp 2025.0
	 */
	DEFINE_WRAPPED_METHOD_0(long long, device_height, device_height)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#device_width-instance_method
	 *
	 * @return long long read https://ruby.sketchup.com/Sketchup/View.html#device_width-instance_method
	 * @min_version SketchUp 2025.0
	 */
	DEFINE_WRAPPED_METHOD_0(long long, device_width, device_width)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 *
	 * @param openglenum read https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 * @param points read https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw, (long long openglenum, RubyUtils::Enumerable<Geom::Point3d> points), draw, openglenum, points)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 *
	 * @param openglenum read https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 * @param points read https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 * @param **options read https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw-instance_method
	 * @min_version SketchUp 2020.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw, (long long openglenum, RubyUtils::Enumerable<Geom::Point3d> points, DrawOptions options), draw, openglenum, points, options)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 *
	 * @param openglenum read https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 * @param points read https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw2d, (long long openglenum, RubyUtils::Enumerable<Geom::Point3d> points), draw2d, openglenum, points)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 *
	 * @param openglenum read https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 * @param points read https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 * @param **options read https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw2d-instance_method
	 * @min_version SketchUp 2020.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw2d, (long long openglenum, RubyUtils::Enumerable<Geom::Point3d> points, Draw2dOptions options), draw2d, openglenum, points, options)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw_lines-instance_method
	 *
	 * @param points read https://ruby.sketchup.com/Sketchup/View.html#draw_lines-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw_lines-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw_lines, (RubyUtils::Enumerable<Geom::Point3d> points), draw_lines, points)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw_points-instance_method
	 *
	 * @param points read https://ruby.sketchup.com/Sketchup/View.html#draw_points-instance_method
	 * @param size read https://ruby.sketchup.com/Sketchup/View.html#draw_points-instance_method
	 * @param style read https://ruby.sketchup.com/Sketchup/View.html#draw_points-instance_method
	 * @param color read https://ruby.sketchup.com/Sketchup/View.html#draw_points-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw_points-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(
		Sketchup::View,
		draw_points,
		(RubyUtils::Enumerable<Geom::Point3d> points, long long size = 6, long long style = 3, Sketchup::Color color = RubyUtils::details::IObject("'black'")),
		draw_points,
		points,
		size,
		style,
		color)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw_polyline-instance_method
	 *
	 * @param points read https://ruby.sketchup.com/Sketchup/View.html#draw_polyline-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw_polyline-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw_polyline, (RubyUtils::Enumerable<Geom::Point3d> points), draw_polyline, points)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 *
	 * @param point read https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 * @param text read https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw_text, (Geom::Point3d point, std::string text), draw_text, point, text)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 *
	 * @param point read https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 * @param text read https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 * @param options read https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#draw_text-instance_method
	 * @min_version SketchUp 2016SketchUp 6.0Known Bugs:Prior to SU2022.0, on macOS, the vertical text alignment for some fonts could appear to be offset from
	 * their expected positions. As of SU2022.0 the vertical alignment should be more accurate and consistent.
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, draw_text, (Geom::Point3d point, std::string text, DrawTextOptions options), draw_text, point, text, options)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#drawing_color=-instance_method
	 *
	 * @param color read https://ruby.sketchup.com/Sketchup/View.html#drawing_color=-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#drawing_color=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, set_drawing_color, (RubyUtils::any_of<Sketchup::Color, std::string> color), drawing_color=, color)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#dynamic=-instance_method
	 *
	 * @param value read https://ruby.sketchup.com/Sketchup/View.html#dynamic=-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/View.html#dynamic=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(bool, set_dynamic, (bool value), dynamic=, value)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#field_of_view-instance_method
	 *
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#field_of_view-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(double, field_of_view, field_of_view)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#field_of_view=-instance_method
	 *
	 * @param fov read https://ruby.sketchup.com/Sketchup/View.html#field_of_view=-instance_method
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#field_of_view=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(double, set_field_of_view, (double fov), field_of_view=, fov)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#graphics_engine-instance_method
	 *
	 * @return Symbol read https://ruby.sketchup.com/Sketchup/View.html#graphics_engine-instance_method
	 * @min_version SketchUp 2024.0
	 */
	DEFINE_WRAPPED_METHOD_0(RubyUtils::Object, graphics_engine, graphics_engine)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#guess_target-instance_method
	 *
	 * @return Geom::Point3d read https://ruby.sketchup.com/Sketchup/View.html#guess_target-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD_0(Geom::Point3d, guess_target, guess_target)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#guess_target-instance_method
	 *
	 * @param screen_point read https://ruby.sketchup.com/Sketchup/View.html#guess_target-instance_method
	 * @return Geom::Point3d read https://ruby.sketchup.com/Sketchup/View.html#guess_target-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Geom::Point3d, guess_target, (Geom::Point3d screen_point), guess_target, screen_point)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#inference_locked%3F-instance_method
	 *
	 * @return bool read https://ruby.sketchup.com/Sketchup/View.html#inference_locked%3F-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(bool, is_inference_locked, inference_locked?)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 *
	 * @param x read https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 * @param y read https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 * @return Sketchup::InputPoint read https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 * @min_version SketchUp 2025.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::InputPoint, inputpoint, (double x, double y), inputpoint, x, y)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 *
	 * @param x read https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 * @param y read https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 * @param inputpoint1 read https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 * @return Sketchup::InputPoint read https://ruby.sketchup.com/Sketchup/View.html#inputpoint-instance_method
	 * @min_version SketchUp 2025.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::InputPoint, inputpoint, (double x, double y, Sketchup::InputPoint inputpoint1), inputpoint, x, y, inputpoint1)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#invalidate-instance_method
	 *
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#invalidate-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::View, invalidate, invalidate)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#last_refresh_time-instance_method
	 *
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#last_refresh_time-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD_0(double, last_refresh_time, last_refresh_time)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#last_refresh_time-instance_method
	 *
	 * @param full read https://ruby.sketchup.com/Sketchup/View.html#last_refresh_time-instance_method
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#last_refresh_time-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(double, last_refresh_time, (bool full), last_refresh_time, full)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#line_stipple=-instance_method
	 *
	 * @param pattern read https://ruby.sketchup.com/Sketchup/View.html#line_stipple=-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#line_stipple=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, set_line_stipple, (std::string pattern), line_stipple=, pattern)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#line_width=-instance_method
	 *
	 * @param width read https://ruby.sketchup.com/Sketchup/View.html#line_width=-instance_method
	 * @return long long read https://ruby.sketchup.com/Sketchup/View.html#line_width=-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(long long, set_line_width, (long long width), line_width=, width)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#load_texture-instance_method
	 *
	 * @param image_rep read https://ruby.sketchup.com/Sketchup/View.html#load_texture-instance_method
	 * @return long long read https://ruby.sketchup.com/Sketchup/View.html#load_texture-instance_method
	 * @min_version SketchUp 2020.0
	 */
	DEFINE_WRAPPED_METHOD(long long, load_texture, (Sketchup::ImageRep image_rep), load_texture, image_rep)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 *
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::View, lock_inference, lock_inference)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 *
	 * @param inputpoint read https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::View, lock_inference, (Sketchup::InputPoint inputpoint), lock_inference, inputpoint)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 *
	 * @param inputpoint read https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 * @param inputpoint2 read https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#lock_inference-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(
		Sketchup::View, lock_inference, (Sketchup::InputPoint inputpoint, Sketchup::InputPoint inputpoint2), lock_inference, inputpoint, inputpoint2)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#model-instance_method
	 *
	 * @return Sketchup::Model read https://ruby.sketchup.com/Sketchup/View.html#model-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::Model, model, model)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 *
	 * @return Sketchup::PickHelper read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @min_version
	 */
	DEFINE_WRAPPED_METHOD_0(Sketchup::PickHelper, pick_helper, pick_helper)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 *
	 * @param x read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @param y read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @param aperture read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @return Sketchup::PickHelper read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @min_version SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::PickHelper, pick_helper, (long long x, long long y, long long aperture), pick_helper, x, y, aperture)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 *
	 * @param x read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @param y read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @param aperture read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @return Sketchup::PickHelper read https://ruby.sketchup.com/Sketchup/View.html#pick_helper-instance_method
	 * @min_version SketchUp 2025.0SketchUp 6.0
	 */
	DEFINE_WRAPPED_METHOD(Sketchup::PickHelper, pick_helper, (double x, double y, double aperture), pick_helper, x, y, aperture)

	/**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#pickray-instance_method
	 *
	 * @param screen_point read https://ruby.sketchup.com/Sketchup/View.html#pickray-instance_method
	 * @return RubyUtils::tuple<Geom::Point3d, Geom::Vector3d> read https://ruby.sketchup.com/Sketchup/View.html#pickray-instance_method
	 * @min_version SketchUp 2025.0
	 */
	DEFINE_WRAPPED_METHOD(RubyUtils::tuple<Geom::Point3d DEFINE_WRAPPED_METHOD_COMMA Geom::Vector3d>, pickray, (RubyUtils::tuple<double, double> screen_point), pickray, screen_point)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#pickray-instance_method
	 * 
	 * @param x read https://ruby.sketchup.com/Sketchup/View.html#pickray-instance_method
	 * @param y read https://ruby.sketchup.com/Sketchup/View.html#pickray-instance_method
	 * @return RubyUtils::tuple<Geom::Point3d, Geom::Vector3d> read https://ruby.sketchup.com/Sketchup/View.html#pickray-instance_method
	 * @min_version SketchUp 2025.0SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(RubyUtils::tuple<Geom::Point3d DEFINE_WRAPPED_METHOD_COMMA Geom::Vector3d>, pickray, (double x, double y), pickray, x, y)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#pixels_to_model-instance_method
	 * 
	 * @param pixels read https://ruby.sketchup.com/Sketchup/View.html#pixels_to_model-instance_method
	 * @param point read https://ruby.sketchup.com/Sketchup/View.html#pixels_to_model-instance_method
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#pixels_to_model-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(double, pixels_to_model, (double pixels, Geom::Point3d point), pixels_to_model, pixels, point)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#refresh-instance_method
	 * 
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#refresh-instance_method
	 * @min_version SketchUp 7.1
	 */
	 DEFINE_WRAPPED_METHOD_0(Sketchup::View, refresh, refresh)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#release_texture-instance_method
	 * 
	 * @param texture_id read https://ruby.sketchup.com/Sketchup/View.html#release_texture-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/View.html#release_texture-instance_method
	 * @min_version 
	 */
	 DEFINE_WRAPPED_METHOD(bool, release_texture, (long long texture_id), release_texture, texture_id)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#remove_observer-instance_method
	 * 
	 * @param observer read https://ruby.sketchup.com/Sketchup/View.html#remove_observer-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/View.html#remove_observer-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(bool, remove_observer, (RubyUtils::details::IObject observer), remove_observer, observer)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#screen_coords-instance_method
	 * 
	 * @param model_point read https://ruby.sketchup.com/Sketchup/View.html#screen_coords-instance_method
	 * @return Geom::Point3d read https://ruby.sketchup.com/Sketchup/View.html#screen_coords-instance_method
	 * @min_version SketchUp 2025.0SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(Geom::Point3d, screen_coords, (Geom::Point3d model_point), screen_coords, model_point)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#set_color_from_line-instance_method
	 * 
	 * @param point1 read https://ruby.sketchup.com/Sketchup/View.html#set_color_from_line-instance_method
	 * @param point2 read https://ruby.sketchup.com/Sketchup/View.html#set_color_from_line-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#set_color_from_line-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(Sketchup::View, set_color_from_line, (Geom::Point3d point1, Geom::Point3d point2), set_color_from_line, point1, point2)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#show_frame-instance_method
	 * 
	 * @param delay read https://ruby.sketchup.com/Sketchup/View.html#show_frame-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#show_frame-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(Sketchup::View, show_frame, (double delay), show_frame, delay)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#text_bounds-instance_method
	 * 
	 * @param point read https://ruby.sketchup.com/Sketchup/View.html#text_bounds-instance_method
	 * @param text read https://ruby.sketchup.com/Sketchup/View.html#text_bounds-instance_method
	 * @param options read https://ruby.sketchup.com/Sketchup/View.html#text_bounds-instance_method
	 * @return Geom::Bounds2d read https://ruby.sketchup.com/Sketchup/View.html#text_bounds-instance_method
	 * @min_version SketchUp 2020.0
	 */
	 DEFINE_WRAPPED_METHOD(Geom::Bounds2d, text_bounds, (Geom::Point3d point, std::string text, DrawTextOptions options), text_bounds, point, text, options)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#tooltip=-instance_method
	 * 
	 * @param string read https://ruby.sketchup.com/Sketchup/View.html#tooltip=-instance_method
	 * @return std::string read https://ruby.sketchup.com/Sketchup/View.html#tooltip=-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(std::string, set_tooltip, (std::string string), tooltip=, string)

#if SKETCHUP_VERSION >= 2025
	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#vpheight-instance_method
	 * 
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#vpheight-instance_method
	 * @min_version SketchUp 2025.0
	 */
	 DEFINE_WRAPPED_METHOD_0(double, vpheight, vpheight)
#else
	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#vpheight-instance_method
	 * 
	 * @return long long read https://ruby.sketchup.com/Sketchup/View.html#vpheight-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD_0(long long, vpheight, vpheight)
#endif

#if SKETCHUP_VERSION >= 2025
	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#vpwidth-instance_method
	 * 
	 * @return double read https://ruby.sketchup.com/Sketchup/View.html#vpwidth-instance_method
	 * @min_version SketchUp 2025.0
	 */
	 DEFINE_WRAPPED_METHOD_0(double, vpwidth, vpwidth)
#else
	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#vpwidth-instance_method
	 * 
	 * @return long long read https://ruby.sketchup.com/Sketchup/View.html#vpwidth-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD_0(long long, vpwidth, vpwidth)
#endif

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * 
	 * @param filename read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @param width read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @param height read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @param antialias read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @param compression read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @min_version 
	 */
	 DEFINE_WRAPPED_METHOD(bool, write_image, (std::string filename, long long width, long long height, bool antialias = false, double compression = 0.0), write_image, filename, width, height, antialias, compression)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * 
	 * @param options read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @return bool read https://ruby.sketchup.com/Sketchup/View.html#write_image-instance_method
	 * @min_version SketchUp 7SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(bool, write_image, (WriteImage1Options options), write_image, options)
	 DEFINE_WRAPPED_METHOD(bool, write_image, (WriteImage2Options options), write_image, options)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#zoom-instance_method
	 * 
	 * @param zoom_or_ents read https://ruby.sketchup.com/Sketchup/View.html#zoom-instance_method
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#zoom-instance_method
	 * @min_version SketchUp 6.0
	 */
	 DEFINE_WRAPPED_METHOD(Sketchup::View, zoom, (RubyUtils::any_of<double, Sketchup::Selection, Sketchup::Entity, RubyUtils::Enumerable<Sketchup::Entity>> zoom_or_ents), zoom, zoom_or_ents)

	 /**
	 * @brief https://ruby.sketchup.com/Sketchup/View.html#zoom_extents-instance_method
	 * 
	 * @return Sketchup::View read https://ruby.sketchup.com/Sketchup/View.html#zoom_extents-instance_method
	 * @min_version 
	 */
	 DEFINE_WRAPPED_METHOD_0(Sketchup::View, zoom_extents, zoom_extents)
};
