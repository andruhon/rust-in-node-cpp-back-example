Rust in node examples
=====================

*Work still in progress*

Experimenting with adding C++ lib back to Rust extension for NodeJS addon.

What's inside:

* C++ static library ./lib/mylib.cc
* Rust dynamic library in ./src/embed.rs (linked with mylib.cc)
* Native NodeJS C++ addon ./src/addon.cc using ./src/embed.rs library

See more general Rust in node examples here:
https://github.com/andruhon/rust-in-node-examples

Installation
------------

  > npm install
  > npm run build

Running
------

  > node index.js

Why
---

On windows it is not really possible to embed node extensions compiled with GCC back into NodeJS,
because NodeJS for Windows is compiled with MSVC and addons should be compiled and linked with MSVC as well.
So it is not possible to use custom build script which uses gcc crate for ths purpose.

TODO
----

* Tests
* More docs

Links
-----

* https://github.com/nodejs/nan/
* https://github.com/wtfil/rust-in-node
* https://github.com/fcanas/node-native-boilerplate/
* https://github.com/rustbridge/neon/
* http://www.puritys.me/docs-blog/article-286-How-to-pass-the-paramater-of-Node.js-or-io.js-into-native-C/C++-function..html
