#pragma once

#include <memory>

template <typename T>
class IEnumerator;

template <typename T>
using IEnumeratorRawPtr = IEnumerator<T>*;

template <typename T>
using IEnumeratorPtr = std::unique_ptr<IEnumerator<T>>;

template <typename T>
using IEnumeratorSharedPtr = std::shared_ptr<IEnumerator<T>>;
