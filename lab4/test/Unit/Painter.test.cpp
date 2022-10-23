#include "../include/pch.h"

#include "../../include/Designer/Designer.h"
#include "../../include/Painter/Painter.h"

class MockCanvas : public ICanvas
{
public:
	void DrawLine(const Point& from, const Point& to)
	{
		ssCanvas << from.x << " " << from.y << " " << to.x << " " << to.y << '\n';
	}
	
	void DrawEllipse(const Point& center, unsigned int verticalR, unsigned int horizontalRadius)
	{
		ssCanvas << center.x << " " << center.y << " " << verticalR << " " << horizontalRadius << '\n';
	}
	
	void DrawRegularPolygon(const std::vector<Point>& points)
	{
		for (auto& p : points)
		{
			ssCanvas << p.x << " " << p.y << '\n';
		}
	}
	
	void SetColor(Color color)
	{
		ssCanvas << "color\n";
	}

	std::stringstream ssCanvas;
};

BOOST_AUTO_TEST_SUITE(Designer_tests)

	BOOST_AUTO_TEST_CASE(Designer_outputs_drafts_content_into_mock_canvas)
	{
		std::istringstream iss{
			std::string("eLlIpsE black 145 40 38 21\n") +
			"rectangle green 0 0 100 12\n" +
			"triangle blue 140 140 365 144 143 400\n" +
			"regular-polygon grEEn 400 400 100 3\n"
		};
		const std::string expectedResult = std::string("color\n") +
			"145 40 38 21\n" +
			"color\n" +
			"0 0\n" +
			"100 0\n" +
			"100 12\n" +
			"0 12\n" +
			"color\n" +
			"140 140\n" +
			"365 144\n" +
			"143 400\n" +
			"color\n" +
			"500 400\n" +
			"350 487\n" +
			"350 313\n";

		Designer d{ std::move(std::make_shared<ShapeFactory>()) };
		auto draft = d.CreateDraft(iss);

		Painter p{};
		auto canvas = std::make_shared<MockCanvas>();
		p.DrawPicture(draft, canvas);

		BOOST_CHECK_EQUAL(expectedResult, canvas->ssCanvas.str());
	}

BOOST_AUTO_TEST_SUITE_END();
