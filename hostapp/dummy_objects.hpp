#pragma once

class ImageRep : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ImageRep">
{
	public:
	inline ImageRep(VALUE obj) : IObject(obj)
	{
	}
	inline ImageRep(const IObject& obj) : IObject(obj)
	{
	}
};

class Texture : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Texture">
{
	public:
	inline Texture(VALUE obj) : IObject(obj)
	{
	}
	inline Texture(const IObject& obj) : IObject(obj)
	{
	}
};

class Color : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Color">
{
	public:
	inline Color(VALUE obj) : IObject(obj)
	{
	}
	inline Color(const IObject& obj) : IObject(obj)
	{
	}
};

class Edge : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Edge">
{
	public:
	inline Edge(VALUE obj) : IObject(obj)
	{
	}
	inline Edge(const IObject& obj) : IObject(obj)
	{
	}
};

class SectionPlane : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::SectionPlane">
{
	public:
	inline SectionPlane(VALUE obj) : IObject(obj)
	{
	}
	inline SectionPlane(const IObject& obj) : IObject(obj)
	{
	}
};

class Layer : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Layer">
{
	public:
	inline Layer(VALUE obj) : IObject(obj)
	{
	}
	inline Layer(const IObject& obj) : IObject(obj)
	{
	}
};

class Drawingelement : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Drawingelement">
{
	public:
	inline Drawingelement(VALUE obj) : IObject(obj)
	{
	}
	inline Drawingelement(const IObject& obj) : IObject(obj)
	{
	}
};

class InstancePath : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::InstancePath">
{
	public:
	inline InstancePath(VALUE obj) : IObject(obj)
	{
	}
	inline InstancePath(const IObject& obj) : IObject(obj)
	{
	}
};

class ComponentDefinition : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ComponentDefinition">
{
	public:
	inline ComponentDefinition(VALUE obj) : IObject(obj)
	{
	}
	inline ComponentDefinition(const IObject& obj) : IObject(obj)
	{
	}
};

class View : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::View">
{
	public:
	inline View(VALUE obj) : IObject(obj)
	{
	}
	inline View(const IObject& obj) : IObject(obj)
	{
	}
};

class Text : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Text">
{
	public:
	inline Text(VALUE obj) : IObject(obj)
	{
	}
	inline Text(const IObject& obj) : IObject(obj)
	{
	}
};

class AttributeDictionaries : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::AttributeDictionaries">
{
	public:
	inline AttributeDictionaries(VALUE obj) : IObject(obj)
	{
	}
	inline AttributeDictionaries(const IObject& obj) : IObject(obj)
	{
	}
};

class Axes : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Axes">
{
	public:
	inline Axes(VALUE obj) : IObject(obj)
	{
	}
	inline Axes(const IObject& obj) : IObject(obj)
	{
	}
};

class Behavior : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Behavior">
{
	public:
	inline Behavior(VALUE obj) : IObject(obj)
	{
	}
	inline Behavior(const IObject& obj) : IObject(obj)
	{
	}
};

class Classifications : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Classifications">
{
	public:
	inline Classifications(VALUE obj) : IObject(obj)
	{
	}
	inline Classifications(const IObject& obj) : IObject(obj)
	{
	}
};

class Layers : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Layers">
{
	public:
	inline Layers(VALUE obj) : IObject(obj)
	{
	}
	inline Layers(const IObject& obj) : IObject(obj)
	{
	}
};

class LineStyles : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::LineStyles">
{
	public:
	inline LineStyles(VALUE obj) : IObject(obj)
	{
	}
	inline LineStyles(const IObject& obj) : IObject(obj)
	{
	}
};

class OptionsManager : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::OptionsManager">
{
	public:
	inline OptionsManager(VALUE obj) : IObject(obj)
	{
	}
	inline OptionsManager(const IObject& obj) : IObject(obj)
	{
	}
};

class OverlaysManager : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::OverlaysManager">
{
	public:
	inline OverlaysManager(VALUE obj) : IObject(obj)
	{
	}
	inline OverlaysManager(const IObject& obj) : IObject(obj)
	{
	}
};

class Pages : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Pages">
{
	public:
	inline Pages(VALUE obj) : IObject(obj)
	{
	}
	inline Pages(const IObject& obj) : IObject(obj)
	{
	}
};

class RenderingOptions : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::RenderingOptions">
{
	public:
	inline RenderingOptions(VALUE obj) : IObject(obj)
	{
	}
	inline RenderingOptions(const IObject& obj) : IObject(obj)
	{
	}
};

