
cd `dirname $0`
if [ -d "./demo/node_modules" ];then
cd ./demo
npm run-script postinstall-mac
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



