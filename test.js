// hello.js  "gypfile": true
const Eagle = require('electron-win-app-rect');
const sourceId = 0x123;
const rect = Eagle.getWindowRect(sourceId);
console.log(rect);