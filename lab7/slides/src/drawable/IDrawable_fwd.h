#pragma once

#include <memory>

namespace drawable
{

class IDrawable;

using IDrawableRawPtr = IDrawable*;
using IDrawablePtr = std::unique_ptr<IDrawable>;
using IDrawableSharedPtr = std::shared_ptr<IDrawable>;

} // namespace drawable
