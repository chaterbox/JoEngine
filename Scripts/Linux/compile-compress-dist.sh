#!/bin/sh
cd ../../
make config=dist
echo 
echo compressing build 
echo
tar -czvf JoEngine_Linux.tar.gz Bin/Sandbox/Sandbox Bin/Engine/libEngine.a Assets
echo
echo compression of JoEngine_Linux DONE
rm Bin/Sandbox/Sandbox
rmdir Bin/Sandbox
rm Bin/Engine/libEngine.a
rmdir Bin/Engine
