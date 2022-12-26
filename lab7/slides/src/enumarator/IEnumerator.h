#pragma once

#include <functional>

#include "IEnumerator_fwd.h"

template <typename T>
class IEnumerator
{
public:
	using TSharedPtr = std::shared_ptr<T>;
	using TSharedPtrConst = std::shared_ptr<const T>;

	//TODO: try const& ptr
	using Callback = std::function<void(const TSharedPtr&)>;
	using CallbackConst = std::function<void(const TSharedPtrConst&)>;

	virtual void EnumerateAll(const Callback&) = 0;
	virtual void EnumerateAll(const CallbackConst&) const = 0;

	virtual ~IEnumerator() = default;
};
