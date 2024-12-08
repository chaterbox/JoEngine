# JoEngine
## OS:
### Supported
- Linux
- Windows
### Planned
- Mac OS

## Renderer Backends
### Supported
- SDL
### Planned/WIP
- Vulkan
### Maybe
- Metal
- DX12

## Libs used
### Window, Events, and Input
- SDL3

### Vulkan
- Vulkan SDK
- VMA
- VkBootstrap
- GLM

### Logging
- Spdlog

### INI
- mINI

### Ui
- ImGui

## Setup
### Linux
Run GenerateProjects.sh in the Scripts/linux folder

#### SteamDeck and SteamOS
##### Requires 3.6
Run Setup.sh in the Scripts/Linux/SteamDeck folder

## Optional
### NeoVim:
#### Gen compile_commands.json
Run GenCompileCommandsJson.sh in the Scripts/linux folder.

#### Requires Bear
if not in your distros repo link is below  
<https://github.com/rizsotto/Bear> 

### Windows
Run GenerateProjects.sh in the Scripts/WIN32 folder

## Branches
### Release 
Stable, runs with little to no major bugs.

## Future Plans:
 - create editor
 - finish vulkan renderer
### Platform Specific:
