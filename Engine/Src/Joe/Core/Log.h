#pragma once
#include "Joe/Core/Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Joe{
	class JOE_API Log{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetEditorLogger() { return s_EditorLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger>s_EngineLogger;
    static std::shared_ptr<spdlog::logger>s_EditorLogger;
		static std::shared_ptr<spdlog::logger>s_ClientLogger;
	};
}

#define JOE_ENGINE_TRACE(...) ::Joe::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define JOE_ENGINE_INFO(...) ::Joe::Log::GetEngineLogger()->info(__VA_ARGS__)
#define JOE_ENGINE_WARNING(...) ::Joe::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define JOE_ENGINE_ERROR(...) ::Joe::Log::GetEngineLogger()->error(__VA_ARGS__)
#define JOE_ENGINE_FATAL(...) ::Joe::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define JOE_EDITOR_TRACE(...) ::Joe::Log::GetEditorLogger()->trace(__VA_ARGS__)
#define JOE_EDITOR_INFO(...) ::Joe::Log::GetEditorLogger()->info(__VA_ARGS__)
#define JOE_EDITOR_WARNING(...) ::Joe::Log::GetEditorLogger()->warn(__VA_ARGS__)
#define JOE_EDITOR_ERROR(...) ::Joe::Log::GetEditorLogger()->error(__VA_ARGS__)
#define JOE_EDITOR_FATAL(...) ::Joe::Log::GetEditorLogger()->critical(__VA_ARGS__)

#define JOE_CLIENT_TRACE(...) ::Joe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JOE_CLIENT_INFO(...) ::Joe::Log::GetClientLogger()->info(__VA_ARGS__)
#define JOE_CLIENT_WARNING(...) ::Joe::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JOE_CLIENT_ERROR(...) ::Joe::Log::GetClientLogger()->error(__VA_ARGS__)
#define JOE_CLIENT_FATAL(...) ::Joe::Log::GetClientLogger()->critical(__VA_ARGS__)
