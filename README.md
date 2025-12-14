# Scalebar

Get a real scale visualisation of digital creations.

## Building

> These commands are created for a fresh install of mingw on windows. It shouldn't be difficult to adapt these for your own configuration and operating system.

In order to generate the files for building, you need to create the folder "target" in the project root and enter it.

```batch
mkdir target
cd target
```

Then you need to run CMake in order to generate the files. You need to generate the files for Mingw make, not nmake. Although, nmake might also work I have not tried it.

```batch
cmake -G "MinGW Makefiles" ..
```

Then all the make files are generated and you can see all the build targets using `make help`. However on a fresh install of mingw on windows, make might not be a valid command. So you will have to use `mingw32-make` instead.

Here are some of the important commands:

- Build and run the entire project:
```batch
mingw32-make
./scalebar
```

- Build and run all the tests:
```batch
mingw32-make test
```

- View all build targets:
```batch
mingw32-make help
```
