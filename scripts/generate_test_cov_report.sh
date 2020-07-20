./clean.sh

./build.sh

cd ../_build
ctest

lcov --capture --directory . --output-file test_coverage.info
lcov --remove test_coverage.info '/usr/*' '7/*' '*/test/*' -o test_coverage_filtered.info

genhtml test_coverage_filtered.info --output-directory CODE_COVERAGE
firefox CODE_COVERAGE/index.html
