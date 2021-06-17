# RuRuTek Build

## Step 01:

Copy 3 files to local machine

1. AOSP_Images_Doc.tar.gz
2. AOSP_SDK.tar.gz
3. AOSP_Tool_chain.tar.gz

Copy a file to local machine

1. lnt.zip

Unzip lnt.zip to `{SDK_DIR}/mt5221_AN10/vendor` directory 

## Step 03:

1. Change the path in `{SDK_DIR}/vendor/lnt/executables/DTVKitPlatform/export_includes.sh` file according to your code base path

2. Change the path in `{SDK_DIR}/vendor/lnt/executables/DVBCore/export_includes.sh` file according to your code base path

3. Change the path in `{SDK_DIR}/build_mi3_stb.sh` file in line 213 (TOOLCHAIN_AAR64), 214 (TOOLCHAIN_LINARO493), 216 (TOOLCHAIN_LINARO721)

## Step 04:

1. Use export command

   ```shell
   export PATH=$PATH:/home/user/Projects/JIO_CODE_5April21/JIO_CODE/mtk-toolchain/linaro_aarch64_linux-2014.09_r20170413/linaro_aarch64_linux-2014.09_r20170413/bin/:/home/user/Projects/JIO_CODE_5April21/JIO_CODE/mtk-toolchain/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf/bin/:/home/user/Projects/JIO_CODE_5April21/JIO_CODE/mtk-toolchain/gcc-linaro-4.9.3-4.9.3_2014.11-x86_64_arm-linux-gnueabihf/linaro-4.9.3-2014.11-arm-linux-gnueabihf/bin/ 
   ```

   In `{SDK_DIR}/mt5221_AN10/` directory, do command 

   ```shell
   source build/envsetup.sh
   ```
2. In same directory, do 

   ```shell
   lunch kustardapple-userdebug
   ```
## Step 05:

Goto `{SDK_DIR}/mt221_AN10/vendor/lnt/executables/DVBCore`

Do the following commands

```shell
source android_setenv.sh
```

```shell
make all
```

```shell
mm
```

## Step 06:

In `{SDK_DIR}/mt5221_AN10/bionic/libc/include/sys/cdefs.h` file, add below 3 lines

```shell
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif
```

In `{SDK_DIR}/mt5221_AN10/bionic/libc/include/bits/ioctl.h` file, comment last 4 lines

Goto `{SDK_DIR}/mt221_AN10/vendor/lnt/executables/DTVKitPlatform`

Do the following commands

```sh
source android_setenv.sh
```

```sh
make all
```

```shell
mm
```

## Step 07:

1. In `{SDK_DIR}/mt5221_AN10/vendor/lnt/hardware/interfaces/dtvkit/1.0/default/` directory, do 

```shell
mm
```

2. In `{SDK_DIR}/mt5221_AN10/vendor/lnt/apps/inputsource/` directory, do

```shell
mm
```

## Step 08:

```shell
sudo ln -sf bash /bin/sh
```

Goto `{SDK_DIR}/mt5221_AN10/vendor/mediatek-stb/mi/misdk/extlibs/mstar/customerinfo/obj` 
```
rm -rf CusInfo*
```

Goto `{SDK_DIR}/mt5221_AN10/vendor/mediatek-stb/mi/misdk/miapp/midemo/build/obj`
```
rm -rf mi*
```

Goto `{SDK_DIR}mt5221_AN10/vendor/mediatek-stb/mi/misdk/miapp/midaemon/build/obj`
```
rm -rf mi*
```

In `{SDK_DIR}` directory, do

```
source mi3_mt5221_anq_profile_aosp.sh
```

```
./build_mi3_stb.sh --buildAll --hash={FILE_DIRECTORY}/Customer_Info.h
```

----------------------------------------
In the End, Images (MTKUpgarde.bin) will be created in, `{SDK_DIR}/images/android_10/kustardapple/`