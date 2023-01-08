#pragma once

#include <memory>

namespace drawable::shape
{

class IStyle;

using IStyleRawPtr = IStyle*;

using IStylePtr = std::unique_ptr<IStyle>;

using IStyleSharedPtrConst = std::shared_ptr<const IStyle>;
using IStyleSharedPtr = std::shared_ptr<IStyle>;

} // namespace drawable::shape
