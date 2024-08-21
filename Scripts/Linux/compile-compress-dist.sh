#!/bin/sh
cd ../../
make config=dist
echo 
echo compressing build 
echo
tar -czvf JoEngine_Linux.tar.gz bin/Sandbox/Sandbox bin/Engine/libEngine.a Assets