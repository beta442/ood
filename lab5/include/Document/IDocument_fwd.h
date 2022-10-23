#ifndef COMMAND_DOCUMENT_IDOCUMENT_FWD_H_
#define COMMAND_DOCUMENT_IDOCUMENT_FWD_H_

#include <memory>

class IDocument;

using IDocumentRawPtr = IDocument*;

using IDocumentPtr = std::unique_ptr<IDocument>;
using IDocumentSharedPtr = std::shared_ptr<IDocument>;
using IDocumentWeakPtr = std::weak_ptr<IDocument>;

#endif // !COMMAND_DOCUMENT_IDOCUMENT_FWD_H_
