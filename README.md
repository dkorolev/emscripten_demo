# `emscripten_demo`

A 2025 example of how to use Emscripten.

## Instructions

To build `wasm/*`, most notably `.wasm` and `.js`:

```
rm -rf wasm && cat code.cc | docker run -i $(docker build -q .) | tar xf -
```

To try it as a Node module:

```
(cd wasm; node run.js)
```

To see it in the browser:

```
(cd wasm; python3 -m http.server 8888)
```

## Details

TL;DR:

1. Emscripten and Wasm are not the same. Golang's Wasm engine, for instance, is different.
2. When using Emscripten, it's best to have it export both the `.wasm` file and the `.js` one.
3. This way it is relatively straightforward to use the code both from the browser and from `node.js`.

For (1), well, we're after performance, so even though Golang is easier, here's a C++ example.

For (2), that's why `-o` format is `.js` in the shell script that is run from within Docker.

For (3), both node.js and browser examples are provided.

## Results

![image](https://github.com/user-attachments/assets/1971b54a-d31b-4c18-b285-b35648023a72)

![image](https://github.com/user-attachments/assets/04b38fad-c7d1-4f09-8940-939b28a841ac)

