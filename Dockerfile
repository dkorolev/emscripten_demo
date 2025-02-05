FROM emscripten/emsdk
COPY ./build_emscripten.sh /
ENTRYPOINT ["/build_emscripten.sh"]
