#!/bin/sh
cd ../../
make config=dist
echo 
echo compressing build 
echo
tar -czvf JoEngine_Linux.tar.gz bin/Sandbox/Sandbox bin/Engine/libEngine.a Assets
echo
echo compression of JoEngine_Linux DONE
rm bin/Sandbox/Sandbox
rmdir bin/Sandbox
rm bin/Engine/libEngine.a
rmdir bin/Engine
