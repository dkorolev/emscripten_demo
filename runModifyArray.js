const wasmLoader = require("./wasm/demo.js");

const run = async () => {
  const wasm = await wasmLoader();
  console.log('Wasm version:', wasm.wasmVersion());

  const arrayContents = new Int32Array([1, 2, 3, 4, 5]);

  let ptr = wasm._malloc(arrayContents.length * arrayContents.BYTES_PER_ELEMENT);

  let wasmWrapped = new Int32Array(wasm.HEAP32.buffer, ptr, arrayContents.length);
  wasmWrapped.set(arrayContents);

  console.log("Before:", wasmWrapped);

  wasm.modifyArray(wasmWrapped.byteOffset, wasmWrapped.length);

  console.log("After: ", wasmWrapped);

  wasm._free(ptr);
};

run();
