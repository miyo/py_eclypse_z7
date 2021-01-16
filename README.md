# Python Wrapper for Eclypse-Z7 Zmod app

## Example

```
$ git clone --recursive https://github.com/Digilent/Eclypse-Z7-SW.git -b zmod_adc_dac/master
$ ORIG=./Eclypse-Z7-SW ./copy.sh
$ (cd src; patch -p1 < ../src.patch)
$ mkdir build
$ cd build
$ cmake ../src
$ make
$ cp ../app/demo.py; sudo python3 demo.py
```
