#!/bin/sh
cd "$(cd "$(dirname "$0")" > /dev/null && pwd)"
cd ../../
make config=dist
echo 
echo compressing build 
echo
tar -czvf JoEngine_Mac.tar.gz bin/Sandbox/Sandbox bin/Engine/libEngine.a Assets
echo
echo compression of JoEngine_Mac DONE
rm bin/Sandbox/Sandbox
rmdir bin/Sandbox
rm bin/Engine/libEngine.a
rmdir bin/Engine
