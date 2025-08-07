#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#elif HZ_PLATFORM_MACOS // defined(__APPLE__)  // macOS 平台（__APPLE__ 是 clang/gcc 的内置宏）
    // macOS 动态库（.dylib）使用 visibility 属性控制符号导出
    #ifdef HZ_BUILD_DLL
        // 编译动态库时，显式导出符号（visibility("default")）
        #define HAZEL_API __attribute__((visibility("default")))
    #else
        // 使用动态库时，不需要特殊导入属性（macOS 自动查找符号）
        #define HAZEL_API
    #endif
#else
	#error Hazel only supports Windows!
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)