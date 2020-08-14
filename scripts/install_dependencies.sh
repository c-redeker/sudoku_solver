echo "------------------------------------"
echo "Installing googletest"
echo "------------------------------------"

cd /tmp
git clone https://github.com/google/googletest.git
cd googletest
mkdir _build
cd _build
cmake ..
make
sudo make install
cd /tmp
rm -rf googletest

echo "------------------------------------"
echo "Installing qt5"
echo "------------------------------------"

sudo apt-get install qt5-default

