#ifndef COMMAND_DOCUMENT_ELEMENTS_IELEMENT_FWD_H_
#define COMMAND_DOCUMENT_ELEMENTS_IELEMENT_FWD_H_

#include <memory>

class IElement;

using IElementRawPtr = IElement*;

using IElementPtr = std::unique_ptr<IElement>;
using IElementPtrConst = std::unique_ptr<const IElement>;
using IElementSharedPtr = std::shared_ptr<IElement>;
using IElementSharedPtrConst = std::shared_ptr<const IElement>;

#endif // !COMMAND_DOCUMENT_ELEMENTS_IELEMENT_FWD_H_
