#!/bin/sh
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"
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
