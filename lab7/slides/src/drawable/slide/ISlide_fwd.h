#pragma once

#include <memory>

namespace drawable::slide
{

class ISlide;

using ISlideRawPtr = ISlide*;
using ISlidePtr = std::unique_ptr<ISlide>;
using ISlideSharedPtr = std::shared_ptr<ISlide>;

} // namespace drawable::slide
