#!/bin/bash
cd "$(cd "$(dirname "$0")" > /dev/null && pwd)"
cd ../../
./Vendor/Bin/premake5/MacOS/premake5 xcode4