class Selection : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Selection">
{
	public:
	inline Selection(VALUE obj) : IObject(obj)
	{
	}
	inline Selection(const IObject& obj) : IObject(obj)
	{
	}
};

class ShadowInfo : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ShadowInfo">
{
	public:
	inline ShadowInfo(VALUE obj) : IObject(obj)
	{
	}
	inline ShadowInfo(const IObject& obj) : IObject(obj)
	{
	}
};

class Styles : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Styles">
{
	public:
	inline Styles(VALUE obj) : IObject(obj)
	{
	}
	inline Styles(const IObject& obj) : IObject(obj)
	{
	}
};

class Tools : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Tools">
{
	public:
	inline Tools(VALUE obj) : IObject(obj)
	{
	}
	inline Tools(const IObject& obj) : IObject(obj)
	{
	}
};

class AttributeDictionary : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::AttributeDictionary">
{
	public:
	inline AttributeDictionary(VALUE obj) : IObject(obj)
	{
	}
	inline AttributeDictionary(const IObject& obj) : IObject(obj)
	{
	}
};

class Hash : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Hash">
{
	public:
	inline Hash(VALUE obj) : IObject(obj)
	{
	}
	inline Hash(const IObject& obj) : IObject(obj)
	{
	}
};

class Length : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Length">
{
	public:
	inline Length(VALUE obj) : IObject(obj)
	{
	}
	inline Length(double obj) : IObject(std::to_string(obj))
	{
	}
	inline Length(const IObject& obj) : IObject(obj)
	{
	}
};

class ConstructionLine : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ConstructionLine">
{
	public:
	inline ConstructionLine(VALUE obj) : IObject(obj)
	{
	}
	inline ConstructionLine(const IObject& obj) : IObject(obj)
	{
	}
};

class ConstructionPoint : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ConstructionPoint">
{
	public:
	inline ConstructionPoint(VALUE obj) : IObject(obj)
	{
	}
	inline ConstructionPoint(const IObject& obj) : IObject(obj)
	{
	}
};

class DimensionLinear : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::DimensionLinear">
{
	public:
	inline DimensionLinear(VALUE obj) : IObject(obj)
	{
	}
	inline DimensionLinear(const IObject& obj) : IObject(obj)
	{
	}
};

class DimensionRadial : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::DimensionRadial">
{
	public:
	inline DimensionRadial(VALUE obj) : IObject(obj)
	{
	}
	inline DimensionRadial(const IObject& obj) : IObject(obj)
	{
	}
};

class Face : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Face">
{
	public:
	inline Face(VALUE obj) : IObject(obj)
	{
	}
	inline Face(const IObject& obj) : IObject(obj)
	{
	}
};

class Curv : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Curv">
{
	public:
	inline Curv(VALUE obj) : IObject(obj)
	{
	}
	inline Curv(const IObject& obj) : IObject(obj)
	{
	}
};

class ArcCurve : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ArcCurve">
{
	public:
	inline ArcCurve(VALUE obj) : IObject(obj)
	{
	}
	inline ArcCurve(const IObject& obj) : IObject(obj)
	{
	}
};

class Image : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Image">
{
	public:
	inline Image(VALUE obj) : IObject(obj)
	{
	}
	inline Image(const IObject& obj) : IObject(obj)
	{
	}
};

class ComponentInstance : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::ComponentInstance">
{
	public:
	inline ComponentInstance(VALUE obj) : IObject(obj)
	{
	}
	inline ComponentInstance(const IObject& obj) : IObject(obj)
	{
	}
};

class InputPoint : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::InputPoint">
{
	public:
	inline InputPoint(VALUE obj) : IObject(obj)
	{
	}
	inline InputPoint(const IObject& obj) : IObject(obj)
	{
	}
};

class Group : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Group">
{
	public:
	inline Group(VALUE obj) : IObject(obj)
	{
	}
	inline Group(const IObject& obj) : IObject(obj)
	{
	}
};

class Vertex : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Vertex">
{
	public:
	inline Vertex(VALUE obj) : IObject(obj)
	{
	}
	inline Vertex(const IObject& obj) : IObject(obj)
	{
	}
};

class Curve : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Sketchup::Curve">
{
	public:
	inline Curve(VALUE obj) : IObject(obj)
	{
	}
	inline Curve(const IObject& obj) : IObject(obj)
	{
	}
};