SCRIPTPATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

$SCRIPTPATH/clean.sh
$SCRIPTPATH/build.sh
$SCRIPTPATH/run_unit_tests.sh

cd $SCRIPTPATH/../_build
lcov --capture --directory . --output-file test_coverage.info
lcov --remove test_coverage.info '/usr/*' '7/*' '*/test/*' -o test_coverage_filtered.info

genhtml test_coverage_filtered.info --output-directory CODE_COVERAGE
firefox CODE_COVERAGE/index.html
