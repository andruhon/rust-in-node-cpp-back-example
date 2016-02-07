var fs = require('fs');
var path = require('path');

/**
 * linux linker want's it to have lib prefix, and
 * node-gyp for some reason does not add such prefix
 */

var libName = 'mysquare.a';
var libBuildDir = path.join('lib', 'build','Release');
var mySquareStaticLib = path.join(libBuildDir,libName);
fs.stat(mySquareStaticLib, function(err, stats){
  if (!err && stats.isFile()) {
    fs.createReadStream(mySquareStaticLib)
    .pipe(fs.createWriteStream(path.join(libBuildDir,'lib'+libName)));
  }
});
