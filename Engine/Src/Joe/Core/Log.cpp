#include "Joepch.h"
#include "spdlog/common.h"
#include "spdlog/spdlog.h"
#include "Log.h"
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Joe{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger = std::make_shared<spdlog::logger>("JOVK");
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger = std::make_shared<spdlog::logger>("APP");

	void Log::Init(){
		spdlog::set_pattern("%^ [%T] %n: %v%$");
    s_CoreLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
