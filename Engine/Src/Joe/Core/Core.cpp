#include <Joepch.h>
#include <Joe/Core/Core.h>

namespace Joe{
  std::string Core::GetFileExtension(const std::string path){
      std::string extensionName = path;
      size_t extensionindex = extensionName.find_last_of(".") + 1;

      extensionName.erase(0,extensionindex);
    
      return extensionName;
  }

  void EngineConfig::Init(){
    #ifdef JOE_DIST
      IniPath = "../../Config/JoEngineConfig.ini";
      ConfigFoldPath = "../../Config";
    #else
      IniPath = "../../../Config/JoEngineConfig.ini";
      ConfigFoldPath = "../../../Config";
    #endif

    if(!std::filesystem::exists(ConfigFoldPath)){
      std::filesystem::create_directory(ConfigFoldPath);
    }

    if(!std::filesystem::exists(IniPath)){
      JOE_ENGINE_INFO("EngineConfig::NON-EXIST\n");
    }
  }
  void EditorConfig::Init(){
    #ifdef JOE_DIST
      IniPath = "../../Config/JoEditorConfig.ini";
      ConfigFoldPath = "../../Config";
    #else
      IniPath = "../../../Config/JoEditorConfig.ini";
      ConfigFoldPath = "../../../Config";
    #endif

    if(!std::filesystem::exists(ConfigFoldPath)){
      std::filesystem::create_directory(ConfigFoldPath);
    }

    if(!std::filesystem::exists(IniPath)){
      JOE_EDITOR_INFO("EditorConfig::NON-EXIST\n");
    }
  }
}
