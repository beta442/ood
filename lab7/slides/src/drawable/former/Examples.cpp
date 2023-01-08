#include "pch.h"

#include "Examples.h"

#include "drawable/shape/CShape/ellipse/Ellipse.h"
#include "drawable/shape/CShape/rectangle/Rectangle.h"
#include "drawable/shape/CShape/triangle/Triangle.h"
#include "drawable/shape/group_shape/CGroupShape/GroupShape.h"

#include "drawable/common/rect/RectD.h"

drawable::shape::IStylePtr CreateStyle(drawable::common::RGBAColor color, bool enableOnInit = true)
{
	return std::make_unique<drawable::shape::Style>(color, enableOnInit);
}

namespace drawable::slide::demo
{

void FormSlideWithComputerScreenPicture(ISlide& slide)
{
	using RectD = shape::Rectangle::RectD;
	using PointD = drawable::common::PointD;

	auto shapesGroup = shape::GroupShape::Create();

	auto screenWrapperRect = std::make_shared<shape::Rectangle>(RectD{ 4, 4, 840, 660 }, CreateStyle(0x00AD00FF), CreateStyle(0x000000FF));
	auto screen = std::make_shared<shape::Rectangle>(RectD{ 24, 34, 800, 600 }, CreateStyle(0x7F7E85FF), CreateStyle(0x7F7E85FF));
	auto powerButton = std::make_shared<shape::Rectangle>(RectD{ 814, 647, 10, 10 }, CreateStyle(0xFF0000FF), CreateStyle(0xFF0000FF));
	auto taskManager = std::make_shared<shape::Rectangle>(RectD{ 24, 600, 800, 34 }, CreateStyle(0x2A3B43FF), CreateStyle(0x2A3B43FF));

	auto startBtn = std::make_shared<shape::Triangle>(PointD{ 38, 630 }, PointD{ 53, 610 }, PointD{ 68, 630 }, CreateStyle(0x24ACF2FF), CreateStyle(0x24ACF2FF));

	auto wallpaper = shape::GroupShape::Create();
	auto firstEllipse = std::make_shared<shape::Ellipse>(PointD{ 300, 200 }, 200, 100, CreateStyle(0x7F7E85FF), CreateStyle(0x2A3B43FF));
	auto secondEllipse = std::make_shared<shape::Ellipse>(PointD{ 325, 120 }, 100, 200, CreateStyle(0x2A3B43FF), CreateStyle(0x7F7E85FF));
	wallpaper->InsertShape(firstEllipse);
	wallpaper->InsertShape(secondEllipse);

	auto s = wallpaper->GetGroup();

	shapesGroup->InsertShape(screenWrapperRect);
	shapesGroup->InsertShape(screen);
	shapesGroup->InsertShape(powerButton);
	shapesGroup->InsertShape(taskManager);
	shapesGroup->InsertShape(startBtn);
	shapesGroup->InsertShape(wallpaper);

	auto& slideShapes = slide.GetShapes();
	for (size_t i = slideShapes.GetShapesCount(); i > 0; --i)
	{
		slideShapes.RemoveShapeAtIndex(i - 1);
	}

	slideShapes = slide.GetShapes();
	slideShapes.InsertShape(shapesGroup);

	auto shapeOutOfGroup = std::make_shared<shape::Rectangle>(RectD{ 1000, 600, 100, 100 }, CreateStyle(0xFF0000FF), CreateStyle(0xFF0000FF));
	slideShapes.InsertShape(shapeOutOfGroup);
}

void SetFillColorToShapesInSlide(ISlide& slide)
{
	auto& shapes = slide.GetShapes();

	for (size_t i = 0, total = shapes.GetShapesCount(); i < total; ++i)
	{
		auto& shape = shapes.GetShapeAtIndex(i);
		shape->GetFillStyle().SetColor(0xFF0000FF);
	}
}

void SetSizeToShapesInSlide(ISlide& slide)
{
	auto& shapes = slide.GetShapes();

	auto& shape = shapes.GetShapeAtIndex(0);
	shape->SetFrame(drawable::common::RectD(20, 20, 1000, 500));
}

} // namespace drawable::slide::demo
