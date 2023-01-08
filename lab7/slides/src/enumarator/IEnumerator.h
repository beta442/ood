#pragma once

#include <functional>

#include "IEnumerator_fwd.h"

template <typename T>
class IEnumerator
{
public:
	using TSharedPtr = std::shared_ptr<T>;
	using TSharedPtrConst = std::shared_ptr<const T>;

	using Callback = std::function<void(T&)>;
	using CallbackConst = std::function<void(const T&)>;

	virtual void EnumerateAll(const Callback&) = 0;
	virtual void EnumerateAll(const CallbackConst&) const = 0;

	virtual ~IEnumerator() = default;
};
