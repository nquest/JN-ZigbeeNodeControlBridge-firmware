#!/bin/sh
BUILD_DIR=Build/ZigbeeNodeControlBridge
ARTIFACT_DIR=Build/bin
SDK_DIR=sdk


CHIP=JN5169
GP=0
BAUD=1000000
DEBUG=LOG

make -j$(($(nproc)+1)) -C $BUILD_DIR GP_SUPPORT=$GP BAUD=$BAUD JENNIC_CHIP=$CHIP JENNIC_CHIP_FAMILY=JN516x DEBUG=$DEBUG OTA=0
make -C $BUILD_DIR clean
# for CHIP in JN5169 JN5168; do
#   for BAUD in 115200 1000000; do
#     for GP in 0 1; do
#       for DEBUG in NONE LOG; do
            
#             make -C $BUILD_DIR BAUD=0 clean
#           done done done done
