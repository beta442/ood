#ifndef COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_FWD_H
#define COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_FWD_H

#include <memory>

class IParagraph;

using IParagraphRawPtr = IParagraph*;

using IParagraphPtr = std::unique_ptr<IParagraph>;
using IParagraphPtrConst = std::unique_ptr<const IParagraph>;
using IParagraphSharedPtr = std::shared_ptr<IParagraph>;
using IParagraphSharedPtrConst = std::shared_ptr<const IParagraph>;

#endif // !COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_FWD_H
