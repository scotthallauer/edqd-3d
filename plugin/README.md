# Plugin: BubbleRob

## Compilation

### Step 1: .cpp → .o
From: [O'Reilly](https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s03.html#cplusplusckbk-CHP-1-TABLE-8)

```
g++ -c -o simExtBubbleRob.o ./plugin/simExtBubbleRob.cpp -I/Applications/coppeliaSim.app/Contents/Resources/programming/include
```

### Step 2: .o → .dylib
From: [O'Reilly](https://www.oreilly.com/library/view/c-cookbook/0596007612/ch01s05.html)

```
g++ -dynamiclib -fPIC -o libsimExtBubbleRob.dylib simExtBubbleRob.o
```