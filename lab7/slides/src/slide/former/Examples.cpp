#include "pch.h"

#include "Examples.h"

#include "slide/drawable/shape/CShape/ellipse/Ellipse.h"
#include "slide/drawable/shape/CShape/rectangle/Rectangle.h"
#include "slide/drawable/shape/CShape/triangle/Triangle.h"

#include "slide/drawable/shape/group_shape/CGroupShape/GroupShape.h"

slide::shape::IStylePtr CreateStyle(slide::common::RGBAColor color, bool enableOnInit = true)
{
	return std::make_unique<slide::shape::Style>(color, enableOnInit);
}

namespace slide
{

namespace demo
{

void FormSlideWithComputerScreenPicture(ISlide& slide)
{
	using RectD = shape::Rectangle::RectD;
	using PointD = slide::common::PointD;

	auto shapesGroup = std::make_shared<shape::GroupShape>();

	auto screenWrapperRect = std::make_shared<shape::Rectangle>(RectD{ 4, 4, 840, 660 }, CreateStyle(0x00AD00FF), CreateStyle(0x000000FF));
	auto screen = std::make_shared<shape::Rectangle>(RectD{ 24, 34, 800, 600 }, CreateStyle(0x7F7E85FF), CreateStyle(0x7F7E85FF));
	auto powerButton = std::make_shared<shape::Rectangle>(RectD{ 814, 647, 10, 10 }, CreateStyle(0xFF0000FF), CreateStyle(0xFF0000FF));
	auto taskManager = std::make_shared<shape::Rectangle>(RectD{ 24, 600, 800, 34 }, CreateStyle(0x2A3B43FF), CreateStyle(0x2A3B43FF));

	auto startBtn = std::make_shared<shape::Triangle>(PointD{ 38, 630 }, PointD{ 53, 610 }, PointD{ 68, 630 }, CreateStyle(0x24ACF2FF), CreateStyle(0x24ACF2FF));

	auto firstEllipse = std::make_shared<shape::Ellipse>(PointD{ 300, 200 }, 200, 100, CreateStyle(0x7F7E85FF), CreateStyle(0x2A3B43FF));
	auto secondEllipse = std::make_shared<shape::Ellipse>(PointD{ 325, 120 }, 100, 200, CreateStyle(0x2A3B43FF), CreateStyle(0x7F7E85FF));

	shapesGroup->InsertShape(screenWrapperRect);
	shapesGroup->InsertShape(screen);
	shapesGroup->InsertShape(powerButton);
	shapesGroup->InsertShape(taskManager);
	shapesGroup->InsertShape(startBtn);
	shapesGroup->InsertShape(firstEllipse);
	shapesGroup->InsertShape(secondEllipse);

	auto& slideShapes = slide.GetShapes();
	for (size_t i = slideShapes.GetShapesCount(); i > 0; --i)
	{
		slideShapes.RemoveShapeAtIndex(i - 1);
	}

	slideShapes.InsertShape(shapesGroup);
}

} // namespace demo

} // namespace slide
