#!/bin/bash
cd /home/edrian/Documents/GitHub/openspadesplus/
rm -r build
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
make -j 8
mv Resources bin
cd bin
mv openspades openspadesplus
./openspadesplus
