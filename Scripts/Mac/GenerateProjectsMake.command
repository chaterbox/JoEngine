#!/bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"
cd ../../
./Vendor/Bin/premake5/MacOS/premake5 gmake2