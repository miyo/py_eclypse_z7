# Python Wrapper for Eclypse-Z7 Zmod app

## Example

```
$ git clone --recursive https://github.com/Digilent/Eclypse-Z7-SW.git -b zmod_adc_dac/master
$ ORIG=./Eclypse-Z7-SW ./copy.sh
$ (cd src; patch -p1 < ../src.patch)
$ mkdir build; cd build
$ cmake ../src
$ make
$ cp ../app/zmoddac1411.py; sudo python3 zmoddac1411.py
$ cp ../app/zmodadc1410.py; sudo python3 zmodadc1410.py
  (press Ctrl-C to stop)
```

## Requirements

### Pybind11

```
$ git clone https://github.com/pybind/pybind11
$ cd pybind11
$ mkdir build; cd build
$ cd build
$ cmake ..
$ make
$ sudo make install
```
