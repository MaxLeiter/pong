# Pong for KnightOS

This is an example project to demonstrate how KnightOS programs can be written
in C. It's a work in progress.

![](http://a.pomf.se/jngdza.gif)

## Points of Interest

* Demonstrates the maturing state of C support on KnightOS
* Uses kimg+scwrap to store images as PNG files and link them in automatically
* Read the Makefile - it's pretty easy to do this yourself

## Compiling

To compile, install the KnightOS SDK and run:

    knightos init
    make

To test it out:

    make run

To make a package:

    make package
