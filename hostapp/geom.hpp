#pragma once

class Geom
{
	public:
	class PolygonMesh : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::PolygonMesh"> {
        public:
            PolygonMesh(VALUE obj) : IObject(obj) { }
            PolygonMesh(const IObject& obj) : IObject(obj) { }
            enum {
                NO_SMOOTH_OR_HIDE = 0, //
                HIDE_BASED_ON_INDEX = 1, // (Negative point index will hide the edge.)
                SOFTEN_BASED_ON_INDEX = 2, // (Negative point index will soften the edge.)
                AUTO_SOFTEN = 4, // (Interior edges are softened.)
                SMOOTH_SOFT_EDGES = 8, // (All soft edges will also be smooth.)
            };
    };

	class BoundingBox : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::BoundingBox">
	{
		public:
		inline BoundingBox(VALUE obj) : IObject(obj)
		{
		}
		inline BoundingBox(const IObject& obj) : IObject(obj)
		{
		}
	};
	class Point2d : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::Point2d">
	{
		public:
		inline Point2d(VALUE obj) : IObject(obj)
		{
		}
		inline Point2d(const IObject& obj) : IObject(obj)
		{
		}
	};
	class Point3d : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::Point3d">
	{
		public:
		inline Point3d(VALUE obj) : IObject(obj)
		{
		}
		inline Point3d(const IObject& obj) : IObject(obj)
		{
		}
	};
	class Vector3d : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::Vector3d">
	{
		public:
		inline Vector3d(VALUE obj) : IObject(obj)
		{
		}
		inline Vector3d(const IObject& obj) : IObject(obj)
		{
		}
	};
	class Transformation : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::Transformation">
	{
		public:
		inline Transformation(VALUE obj) : IObject(obj)
		{
		}
		inline Transformation(const IObject& obj) : IObject(obj)
		{
		}
	};
	class LatLong : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::LatLong">
	{
		public:
		inline LatLong(VALUE obj) : IObject(obj)
		{
		}
		inline LatLong(const IObject& obj) : IObject(obj)
		{
		}
	};
	class UTM : public RubyUtils::details::IObject, public RubyUtils::details::NamedRubyWrapper<"Geom::UTM">
	{
		public:
		inline UTM(VALUE obj) : IObject(obj)
		{
		}
		inline UTM(const IObject& obj) : IObject(obj)
		{
		}
	};
};
