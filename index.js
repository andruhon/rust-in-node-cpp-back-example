os = require('os');
addon = require('./build/Release/addon');

console.log(os.EOL+"mytest:");
console.log(addon.mytest(8));
