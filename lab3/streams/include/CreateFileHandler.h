#ifndef CREATE_FILE_HANDLER_HPP
#define CREATE_FILE_HANDLER_HPP

#include <vector>

#include "DecoratorHelpers.hpp"
#include "InputStreamDeCrypter.h"
#include "OutputStreamEnCrypter.h"

#include "FileInputStream.h"
#include "FileOutputStream.h"

IInputDataStreamPtr CreateInputFileHandler(const std::string& fileName, const std::vector<unsigned char>& deCryptKeys)
{
	auto handler = std::invoke([&]() {
		IInputDataStreamPtr handler = std::make_unique<FileInputStream>(fileName);

		using namespace decorator_helpers;

		for (auto& key : deCryptKeys)
		{
			handler = std::move((std::move(handler) << DecorateStream<InputStreamDeCrypter>(key)));
		}

		return handler;
	});

	return handler;
}

IOutputDataStreamPtr CreateOutputFileHandler(const std::string& fileName, const std::vector<unsigned char>& enCryptKeys)
{
	auto handler = std::invoke([&]() {
		IOutputDataStreamPtr handler = std::make_unique<FileOutputStream>(fileName);

		using namespace decorator_helpers;

		for (auto& key : enCryptKeys)
		{
			handler = std::move((std::move(handler) << DecorateStream<OutputStreamEnCrypter>(key)));
		}

		return handler;
	});

	return handler;
}

#endif // !CREATE_FILE_HANDLER_HPP
