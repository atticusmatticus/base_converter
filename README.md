# Base Converter Tool

A simple command-line tool written in Python to convert a single input or a list of input values into hexadecimal, decimal, and binary base values.

Can be used with single input value:
```bash
$ bs 10
#  10  ==>  0xa  10  0b1010
```

Or multiple input values:
```bash
$ bs 0b111 10 0xff
#  0b111	==>  0x7	7	 0b111
#  10	    ==>  0xa	10	 0b1010
#  0xff	    ==>  0xff	255  0b11111111
```
