#include "pch.h"

#include "slide/shape/Rectangle.h"

void PrintFrameInfo(const slide::RectD& frame)
{
	std::cout << "Frame:\n"
			  << "       x: " << frame.leftTop.x << '\n'
			  << "       y: " << frame.leftTop.y << '\n'
			  << "   width: " << frame.width << '\n'
			  << "  height: " << frame.height << std::endl;
}

void PrintStyleInfo(const slide::shape::IStyle& style)
{
	bool hasColor = style.GetColor().has_value();
	bool hasEnabled = style.IsEnabled().has_value();
	std::cout << "Style:\n"
			  << std::boolalpha
			  << "       hasColor: " << hasColor << '\n'
			  << "     hasEnabled: " << hasEnabled;

	if (hasColor)
	{
		std::cout << "\n          color: 0x"
				  << std::hex << std::setw(8) << std::setfill('0') << style.GetColor().value();
	}
	if (hasEnabled)
	{
		std::cout << "\n  enabledStatus: "
				  << style.IsEnabled().value();
	}

	std::cout << std::endl;
}

void PrintShapeInfo(const slide::shape::IShape& shape)
{
	PrintFrameInfo(shape.GetFrame());
	std::cout << "Fill ";
	PrintStyleInfo(shape.GetFillStyle());
	std::cout << "Outline ";
	PrintStyleInfo(shape.GetOutlineStyle());
}

slide::shape::IStylePtr CreateStyle(slide::RGBAColor color, bool enableOnInit = true)
{
	return std::make_unique<slide::shape::Style>(color, enableOnInit);
}

int main()
{
	using namespace slide;
	using namespace shape;

	Rectangle rect1{};
	std::cout << "Rect1:" << std::endl;
	PrintShapeInfo(rect1);

	Rectangle rect2{ RectD{}, CreateStyle(1234567890), CreateStyle(987654321, false) };
	std::cout << "\nRect2:" << std::endl;
	PrintShapeInfo(rect2);

	auto rectD = RectD{};
	rectD.leftTop = { 100, 150 };
	rectD.width = 150;
	rectD.height = 20;
	Rectangle rect3{ rectD, CreateStyle(1234567890), CreateStyle(987654321, true) };
	std::cout << "\nRect3:" << std::endl;
	PrintShapeInfo(rect3);

	return 0;
}
