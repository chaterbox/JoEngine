#pragma once
#include "Joe/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
//TODO: expand logger class
namespace Joe{
	class JOE_API Log{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger>s_CoreLogger;
		static std::shared_ptr<spdlog::logger>s_ClientLogger;
	};
}

#define JOE_CORE_TRACE(...) ::Joe::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JOE_CORE_INFO(...) ::Joe::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JOE_CORE_WARN(...) ::Joe::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JOE_CORE_ERROR(...) ::Joe::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JOE_CORE_FATAL(...) ::Joe::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define JOE_TRACE(...) ::Joe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JOE_INFO(...) ::Joe::Log::GetClientLogger()->info(__VA_ARGS__)
#define JOE_WARN(...) ::Joe::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JOE_ERROR(...) ::Joe::Log::GetClientLogger()->error(__VA_ARGS__)
#define JOE_FATAL(...) ::Joe::Log::GetClientLogger()->critical(__VA_ARGS__)
