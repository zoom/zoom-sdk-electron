@ECHO off&setlocal enabledelayedexpansion
call npm config set npm_config_arch ia32
call npm config set npm_config_target_arch ia32
for /f "tokens=1 delims=v" %%i in ('electron -v') do set elec_ver=%%i
call node-gyp rebuild --target=%elec_ver% --arch=ia32 --dist-url=https://atom.io/download/electron --release --msvs_version=2019
exit