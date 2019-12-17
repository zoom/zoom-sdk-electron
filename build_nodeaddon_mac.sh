
cd `dirname $0`
if [ -d "./demo/node_modules" ];then
cd ./demo
npm run-script postinstall-mac
#cp -Rf ../sdk/mac/ZoomSDK/ZoomSDK.framework/Versions/A/Headers/zoom_sdk_raw_data_helper_interface.h  ../lib/node_add_on/mac&&cp -Rf ../sdk/mac/ZoomSDK/ZoomSDK.framework/Versions/A/Headers/zoom_sdk_platform.h  ../lib/node_add_on/mac
else
cd ./demo
npm install
npm run-script postinstall-mac
fi

version=$(electron --version)
if [ $? -ne  0 ];then
echo "build fail ,electron not install"
exit
else
cd ../
sed -i "" 's/5.0.2/'${version#*v}'/g' ./demo/package.json
node-gyp rebuild --target=${version#*v}  --dist-url=https://atom.io/download/electron
fi
cp -Rf ./build/Release/zoomsdk.node  ./sdk/mac && cp -Rf ./build/Release/zoomsdk.node.dSYM  ./sdk/mac&&
cp -Rf ./build/Release/zoomsdk_render.node  ./sdk/mac && cp -Rf ./build/Release/zoomsdk_render.node.dSYM  ./sdk/mac


