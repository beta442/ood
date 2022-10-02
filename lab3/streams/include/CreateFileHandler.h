#ifndef CREATE_FILE_HANDLER_H
#define CREATE_FILE_HANDLER_H

#include <vector>

#include "FileInputStream.h"
#include "FileOutputStream.h"

IInputDataStreamPtr CreateInputFileHandler(const std::string& fileName, const std::vector<unsigned char>& deCryptKeys, bool deCompress);
IOutputDataStreamPtr CreateOutputFileHandler(const std::string& fileName, const std::vector<unsigned char>& enCryptKeys, bool compress);

#endif // !CREATE_FILE_HANDLER_H
