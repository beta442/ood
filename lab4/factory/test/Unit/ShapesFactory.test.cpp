#include "../include/pch.h"

#include "../../include/Shapes/Factory/ShapeFactory.h"

#include "../../include/Shapes/Ellipse.h"
#include "../../include/Shapes/Rectangle.h"
#include "../../include/Shapes/RegularPolygon.h"
#include "../../include/Shapes/Triangle.h"
#include "../../include/Shapes/ShapeType.hpp"

BOOST_AUTO_TEST_SUITE(Shapes_factory_tests)

	ShapeFactory f{};

	BOOST_AUTO_TEST_CASE(Creating_shape_with_empty_string_throws)
	{
		BOOST_CHECK_THROW(f.CreateShape(""), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_shape_with_wrong_shapeType_throws)
	{
		BOOST_CHECK_THROW(f.CreateShape("abracadabra"), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_shape_with_shapeType_only_throws)
	{
		using namespace shapes_string_types;

		BOOST_CHECK_THROW(f.CreateShape(std::string(RECTANGLE_TYPE)), std::invalid_argument);
		BOOST_CHECK_THROW(f.CreateShape(std::string(TRIANGLE_TYPE)), std::invalid_argument);
		BOOST_CHECK_THROW(f.CreateShape(std::string(ELLIPSE_TYPE)), std::invalid_argument);
		BOOST_CHECK_THROW(f.CreateShape(std::string(REGULAR_POLYGON_TYPE)), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_shape_with_wrong_shapeColor_throws)
	{
		BOOST_CHECK_THROW(f.CreateShape("ellIpse abracadabra"), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_shape_with_shapeType_and_shapeColor_only_throws)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		BOOST_CHECK_THROW(f.CreateShape(std::string(RECTANGLE_TYPE) + " " + std::string(GREEN_TYPE)), std::invalid_argument);
		BOOST_CHECK_THROW(f.CreateShape(std::string(TRIANGLE_TYPE) + " " + std::string(RED_TYPE)), std::invalid_argument);
		BOOST_CHECK_THROW(f.CreateShape(std::string(ELLIPSE_TYPE) + " " + std::string(BLACK_TYPE)), std::invalid_argument);
		BOOST_CHECK_THROW(f.CreateShape(std::string(REGULAR_POLYGON_TYPE) + " " + std::string(BLUE_TYPE)), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_shape_with_shapeType_and_shapeColor_and_point_only_throws)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		BOOST_CHECK_THROW(f.CreateShape(std::string(RECTANGLE_TYPE) + " " + std::string(GREEN_TYPE) + " 10 -20"), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_shape_with_shapeType_and_shapeColor_and_wrongPoint_throws)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		BOOST_CHECK_THROW(f.CreateShape(std::string(RECTANGLE_TYPE) + " " + std::string(GREEN_TYPE) + " a b"), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_ellipse_with_wrong_args_throws)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		BOOST_CHECK_THROW(f.CreateShape(std::string(ELLIPSE_TYPE) + " " + std::string(GREEN_TYPE) + " 10 -20 a b"), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Creating_ellipse)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		const Point baseP{ 10, -20 };
		const unsigned int verticalR = 30, horizontalR = 40;
		const Color color = Color::GREEN;
		std::stringstream ss{ std::string(ELLIPSE_TYPE) + " " + std::string(GREEN_TYPE) + " 10 -20 30 40" };
		std::string dscrpt{};
		std::getline(ss, dscrpt);

		const auto shape = f.CreateShape(dscrpt);

		BOOST_CHECK(shape->GetBasePoint() == baseP);
		BOOST_CHECK(shape->GetColor() == color);
	}

	BOOST_AUTO_TEST_CASE(Creating_rectangle)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		const Point baseP{ 10, -20 };
		const unsigned int width = 30, height = 40;
		const Color color = Color::GREEN;
		std::stringstream ss{ std::string(RECTANGLE_TYPE) + " " + std::string(GREEN_TYPE) + " 10 -20 30 40" };
		std::string dscrpt{};
		std::getline(ss, dscrpt);

		const auto shape = f.CreateShape(dscrpt);

		BOOST_CHECK(shape->GetBasePoint() == baseP);
		BOOST_CHECK(shape->GetColor() == color);
	}

	BOOST_AUTO_TEST_CASE(Creating_regularPoly)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		const Point baseP{ 10, -20 };
		const unsigned int radius = 30;
		const size_t vertexCount = 100;
		const Color color = Color::GREEN;
		std::stringstream ss{ std::string(REGULAR_POLYGON_TYPE) + " " + std::string(GREEN_TYPE) + " 10 -20 30 100" };
		std::string dscrpt{};
		std::getline(ss, dscrpt);

		const auto shape = f.CreateShape(dscrpt);

		BOOST_CHECK(shape->GetBasePoint() == baseP);
		BOOST_CHECK(shape->GetColor() == color);
	}

	BOOST_AUTO_TEST_CASE(Creating_triangle)
	{
		using namespace shapes_string_types;
		using namespace color_string_types;

		const Point v1{ 10, -20 }, v2{ 0, 0 }, v3{ 100, 100 };
		const Color color = Color::GREEN;
		std::stringstream ss{ std::string(TRIANGLE_TYPE) + " " + std::string(GREEN_TYPE) + " 10 -20 0 0 100 100" };
		std::string dscrpt{};
		std::getline(ss, dscrpt);

		const auto shape = f.CreateShape(dscrpt);

		BOOST_CHECK(shape->GetBasePoint() == v1);
		BOOST_CHECK(shape->GetColor() == color);
	}

BOOST_AUTO_TEST_SUITE_END();
