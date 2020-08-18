# Sudoku Solver (in progress)
This repo contains a solver for sudokus (not finished yet).

## Dependencies
[googletest](https://github.com/google/googletest)  
[Qt5](https://doc.qt.io/qt-5/gettingstarted.html)

Installation of dependencies via scripts/install_dependencies.sh possible.

## Installation
```bash
mkdir _build
cd _build
cmake ..
make
```
Build via scripts/build.sh possible

## Usage
from build directory _build/src run
```bash
./sudoku_solver_main sudokus.txt
```

## License
[MIT](https://choosealicense.com/licenses/mit/)
