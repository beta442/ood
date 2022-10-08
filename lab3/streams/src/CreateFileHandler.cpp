#include <algorithm>

#include "../include/CreateFileHandler.h"

#include "../include/DecoratorHelpers.hpp"

#include "../include/InputStreamDeCrypter.h"
#include "../include/InputStreamRLEDeCompressor.h"

#include "../include/OutputStreamRLECompressor.h"
#include "../include/OutputStreamEnCrypter.h"

IInputDataStreamPtr CreateInputFileHandler(const std::string& fileName, const std::vector<unsigned char>& deCryptKeys, bool deCompress)
{
	auto handler = std::invoke([&]() {
		IInputDataStreamPtr handler = std::make_unique<FileInputStream>(fileName);

		using namespace decorator_helpers;

		if (deCompress)
		{
			handler = std::move((std::move(handler) << DecorateStream<InputStreamRLEDeCompressor>()));
		}

		for (auto& key : deCryptKeys)
		{
			handler = std::move((std::move(handler) << DecorateStream<InputStreamDeCrypter>(key)));
		}

		return handler;
	});

	return handler;
}

IOutputDataStreamPtr CreateOutputFileHandler(const std::string& fileName, const std::vector<unsigned char>& enCryptKeys, bool compress)
{
	auto handler = std::invoke([&]() {
		IOutputDataStreamPtr handler = std::make_unique<FileOutputStream>(fileName);

		using namespace decorator_helpers;

		for (auto it = enCryptKeys.crbegin(), endIt = enCryptKeys.crend(); it != endIt; ++it)
		{
			handler = std::move((std::move(handler) << DecorateStream<OutputStreamEnCrypter>(*it)));
		}

		if (compress)
		{
			handler = std::move((std::move(handler) << DecorateStream<OutputStreamRLECompressor>()));
		}

		return handler;
	});

	return handler;
}
