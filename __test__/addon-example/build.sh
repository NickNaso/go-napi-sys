echo Cleaning previous build ... && \
rm -rf libgoaddon.a && \
rm -rf libgoaddon.h && \
rm -rf ./build && \
rm -rf hello.cc && \
echo Start prebuild process ... && \
echo Start building ... && \
# Remember for Node.js version less than 12 the MACOSX_DEPLOYMENT_TARGET need to 
# be set to 10.7
export MACOSX_DEPLOYMENT_TARGET=10.10 && \
go build -a -x -o libgoaddon.a -buildmode=c-archive main.go && \
cp hello.tpl hello.cc && \
npm install && \
echo Build finished. && \
echo Test ...
npm test && \
echo Test executed with success.