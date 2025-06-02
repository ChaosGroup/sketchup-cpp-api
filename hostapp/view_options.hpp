#pragma once
#include "../ruby/utils.hpp"
#include "../cpp/utils.hpp"

class DrawOptionSet : public cpp_utils::DummyClass
{
public:
    using normals = RubyUtils::Key<"normals", RubyUtils::Enumerable<Geom::Vector3d>>;
    using texture = RubyUtils::Key<"texture", int>;
    using uvs = RubyUtils::Key<"uvs", RubyUtils::Enumerable<Geom::Vector3d>>;
};

class Draw2dOptionSet : public cpp_utils::DummyClass
{
public:
    using texture = RubyUtils::Key<"texture", int>;
    using uvs = RubyUtils::Key<"uvs", RubyUtils::Enumerable<Geom::Vector3d>>;
};

class DrawTextOptionSet : public cpp_utils::DummyClass
{
public:
    /*
    :font (String) — The name of the font to use. If it does not exist on the system, a default font will be used instead.
    :size (Integer) — Legacy: The size of the font in system-dependent units. On Windows this is in points, on Mac it's in pixels.
    :pixel_size (Integer) — Added SketchUp 2025.0: The size of the font in pixels.
    :point_size (Integer) — Added SketchUp 2025.0: The size of the font in points.
    :bold (Boolean) — Controls the Bold property of the font.
    :italic (Boolean) — Controls the Italic property of the font.
    :color (Sketchup::Color) — The color to draw the text with.
    :align (Integer) — The text alignment, one of the following constants: TextAlignLeft, TextAlignCenter or TextAlignRight.
    :vertical_align (Integer) — Added SketchUp 2020.0. The vertical text alignment, one of the following constants: TextVerticalAlignBoundsTop, TextVerticalAlignBaseline, TextVerticalAlignCapHeight or TextVerticalAlignCenter. Note that some fonts on Mac might not align as expected due to the system reporting incorrect font metrics.
    */
    using font = RubyUtils::Key<"font", std::string>;
    using size = RubyUtils::Key<"size", int>;
    using pixel_size = RubyUtils::Key<"pixel_size", int>;
    using point_size = RubyUtils::Key<"point_size", int>;
    using bold = RubyUtils::Key<"bold", bool>;
    using italic = RubyUtils::Key<"italic", bool>;
    using color = RubyUtils::Key<"color", Sketchup::Color>;
    using align = RubyUtils::Key<"align", int>;
    using vertical_align = RubyUtils::Key<"vertical_align", int>;
};

class WriteImageOptionSet : public cpp_utils::DummyClass
{
public:
    /*
    filename (String) — The filename for the saved image.
    width (Integer) — default: #vpwidth — Width in pixels (max 16000).
    height (Integer) — default: #vpheight — Height in pixels (max 16000).
    scale_factor (Float) — default: 1.0 — Scaling factor for elements that are viewport dependent, such as text heights, arrow heads, line widths, stipple patterns, etc. (Added in SketchUp 2019.2)
    antialias (Boolean) — default: false
    compression (Float) — default: 1.0 — Compression factor for JPEG, images between 0.0 and 1.0.
    transparent (Boolean) — default: false — Added in SketchUp 8.
    */
    using filename = RubyUtils::Key<"filename", std::string>;
    using width = RubyUtils::Key<"width", int>;
    using height = RubyUtils::Key<"height", int>;
    using scale_factor = RubyUtils::Key<"scale_factor", double>;
    using antialias = RubyUtils::Key<"antialias", bool>;
    using compression = RubyUtils::Key<"compression", double>;
    using transparent = RubyUtils::Key<"transparent", bool>;

    /*
    filename (String) — The filename for the saved image.
    source (Boolean) — default: :image — Set to :framebuffer to dump the current framebuffer.
    compression (Float) — default: 1.0 — Compression factor for JPEG, images between 0.0 and 1.0.
    */
    using source = RubyUtils::Key<"source", bool>;
};
