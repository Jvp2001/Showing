// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"




// template< class Derived, class Base >
// concept derived_from =
//   std::is_base_of_v<Base, Derived> &&
//   std::is_convertible_v<const volatile Derived*, const volatile Base*>;
// template<typename T>
// concept TIsUserWidget = derived_from<T,UUserWidget> and TNot<TIsPointer<T>>::Value;