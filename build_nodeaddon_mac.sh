cd $(dirname $0)

if [ -d "../../node_modules" ]; then
  cd ../../
  yarn run postinstall-mac
else
  cd ../../
  yarn install
  yarn run postinstall-mac
fi

version=$(electron --version)

if [ $? -ne 0 ]; then
  echo "build fail ,electron not install"
  exit
else
  cd ./node_modules/zoom-sdk-electron
  sed -i "" 's/8.2.4/'${version#*v}'/g' ../../package.json
  node-gyp rebuild --target=${version#*v} --dist-url=https://atom.io/download/electron
fi

cp -Rf ./build/Release/zoomsdk.node ./sdk/mac && cp -Rf ./build/Release/zoomsdk_render.node ./sdk/mac
