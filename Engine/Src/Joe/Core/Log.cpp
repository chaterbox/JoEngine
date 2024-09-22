#include "Joepch.h"
#include "spdlog/common.h"
#include "spdlog/spdlog.h"
#include "Log.h"
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Joe{
  std::shared_ptr<spdlog::logger> Log::s_CoreLogger = std::make_shared<spdlog::logger>("JOE");
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger = std::make_shared<spdlog::logger>("APP");

  void Log::Init(){
    std::string engineLogPath,appLogPath;

    #ifndef JOE_DIST
      engineLogPath = "../../../Intermediate/Logs/Engine.txt";
      appLogPath = "../../../Intermediate/Logs/App.txt";
    #endif
    #ifdef JOE_DIST
      engineLogPath = "../../Intermediate/Logs/Engine.txt";
      appLogPath = "../../Intermediate/Logs/App.txt";
    #endif

    spdlog::set_pattern("%^ [%T] %n: %v%$");
    s_CoreLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    s_CoreLogger->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(engineLogPath));
    s_CoreLogger->set_level(spdlog::level::trace);
   
    s_ClientLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    s_ClientLogger->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(appLogPath));
    s_ClientLogger->set_level(spdlog::level::trace);
  }
}
