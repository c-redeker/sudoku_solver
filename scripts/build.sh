SCRIPTPATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
BUILD_DIR="$SCRIPTPATH/../_build"
if [ ! -d "$BUILD_DIR" ]; then
  mkdir $BUILD_DIR
fi
cd $SCRIPTPATH/../_build
cmake ..
make
