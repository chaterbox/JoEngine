#pragma once
#include <memory>

#if defined(JOE_PLATFORM_LINUX) || defined(JOE_PLATFORM_WINDOWS)
	#define JOE_API
	#else
	#error "ERROR: Platform Not Linux"
#endif

#ifdef JOE_ENABLE_ASSERTS
#define JOE_ASSERT(x, ...) {if(!(x)) {JOE_ERROR("assertion Failed: {0}",__VA_ARGS__);}}
#define JOE_CORE_ASSERT(x, ...) {if(!(x)){JOE_CORE_ERROR("assertion Failed: {0}",__VA_ARGS__);}}
#else
#define JOE_ASSERT(x,...)
#define JOE_CORE_ASSERT(x,...)
#endif

#define BIT(x)(1 << x)

#define JOE_BIND_EVENT_FN(fn)std::bind(&fn,this,std::placeholders::_1)

namespace Joe{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}
