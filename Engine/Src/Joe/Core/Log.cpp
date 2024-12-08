#include "Joepch.h"
#include "spdlog/common.h"
#include "spdlog/spdlog.h"
#include "Log.h"
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Joe{
  std::shared_ptr<spdlog::logger> Log::s_EngineLogger = std::make_shared<spdlog::logger>("JOENGINE");
  std::shared_ptr<spdlog::logger> Log::s_EditorLogger = std::make_shared<spdlog::logger>("JOEDITOR");
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger = std::make_shared<spdlog::logger>("CLIENT");

  void Log::Init(){
    std::string engineLogPath,editorLogPath,appLogPath;

    #ifndef JOE_DIST
      engineLogPath = "../../../Intermediate/Logs/Engine.txt";
      editorLogPath = "../../../Intermediate/Logs/Editor.txt";
      appLogPath = "../../../Intermediate/Logs/Client.txt";
    #endif
    #ifdef JOE_DIST
      engineLogPath = "../../Intermediate/Logs/Engine.txt";
      editorLogPath = "../../Intermediate/Logs/Editor.txt";
      appLogPath = "../../Intermediate/Logs/Client.txt";
    #endif

    spdlog::set_pattern("%^ [%T] %n: %v%$");
    s_EngineLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    s_EngineLogger->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(engineLogPath));
    s_EngineLogger->set_level(spdlog::level::trace);

    s_EditorLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    s_EditorLogger->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(editorLogPath));
    s_EditorLogger->set_level(spdlog::level::trace); 
   
    s_ClientLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    s_ClientLogger->sinks().push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(appLogPath));
    s_ClientLogger->set_level(spdlog::level::trace);
  }
}
