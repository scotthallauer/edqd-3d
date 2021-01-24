# Plugin: EDQDRobot

## Compilation

The below instructions are written specifically for macOS systems. Similar, yet different, steps will be followed on Windows and Linux.

### Step 1: Create directory and move files

Start by creating a directory (named after the plugin) in CoppeliaSim's programming directory. For this plugin, let's name the directory `simExtEDQDRobot`.

On macOS, this new directory will be located at: `/Applications/coppeliaSim.app/Contents/Resources/programming/simExtEDQDRobot`.

Thereafter, move the following files into that new directory:

- `simExtEDQDRobot.cpp`
- `simExtEDQDRobot.h`
- `simExtEDQDRobot.pro`

### Step 2: Run qmake

Open a terminal window at the directory you created in step 1. You can change to this directory by running the command:

```
cd /Applications/coppeliaSim.app/Contents/Resources/programming/simExtEDQDRobot
```

Next, if you have not yet installed Qt on your machine, run the command:

```
brew install qt
```

Once Qt is installed, make sure it is in your PATH by running the following two commands:

```
PATH=/usr/local/Cellar/qt/5.15.2/bin:$PATH
export PATH
```

Finally, run qmake to generate the appropriate Makefile:

```
qmake
```

### Step 3: Run make

Now that you have generated a Makefile, you can compile the plugin by running make:

```
make
```

### Step 4: Move generated library

Once the plugin has compiled successfully, a `.dylib` file will be generated (on macOS). For this plugin, the file will be named `libsimExtEDQDRobot.dylib`.

Move (or copy) this file to CoppeliaSim's main directory (the one containing the `coppeliaSim` executable). On macOS, this should be located at: `/Applications/coppeliaSim.app/Contents/MacOS`

### Step 5: Start CoppeliaSim

If you open CoppeliaSim now, your plugin will automatically be loaded on start-up!