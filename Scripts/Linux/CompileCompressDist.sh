#!/bin/sh
cd ../../
echo -e "\e[1;96mCompiling DIST build\e[0m"
make config=dist
echo 
echo -e "\e[1;96mCompressing build\e[0m"
echo
tar -czvf JoEngine_Linux.tar.gz Bin/Sandbox/Sandbox Bin/Editor/Editor Bin/Engine/libEngine.a Assets Config
echo
echo -e "\e[1;96mCompression of JoEngine_Linux DONE\e[0m"
rm Bin/Sandbox/Sandbox
rmdir Bin/Sandbox
rm Bin/Editor/Editor
rmdir Bin/Editor
rm Bin/Engine/libEngine.a
rmdir Bin/Engine
echo -e "\e[1;32mScript done\e[0m"
