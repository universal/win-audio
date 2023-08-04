{
  "targets": [
    {
      "target_name": "audio",
      "defines": [
        "NAPI_VERSION=<(napi_build_version)",
      ],
      'conditions': [
        ['OS=="win"', {
          "sources": ["audio-napi.cc"],
          "cflags" : [ "-lole32", "-loleaut32"]
        }],
        ['OS=="linux"', {
          "sources": ["audio-napi_dummy.cc"]
        }],
        ['OS=="mac"', {
          "sources": ["audio-napi_dummy.cc"]
        }],
      ]
    }
  ]
}
