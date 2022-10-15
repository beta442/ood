#ifndef CANVAS_SVG_CANVAS_H_
#define CANVAS_SVG_CANVAS_H_

#include <wx/dcsvg.h>

#include "ICanvas.h"

class SVGCanvas : public ICanvas
{
public:
	SVGCanvas(const wxString& outputFileName, unsigned int width, unsigned int height);

	void DrawEllipse(const Point& center, unsigned int verticalR, unsigned int horizontalRadius) final;
	void DrawLine(const Point& from, const Point& to) final;
	void DrawRegularPolygon(const std::vector<Point>& points) final;
	void SetColor(Color color) final;

private:
	wxSVGFileDC m_svgFile;
};

#endif // !CANVAS_SVG_CANVAS_H_
