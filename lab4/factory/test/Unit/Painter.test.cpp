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
			"regular-polygon grEEn 400 400 100 15\n"
		};
		const Point expectedEllipseP{ 145, 40 }, expectedRegularPolyP{ 400, 400 };

		Designer d{ std::move(std::make_shared<ShapeFactory>()) };
		auto draft = d.CreateDraft(iss);

		Painter p{};
		auto canvas = std::make_shared<MockCanvas>();
		p.DrawPicture(draft, canvas);

		std::cout << canvas->ssCanvas.str();
	}

BOOST_AUTO_TEST_SUITE_END();
